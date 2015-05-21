/* -*-	Mode:C++; c-basic-offset:8; tab-width:8; indent-tabs-mode:t -*- */
/*
 * Super-rational TCP congestion control.
 * Keith Winstein, Hari Balakrishnan (MIT CSAIL & Wireless@MIT).
 * January 2013.
 */

#include <algorithm>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <string>
#include "exception.hh"
#include "tcp-gusteau.h"

GusteauTcpAgent::GusteauTcpAgent()
	: _memory(),
	  _intersend_time( 0.0 ),
          _max_receive_ratio( 1.0 ),
	  transmission_map_(),
	  retx_pending_(),
	  largest_oo_ts_( -1.0 ),
	  largest_oo_ack_( -1 ),
	  transmitted_pkts_( 0 ),
	  rational_rtx_timer_( this ),
	  _last_send_time( 0 ),
	  count_bytes_acked_( 0 )
{
	try {
		bind_bool("count_bytes_acked_", &count_bytes_acked_);
        } catch (const Exception & e) {
		e.perror();
		exit(1);
        }
}

GusteauTcpAgent::~GusteauTcpAgent()
{
}

void
GusteauTcpAgent::delay_bind_init_all()
{
	delay_bind_init_one("_intersend_time");
	TcpAgent::delay_bind_init_all();
        reset();
}

int
GusteauTcpAgent::delay_bind_dispatch(const char *varName, const char *localName, 
				   TclObject *tracer)
{
        if (delay_bind(varName, localName, "tracewhisk_", &tracewhisk_, tracer)) return TCL_OK;
	if (delay_bind(varName, localName, "_intersend_time", &_intersend_time, tracer)) return TCL_OK;
        return TcpAgent::delay_bind_dispatch(varName, localName, tracer);
}


static class GusteauTcpClass : public TclClass {
public:
	GusteauTcpClass() : TclClass("Agent/TCP/Gusteau") {}
	TclObject* create(int, const char*const*) {
		return (new GusteauTcpAgent());
	}
} class_rational_tcp;

/*
 * initial_window() is called in a few different places in tcp.cc.
 * This function overrides the default. 
 */
double
GusteauTcpAgent::initial_window()
{
	_memory.reset();
        cwnd_ = 15;
        _intersend_time = .5 * .001;
	//update_cwnd_and_pacing();
	return cwnd_;
}

void 
GusteauTcpAgent::send_helper(int maxburst) 
{
	/* 
	 * If there is still data to be sent and there is space in the
	 * window, set a timer to schedule the next burst.
	 */
	assert( burstsnd_timer_.status() != TIMER_PENDING );

	/* schedule wakeup */
	auto num_lost_or_received = (largest_oo_ts_ != -1.0) ? transmission_map_.at( largest_oo_ts_ ).second : 0.0;
	if (transmission_map_.size() < num_lost_or_received + window()) {
		if ( ( not retx_pending_.empty() ) or ( t_seqno_ < curseq_ ) ) {
			const double now( Scheduler::instance().clock() );
			const double time_since_last_send( now - _last_send_time );
			const double wait_time( _intersend_time - time_since_last_send );
			assert( wait_time > 0 );
			burstsnd_timer_.resched( wait_time );
		}
	}
}

void GusteauTcpAgent::recv(Packet* pkt, Handler *h) {
	hdr_tcp *tcph = hdr_tcp::access(pkt);
	hdr_cmn *cmn_hdr = hdr_cmn::access(pkt);
	
	// Check if ACK is valid.  Suggestion by Mark Allman. 
	assert (cmn_hdr->ptype() == PT_ACK);
	assert (tcph->seqno() >= last_ack_);

	// Update last_ack_ if receiver received next in-order packet
	if ( tcph->seqno() > last_ack_ ) {
		/* RFC 6298 5.3: Acknowledges new data */
		rational_rtx_timer_.resched( rational_rtx_timer_.rto() );
		last_ack_ = tcph->seqno();
	}

	// Calculate srtt and friends
	rational_rtx_timer_.update_rtt_timer( Scheduler::instance().clock() - tcph->ts_echo() );

	/* Received ts has to be greater than the largest seen so far */
	/* Assumption: No reordering */
	assert( tcph->ts_echo() > largest_oo_ts_ );
	largest_oo_ts_ = tcph->ts_echo();

	/* Look at incoming ts */
	int oo_acked_seqno = transmission_map_.at( tcph->ts_echo() ).first;

	/* Compare it to largest_oo_ack_ to fast retransmit missing packets */
	if ( oo_acked_seqno > largest_oo_ack_ ) {
		for (int i = largest_oo_ack_ + 1; i < oo_acked_seqno; i++) {
			retx_pending_.push( i );
		}
	}
	largest_oo_ack_ = max( largest_oo_ack_, oo_acked_seqno );

	/* Update congestion state regardless */
	update_congestion_state(pkt);

	/* RFC 6298: 5.2 No more outstanding packets */
	if( t_seqno_ == last_ack_ or
            ( t_seqno_ - 1 == last_ack_ and t_seqno_ == curseq_ ) or /* ontype bytes overshoot */
            ( t_seqno_ - 1 == last_ack_ and curseq_ == maxseq_ ) ) { /* ontype time overshoot */
		rational_rtx_timer_.force_cancel();
	}

	if (app_) app_->recv_ack(pkt); /* ANIRUDH: Callback to app */
	Packet::free(pkt);
}

void GusteauTcpAgent::send_much(int force, int reason, int maxburst)
{
	//assert (burstsnd_timer_.status() != TIMER_PENDING);
	if (burstsnd_timer_.status() == TIMER_PENDING ) {
		return;
	}

	auto num_lost_or_received = (largest_oo_ts_ != -1.0) ? transmission_map_.at( largest_oo_ts_ ).second : 0.0;
	if (transmission_map_.size() < num_lost_or_received + window()) {
		if ( not retx_pending_.empty() ) {
			output(retx_pending_.front(), TCP_REASON_DUPACK );
			retx_pending_.pop();
		}
		else if ( t_seqno_ < curseq_ ) {
			output(t_seqno_, reason);
			t_seqno_ ++ ;
		}
	}
	send_helper(maxburst);
}

void GusteauTcpAgent::output( int seqno, int reason )
{
	/* Cannot have two transmissions at the same time */
	assert( transmission_map_.find( Scheduler::instance().clock() ) == transmission_map_.end() );
	transmission_map_[ Scheduler::instance().clock() ] = make_pair( seqno, ++transmitted_pkts_ );
	assert( transmission_map_.size() == transmitted_pkts_ );
	_last_send_time = Scheduler::instance().clock();
	TcpAgent::output( seqno, reason );
	if ( rational_rtx_timer_.status() != TIMER_PENDING ) {
		/* RFC 6298: 5.1 : Set timer if it isn't already running */
		rational_rtx_timer_.resched( rational_rtx_timer_.rto() );
	}
}

/*
 * Update congestion state appropriately.
 */
void
GusteauTcpAgent::update_congestion_state(Packet *pkt) 
{
	double now = Scheduler::instance().clock();
	hdr_tcp *tcph = hdr_tcp::access(pkt);

	double timestep = 1000.0;

	unsigned int src = hdr_ip::access(pkt)->saddr();
	unsigned int flow_id = hdr_ip::access(pkt)->flowid();
	update_memory( RemyPacket( src, flow_id, timestep * tcph->ts_echo(), timestep * now ), fid_ );

	update_cwnd_and_pacing();

	/* TODO: Figure out what this is: if the connection is done, call finish() */
	assert( highest_ack_ < curseq_-1);
}

void 
GusteauTcpAgent::update_memory( const RemyPacket & packet, const unsigned int flow_id )
{
	std::vector< RemyPacket > packets( 1, packet );
	_memory.packets_received( packets, flow_id );
}

void
GusteauTcpAgent::update_cwnd_and_pacing( void )
{
	double old_intersend_time = _intersend_time;
	double timestep_inverse = .001;
        unsigned int new_cwnd = cwnd_;

        /* RTT ratio threshold */
        if( _memory.field( 2 ) <= 1.01  and _memory.field( 2 ) >= 1.0 ) {
          /* Gradually allow more sending */
          new_cwnd = cwnd_ + 1;
          
          /* Queue is small-- send faster! 
             Increase rate more cautiously as we approach smaller sewma values
             so as not to flood the queue. */
	  if( _memory.field( 1 ) > 1 ) {
		  _intersend_time = _memory.field( 1 ) / ( _memory.field( 1 )/10 + 1 );
	  } else {
		  _intersend_time = _memory.field( 1 ) / ( _memory.field( 1 ) + 1 );
	  }
        } else if( _memory.field( 2 ) > 1.01 ) {
          /* Queue is too large; back off */
		_intersend_time = _memory.field( 1 ) * 1.1;
        }

	cwnd_ = new_cwnd;

	_intersend_time = timestep_inverse * _intersend_time;
	double _print_intersend = _intersend_time;

	const double now( Scheduler::instance().clock() );
	const double time_since_last_send( now - _last_send_time );
	const double wait_time( _intersend_time - time_since_last_send );

	if (tracewhisk_) {
		fprintf( stderr, "%g: %s newcwnd: %u newintersend: %f\n", now, _memory.str().c_str(), new_cwnd, _print_intersend );
	}

	burstsnd_timer_.resched( wait_time <= 0 ? 0 : wait_time );
}

void
GusteauTcpAgent::timeout_nonrtx( int tno )
{
	assert ( tno != TCP_TIMER_DELSND );
	if ( tno == TCP_TIMER_BURSTSND ) {
		send_much( 1, TCP_REASON_TIMEOUT, maxburst_ );
	}
}

void 
GusteauTcpAgent::traceVar(TracedVar *v)
{
	#define TCP_WRK_SIZE 512
	if (!channel_)
		return;

	double curtime;
	Scheduler& s = Scheduler::instance();
	char wrk[TCP_WRK_SIZE];

	curtime = &s ? s.clock() : 0;
	
	if (v == &_intersend_time) {
		snprintf(wrk, TCP_WRK_SIZE,
			 "%-8.5f %-2d %-2d %-2d %-2d %s %-6.6f\n",
			 curtime, addr(), port(), daddr(), dport(),
			 v->name(), double(*((TracedDouble*) v))); 
		(void)Tcl_Write(channel_, wrk, -1);
	} else {
		TcpAgent::traceVar(v);
	}

}
void GusteauTcpAgent::reset_to_iw(void)
{
	cwnd_ = 0;
	_last_send_time = 0;
	_intersend_time = 0;
	initial_window();
	fid_++;
}

int GusteauTcpAgent::command(int argc, const char*const* argv)
{
	if (argc == 2) {
		if (strcmp(argv[1], "reset_to_iw") == 0) {
			/* Clear all state except for the sequence numbers */
			reset_to_iw();
			return (TCL_OK);
		}
	}
	return (TcpAgent::command(argc, argv));
}
