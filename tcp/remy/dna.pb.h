// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dna.proto

#ifndef PROTOBUF_dna_2eproto__INCLUDED
#define PROTOBUF_dna_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace RemyBuffers {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_dna_2eproto();
void protobuf_AssignDesc_dna_2eproto();
void protobuf_ShutdownFile_dna_2eproto();

class WhiskerTree;
class MemoryRange;
class Memory;
class Whisker;

// ===================================================================

class WhiskerTree : public ::google::protobuf::Message {
 public:
  WhiskerTree();
  virtual ~WhiskerTree();

  WhiskerTree(const WhiskerTree& from);

  inline WhiskerTree& operator=(const WhiskerTree& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const WhiskerTree& default_instance();

  void Swap(WhiskerTree* other);

  // implements Message ----------------------------------------------

  WhiskerTree* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const WhiskerTree& from);
  void MergeFrom(const WhiskerTree& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .RemyBuffers.MemoryRange domain = 1;
  inline bool has_domain() const;
  inline void clear_domain();
  static const int kDomainFieldNumber = 1;
  inline const ::RemyBuffers::MemoryRange& domain() const;
  inline ::RemyBuffers::MemoryRange* mutable_domain();
  inline ::RemyBuffers::MemoryRange* release_domain();
  inline void set_allocated_domain(::RemyBuffers::MemoryRange* domain);

  // repeated .RemyBuffers.WhiskerTree children = 2;
  inline int children_size() const;
  inline void clear_children();
  static const int kChildrenFieldNumber = 2;
  inline const ::RemyBuffers::WhiskerTree& children(int index) const;
  inline ::RemyBuffers::WhiskerTree* mutable_children(int index);
  inline ::RemyBuffers::WhiskerTree* add_children();
  inline const ::google::protobuf::RepeatedPtrField< ::RemyBuffers::WhiskerTree >&
      children() const;
  inline ::google::protobuf::RepeatedPtrField< ::RemyBuffers::WhiskerTree >*
      mutable_children();

  // optional .RemyBuffers.Whisker leaf = 3;
  inline bool has_leaf() const;
  inline void clear_leaf();
  static const int kLeafFieldNumber = 3;
  inline const ::RemyBuffers::Whisker& leaf() const;
  inline ::RemyBuffers::Whisker* mutable_leaf();
  inline ::RemyBuffers::Whisker* release_leaf();
  inline void set_allocated_leaf(::RemyBuffers::Whisker* leaf);

  // @@protoc_insertion_point(class_scope:RemyBuffers.WhiskerTree)
 private:
  inline void set_has_domain();
  inline void clear_has_domain();
  inline void set_has_leaf();
  inline void clear_has_leaf();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::RemyBuffers::MemoryRange* domain_;
  ::google::protobuf::RepeatedPtrField< ::RemyBuffers::WhiskerTree > children_;
  ::RemyBuffers::Whisker* leaf_;
  friend void  protobuf_AddDesc_dna_2eproto();
  friend void protobuf_AssignDesc_dna_2eproto();
  friend void protobuf_ShutdownFile_dna_2eproto();

  void InitAsDefaultInstance();
  static WhiskerTree* default_instance_;
};
// -------------------------------------------------------------------

class MemoryRange : public ::google::protobuf::Message {
 public:
  MemoryRange();
  virtual ~MemoryRange();

  MemoryRange(const MemoryRange& from);

  inline MemoryRange& operator=(const MemoryRange& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MemoryRange& default_instance();

  void Swap(MemoryRange* other);

  // implements Message ----------------------------------------------

  MemoryRange* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MemoryRange& from);
  void MergeFrom(const MemoryRange& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .RemyBuffers.Memory lower = 11;
  inline bool has_lower() const;
  inline void clear_lower();
  static const int kLowerFieldNumber = 11;
  inline const ::RemyBuffers::Memory& lower() const;
  inline ::RemyBuffers::Memory* mutable_lower();
  inline ::RemyBuffers::Memory* release_lower();
  inline void set_allocated_lower(::RemyBuffers::Memory* lower);

  // optional .RemyBuffers.Memory upper = 12;
  inline bool has_upper() const;
  inline void clear_upper();
  static const int kUpperFieldNumber = 12;
  inline const ::RemyBuffers::Memory& upper() const;
  inline ::RemyBuffers::Memory* mutable_upper();
  inline ::RemyBuffers::Memory* release_upper();
  inline void set_allocated_upper(::RemyBuffers::Memory* upper);

  // @@protoc_insertion_point(class_scope:RemyBuffers.MemoryRange)
 private:
  inline void set_has_lower();
  inline void clear_has_lower();
  inline void set_has_upper();
  inline void clear_has_upper();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::RemyBuffers::Memory* lower_;
  ::RemyBuffers::Memory* upper_;
  friend void  protobuf_AddDesc_dna_2eproto();
  friend void protobuf_AssignDesc_dna_2eproto();
  friend void protobuf_ShutdownFile_dna_2eproto();

  void InitAsDefaultInstance();
  static MemoryRange* default_instance_;
};
// -------------------------------------------------------------------

class Memory : public ::google::protobuf::Message {
 public:
  Memory();
  virtual ~Memory();

  Memory(const Memory& from);

  inline Memory& operator=(const Memory& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Memory& default_instance();

  void Swap(Memory* other);

  // implements Message ----------------------------------------------

  Memory* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Memory& from);
  void MergeFrom(const Memory& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double rec_rec_ewma = 22;
  inline bool has_rec_rec_ewma() const;
  inline void clear_rec_rec_ewma();
  static const int kRecRecEwmaFieldNumber = 22;
  inline double rec_rec_ewma() const;
  inline void set_rec_rec_ewma(double value);

  // @@protoc_insertion_point(class_scope:RemyBuffers.Memory)
 private:
  inline void set_has_rec_rec_ewma();
  inline void clear_has_rec_rec_ewma();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  double rec_rec_ewma_;
  friend void  protobuf_AddDesc_dna_2eproto();
  friend void protobuf_AssignDesc_dna_2eproto();
  friend void protobuf_ShutdownFile_dna_2eproto();

  void InitAsDefaultInstance();
  static Memory* default_instance_;
};
// -------------------------------------------------------------------

class Whisker : public ::google::protobuf::Message {
 public:
  Whisker();
  virtual ~Whisker();

  Whisker(const Whisker& from);

  inline Whisker& operator=(const Whisker& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Whisker& default_instance();

  void Swap(Whisker* other);

  // implements Message ----------------------------------------------

  Whisker* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Whisker& from);
  void MergeFrom(const Whisker& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 window_increment = 31;
  inline bool has_window_increment() const;
  inline void clear_window_increment();
  static const int kWindowIncrementFieldNumber = 31;
  inline ::google::protobuf::int32 window_increment() const;
  inline void set_window_increment(::google::protobuf::int32 value);

  // optional double window_multiple = 32;
  inline bool has_window_multiple() const;
  inline void clear_window_multiple();
  static const int kWindowMultipleFieldNumber = 32;
  inline double window_multiple() const;
  inline void set_window_multiple(double value);

  // optional double intersend = 33;
  inline bool has_intersend() const;
  inline void clear_intersend();
  static const int kIntersendFieldNumber = 33;
  inline double intersend() const;
  inline void set_intersend(double value);

  // optional .RemyBuffers.MemoryRange domain = 34;
  inline bool has_domain() const;
  inline void clear_domain();
  static const int kDomainFieldNumber = 34;
  inline const ::RemyBuffers::MemoryRange& domain() const;
  inline ::RemyBuffers::MemoryRange* mutable_domain();
  inline ::RemyBuffers::MemoryRange* release_domain();
  inline void set_allocated_domain(::RemyBuffers::MemoryRange* domain);

  // @@protoc_insertion_point(class_scope:RemyBuffers.Whisker)
 private:
  inline void set_has_window_increment();
  inline void clear_has_window_increment();
  inline void set_has_window_multiple();
  inline void clear_has_window_multiple();
  inline void set_has_intersend();
  inline void clear_has_intersend();
  inline void set_has_domain();
  inline void clear_has_domain();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  double window_multiple_;
  double intersend_;
  ::RemyBuffers::MemoryRange* domain_;
  ::google::protobuf::int32 window_increment_;
  friend void  protobuf_AddDesc_dna_2eproto();
  friend void protobuf_AssignDesc_dna_2eproto();
  friend void protobuf_ShutdownFile_dna_2eproto();

  void InitAsDefaultInstance();
  static Whisker* default_instance_;
};
// ===================================================================


// ===================================================================

// WhiskerTree

// optional .RemyBuffers.MemoryRange domain = 1;
inline bool WhiskerTree::has_domain() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void WhiskerTree::set_has_domain() {
  _has_bits_[0] |= 0x00000001u;
}
inline void WhiskerTree::clear_has_domain() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void WhiskerTree::clear_domain() {
  if (domain_ != NULL) domain_->::RemyBuffers::MemoryRange::Clear();
  clear_has_domain();
}
inline const ::RemyBuffers::MemoryRange& WhiskerTree::domain() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.WhiskerTree.domain)
  return domain_ != NULL ? *domain_ : *default_instance_->domain_;
}
inline ::RemyBuffers::MemoryRange* WhiskerTree::mutable_domain() {
  set_has_domain();
  if (domain_ == NULL) domain_ = new ::RemyBuffers::MemoryRange;
  // @@protoc_insertion_point(field_mutable:RemyBuffers.WhiskerTree.domain)
  return domain_;
}
inline ::RemyBuffers::MemoryRange* WhiskerTree::release_domain() {
  clear_has_domain();
  ::RemyBuffers::MemoryRange* temp = domain_;
  domain_ = NULL;
  return temp;
}
inline void WhiskerTree::set_allocated_domain(::RemyBuffers::MemoryRange* domain) {
  delete domain_;
  domain_ = domain;
  if (domain) {
    set_has_domain();
  } else {
    clear_has_domain();
  }
  // @@protoc_insertion_point(field_set_allocated:RemyBuffers.WhiskerTree.domain)
}

// repeated .RemyBuffers.WhiskerTree children = 2;
inline int WhiskerTree::children_size() const {
  return children_.size();
}
inline void WhiskerTree::clear_children() {
  children_.Clear();
}
inline const ::RemyBuffers::WhiskerTree& WhiskerTree::children(int index) const {
  // @@protoc_insertion_point(field_get:RemyBuffers.WhiskerTree.children)
  return children_.Get(index);
}
inline ::RemyBuffers::WhiskerTree* WhiskerTree::mutable_children(int index) {
  // @@protoc_insertion_point(field_mutable:RemyBuffers.WhiskerTree.children)
  return children_.Mutable(index);
}
inline ::RemyBuffers::WhiskerTree* WhiskerTree::add_children() {
  // @@protoc_insertion_point(field_add:RemyBuffers.WhiskerTree.children)
  return children_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::RemyBuffers::WhiskerTree >&
WhiskerTree::children() const {
  // @@protoc_insertion_point(field_list:RemyBuffers.WhiskerTree.children)
  return children_;
}
inline ::google::protobuf::RepeatedPtrField< ::RemyBuffers::WhiskerTree >*
WhiskerTree::mutable_children() {
  // @@protoc_insertion_point(field_mutable_list:RemyBuffers.WhiskerTree.children)
  return &children_;
}

// optional .RemyBuffers.Whisker leaf = 3;
inline bool WhiskerTree::has_leaf() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void WhiskerTree::set_has_leaf() {
  _has_bits_[0] |= 0x00000004u;
}
inline void WhiskerTree::clear_has_leaf() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void WhiskerTree::clear_leaf() {
  if (leaf_ != NULL) leaf_->::RemyBuffers::Whisker::Clear();
  clear_has_leaf();
}
inline const ::RemyBuffers::Whisker& WhiskerTree::leaf() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.WhiskerTree.leaf)
  return leaf_ != NULL ? *leaf_ : *default_instance_->leaf_;
}
inline ::RemyBuffers::Whisker* WhiskerTree::mutable_leaf() {
  set_has_leaf();
  if (leaf_ == NULL) leaf_ = new ::RemyBuffers::Whisker;
  // @@protoc_insertion_point(field_mutable:RemyBuffers.WhiskerTree.leaf)
  return leaf_;
}
inline ::RemyBuffers::Whisker* WhiskerTree::release_leaf() {
  clear_has_leaf();
  ::RemyBuffers::Whisker* temp = leaf_;
  leaf_ = NULL;
  return temp;
}
inline void WhiskerTree::set_allocated_leaf(::RemyBuffers::Whisker* leaf) {
  delete leaf_;
  leaf_ = leaf;
  if (leaf) {
    set_has_leaf();
  } else {
    clear_has_leaf();
  }
  // @@protoc_insertion_point(field_set_allocated:RemyBuffers.WhiskerTree.leaf)
}

// -------------------------------------------------------------------

// MemoryRange

// optional .RemyBuffers.Memory lower = 11;
inline bool MemoryRange::has_lower() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MemoryRange::set_has_lower() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MemoryRange::clear_has_lower() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MemoryRange::clear_lower() {
  if (lower_ != NULL) lower_->::RemyBuffers::Memory::Clear();
  clear_has_lower();
}
inline const ::RemyBuffers::Memory& MemoryRange::lower() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.MemoryRange.lower)
  return lower_ != NULL ? *lower_ : *default_instance_->lower_;
}
inline ::RemyBuffers::Memory* MemoryRange::mutable_lower() {
  set_has_lower();
  if (lower_ == NULL) lower_ = new ::RemyBuffers::Memory;
  // @@protoc_insertion_point(field_mutable:RemyBuffers.MemoryRange.lower)
  return lower_;
}
inline ::RemyBuffers::Memory* MemoryRange::release_lower() {
  clear_has_lower();
  ::RemyBuffers::Memory* temp = lower_;
  lower_ = NULL;
  return temp;
}
inline void MemoryRange::set_allocated_lower(::RemyBuffers::Memory* lower) {
  delete lower_;
  lower_ = lower;
  if (lower) {
    set_has_lower();
  } else {
    clear_has_lower();
  }
  // @@protoc_insertion_point(field_set_allocated:RemyBuffers.MemoryRange.lower)
}

// optional .RemyBuffers.Memory upper = 12;
inline bool MemoryRange::has_upper() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MemoryRange::set_has_upper() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MemoryRange::clear_has_upper() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MemoryRange::clear_upper() {
  if (upper_ != NULL) upper_->::RemyBuffers::Memory::Clear();
  clear_has_upper();
}
inline const ::RemyBuffers::Memory& MemoryRange::upper() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.MemoryRange.upper)
  return upper_ != NULL ? *upper_ : *default_instance_->upper_;
}
inline ::RemyBuffers::Memory* MemoryRange::mutable_upper() {
  set_has_upper();
  if (upper_ == NULL) upper_ = new ::RemyBuffers::Memory;
  // @@protoc_insertion_point(field_mutable:RemyBuffers.MemoryRange.upper)
  return upper_;
}
inline ::RemyBuffers::Memory* MemoryRange::release_upper() {
  clear_has_upper();
  ::RemyBuffers::Memory* temp = upper_;
  upper_ = NULL;
  return temp;
}
inline void MemoryRange::set_allocated_upper(::RemyBuffers::Memory* upper) {
  delete upper_;
  upper_ = upper;
  if (upper) {
    set_has_upper();
  } else {
    clear_has_upper();
  }
  // @@protoc_insertion_point(field_set_allocated:RemyBuffers.MemoryRange.upper)
}

// -------------------------------------------------------------------

// Memory

// optional double rec_rec_ewma = 22;
inline bool Memory::has_rec_rec_ewma() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Memory::set_has_rec_rec_ewma() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Memory::clear_has_rec_rec_ewma() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Memory::clear_rec_rec_ewma() {
  rec_rec_ewma_ = 0;
  clear_has_rec_rec_ewma();
}
inline double Memory::rec_rec_ewma() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.Memory.rec_rec_ewma)
  return rec_rec_ewma_;
}
inline void Memory::set_rec_rec_ewma(double value) {
  set_has_rec_rec_ewma();
  rec_rec_ewma_ = value;
  // @@protoc_insertion_point(field_set:RemyBuffers.Memory.rec_rec_ewma)
}

// -------------------------------------------------------------------

// Whisker

// optional sint32 window_increment = 31;
inline bool Whisker::has_window_increment() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Whisker::set_has_window_increment() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Whisker::clear_has_window_increment() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Whisker::clear_window_increment() {
  window_increment_ = 0;
  clear_has_window_increment();
}
inline ::google::protobuf::int32 Whisker::window_increment() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.Whisker.window_increment)
  return window_increment_;
}
inline void Whisker::set_window_increment(::google::protobuf::int32 value) {
  set_has_window_increment();
  window_increment_ = value;
  // @@protoc_insertion_point(field_set:RemyBuffers.Whisker.window_increment)
}

// optional double window_multiple = 32;
inline bool Whisker::has_window_multiple() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Whisker::set_has_window_multiple() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Whisker::clear_has_window_multiple() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Whisker::clear_window_multiple() {
  window_multiple_ = 0;
  clear_has_window_multiple();
}
inline double Whisker::window_multiple() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.Whisker.window_multiple)
  return window_multiple_;
}
inline void Whisker::set_window_multiple(double value) {
  set_has_window_multiple();
  window_multiple_ = value;
  // @@protoc_insertion_point(field_set:RemyBuffers.Whisker.window_multiple)
}

// optional double intersend = 33;
inline bool Whisker::has_intersend() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Whisker::set_has_intersend() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Whisker::clear_has_intersend() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Whisker::clear_intersend() {
  intersend_ = 0;
  clear_has_intersend();
}
inline double Whisker::intersend() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.Whisker.intersend)
  return intersend_;
}
inline void Whisker::set_intersend(double value) {
  set_has_intersend();
  intersend_ = value;
  // @@protoc_insertion_point(field_set:RemyBuffers.Whisker.intersend)
}

// optional .RemyBuffers.MemoryRange domain = 34;
inline bool Whisker::has_domain() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Whisker::set_has_domain() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Whisker::clear_has_domain() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Whisker::clear_domain() {
  if (domain_ != NULL) domain_->::RemyBuffers::MemoryRange::Clear();
  clear_has_domain();
}
inline const ::RemyBuffers::MemoryRange& Whisker::domain() const {
  // @@protoc_insertion_point(field_get:RemyBuffers.Whisker.domain)
  return domain_ != NULL ? *domain_ : *default_instance_->domain_;
}
inline ::RemyBuffers::MemoryRange* Whisker::mutable_domain() {
  set_has_domain();
  if (domain_ == NULL) domain_ = new ::RemyBuffers::MemoryRange;
  // @@protoc_insertion_point(field_mutable:RemyBuffers.Whisker.domain)
  return domain_;
}
inline ::RemyBuffers::MemoryRange* Whisker::release_domain() {
  clear_has_domain();
  ::RemyBuffers::MemoryRange* temp = domain_;
  domain_ = NULL;
  return temp;
}
inline void Whisker::set_allocated_domain(::RemyBuffers::MemoryRange* domain) {
  delete domain_;
  domain_ = domain;
  if (domain) {
    set_has_domain();
  } else {
    clear_has_domain();
  }
  // @@protoc_insertion_point(field_set_allocated:RemyBuffers.Whisker.domain)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace RemyBuffers

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_dna_2eproto__INCLUDED
