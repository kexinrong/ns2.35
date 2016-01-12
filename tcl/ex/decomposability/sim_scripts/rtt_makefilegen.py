import os
import numpy
import math

# constants
iteration_count = 10
resultfolder = "resultslogsimple"
topofolder = "topologarithmic"

# protocols
rationalstr="-tcp TCP/Rational -sink TCPSink/Sack1 -gw DropTail"

# traffic pattern
traffic_workload="-ontype time -onrand Exponential -onavg 1.0 -offrand Exponential"

# Clean up the results and topologies folder
os.system("rm -rf " + resultfolder)
os.system("mkdir " + resultfolder)
os.system("rm -rf " + topofolder)
os.system("mkdir " + topofolder)

# define a logrange function
def logrange(below, above, num_points):
  start = math.log10(below)
  stop  = math.log10(above)
  return list(numpy.around(numpy.logspace(start, stop, num_points), 5));

  # Make linkspeed topologies
linkspeed_range = logrange(1.0, 1000, 1000);
for linkspeed in linkspeed_range:
  fh=open(topofolder + "/linkspeed"+ str(linkspeed) + ".txt", "w");
  fh.write("0 1 " + str(linkspeed) + " 74\n");
  fh.write("1 2 1000000000 1\n");
  fh.write("1 3 1000000000 1\n");
  fh.close();

# Make common sd file
fh=open(topofolder + "/sd.txt", 'w');
fh.write("0 2\n");
fh.write("0 3\n");
fh.close();

# Synthesize command line
def synthesize( whiskertree, topology, tcp_agents, traffic_cfg, off_time, sim_time, run, tag ):
  global topofolder
  global resultfolder
  cmdline="WHISKERS=" + whiskertree + " ./decompose.tcl " + topology + " " + topofolder + "/sd.txt " + tcp_agents + " " +  traffic_cfg + " -offavg "+ str( off_time ) + " -simtime " + str( sim_time ) + " -run " + str( run )
  fileio=" >" + resultfolder + "/" + tag + "run" + str( run ) + ".out " + "2>" + resultfolder + "/" + tag + "run" + str( run ) +  ".err"
  cmdline += fileio
  target = resultfolder + "/" + tag + "run" + str( run ) + ".out"
  synthesize.targets += " " + target
  synthesize.cmdlines += "\n" + target + ":\n\t" + cmdline
synthesize.targets=""
synthesize.cmdlines=""

# Auto-agility
for linkspeed in linkspeed_range:
  linkspeed_topology = topofolder + "/linkspeed" + str(linkspeed) + ".txt"
  for run in range(1, iteration_count + 1):
    synthesize( os.getcwd() + "/remy-rtt.N",     linkspeed_topology, rationalstr,      traffic_workload, 1.0, 100, run, "remyrtt-link"+str(linkspeed));
    
print "all: " + synthesize.targets, synthesize.cmdlines

