// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nav_msgs.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_nav_5fmsgs_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_nav_5fmsgs_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_nav_5fmsgs_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_nav_5fmsgs_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_nav_5fmsgs_2eproto;
namespace robot_service {
class Pose;
struct PoseDefaultTypeInternal;
extern PoseDefaultTypeInternal _Pose_default_instance_;
class Quaternion;
struct QuaternionDefaultTypeInternal;
extern QuaternionDefaultTypeInternal _Quaternion_default_instance_;
class Vector3;
struct Vector3DefaultTypeInternal;
extern Vector3DefaultTypeInternal _Vector3_default_instance_;
}  // namespace robot_service
PROTOBUF_NAMESPACE_OPEN
template<> ::robot_service::Pose* Arena::CreateMaybeMessage<::robot_service::Pose>(Arena*);
template<> ::robot_service::Quaternion* Arena::CreateMaybeMessage<::robot_service::Quaternion>(Arena*);
template<> ::robot_service::Vector3* Arena::CreateMaybeMessage<::robot_service::Vector3>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace robot_service {

// ===================================================================

class Pose final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:robot_service.Pose) */ {
 public:
  inline Pose() : Pose(nullptr) {}
  ~Pose() override;
  explicit constexpr Pose(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Pose(const Pose& from);
  Pose(Pose&& from) noexcept
    : Pose() {
    *this = ::std::move(from);
  }

  inline Pose& operator=(const Pose& from) {
    CopyFrom(from);
    return *this;
  }
  inline Pose& operator=(Pose&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Pose& default_instance() {
    return *internal_default_instance();
  }
  static inline const Pose* internal_default_instance() {
    return reinterpret_cast<const Pose*>(
               &_Pose_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Pose& a, Pose& b) {
    a.Swap(&b);
  }
  inline void Swap(Pose* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Pose* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Pose* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Pose>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Pose& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Pose& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Pose* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "robot_service.Pose";
  }
  protected:
  explicit Pose(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kThetaFieldNumber = 3,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // double theta = 3;
  void clear_theta();
  double theta() const;
  void set_theta(double value);
  private:
  double _internal_theta() const;
  void _internal_set_theta(double value);
  public:

  // @@protoc_insertion_point(class_scope:robot_service.Pose)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  double theta_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_nav_5fmsgs_2eproto;
};
// -------------------------------------------------------------------

class Vector3 final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:robot_service.Vector3) */ {
 public:
  inline Vector3() : Vector3(nullptr) {}
  ~Vector3() override;
  explicit constexpr Vector3(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Vector3(const Vector3& from);
  Vector3(Vector3&& from) noexcept
    : Vector3() {
    *this = ::std::move(from);
  }

  inline Vector3& operator=(const Vector3& from) {
    CopyFrom(from);
    return *this;
  }
  inline Vector3& operator=(Vector3&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Vector3& default_instance() {
    return *internal_default_instance();
  }
  static inline const Vector3* internal_default_instance() {
    return reinterpret_cast<const Vector3*>(
               &_Vector3_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Vector3& a, Vector3& b) {
    a.Swap(&b);
  }
  inline void Swap(Vector3* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Vector3* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Vector3* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Vector3>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Vector3& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Vector3& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Vector3* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "robot_service.Vector3";
  }
  protected:
  explicit Vector3(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // double z = 3;
  void clear_z();
  double z() const;
  void set_z(double value);
  private:
  double _internal_z() const;
  void _internal_set_z(double value);
  public:

  // @@protoc_insertion_point(class_scope:robot_service.Vector3)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  double z_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_nav_5fmsgs_2eproto;
};
// -------------------------------------------------------------------

class Quaternion final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:robot_service.Quaternion) */ {
 public:
  inline Quaternion() : Quaternion(nullptr) {}
  ~Quaternion() override;
  explicit constexpr Quaternion(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Quaternion(const Quaternion& from);
  Quaternion(Quaternion&& from) noexcept
    : Quaternion() {
    *this = ::std::move(from);
  }

  inline Quaternion& operator=(const Quaternion& from) {
    CopyFrom(from);
    return *this;
  }
  inline Quaternion& operator=(Quaternion&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Quaternion& default_instance() {
    return *internal_default_instance();
  }
  static inline const Quaternion* internal_default_instance() {
    return reinterpret_cast<const Quaternion*>(
               &_Quaternion_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Quaternion& a, Quaternion& b) {
    a.Swap(&b);
  }
  inline void Swap(Quaternion* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Quaternion* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Quaternion* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Quaternion>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Quaternion& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Quaternion& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Quaternion* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "robot_service.Quaternion";
  }
  protected:
  explicit Quaternion(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
    kWFieldNumber = 4,
  };
  // double x = 1;
  void clear_x();
  double x() const;
  void set_x(double value);
  private:
  double _internal_x() const;
  void _internal_set_x(double value);
  public:

  // double y = 2;
  void clear_y();
  double y() const;
  void set_y(double value);
  private:
  double _internal_y() const;
  void _internal_set_y(double value);
  public:

  // double z = 3;
  void clear_z();
  double z() const;
  void set_z(double value);
  private:
  double _internal_z() const;
  void _internal_set_z(double value);
  public:

  // double w = 4;
  void clear_w();
  double w() const;
  void set_w(double value);
  private:
  double _internal_w() const;
  void _internal_set_w(double value);
  public:

  // @@protoc_insertion_point(class_scope:robot_service.Quaternion)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double x_;
  double y_;
  double z_;
  double w_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_nav_5fmsgs_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Pose

// double x = 1;
inline void Pose::clear_x() {
  x_ = 0;
}
inline double Pose::_internal_x() const {
  return x_;
}
inline double Pose::x() const {
  // @@protoc_insertion_point(field_get:robot_service.Pose.x)
  return _internal_x();
}
inline void Pose::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Pose::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:robot_service.Pose.x)
}

// double y = 2;
inline void Pose::clear_y() {
  y_ = 0;
}
inline double Pose::_internal_y() const {
  return y_;
}
inline double Pose::y() const {
  // @@protoc_insertion_point(field_get:robot_service.Pose.y)
  return _internal_y();
}
inline void Pose::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Pose::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:robot_service.Pose.y)
}

// double theta = 3;
inline void Pose::clear_theta() {
  theta_ = 0;
}
inline double Pose::_internal_theta() const {
  return theta_;
}
inline double Pose::theta() const {
  // @@protoc_insertion_point(field_get:robot_service.Pose.theta)
  return _internal_theta();
}
inline void Pose::_internal_set_theta(double value) {
  
  theta_ = value;
}
inline void Pose::set_theta(double value) {
  _internal_set_theta(value);
  // @@protoc_insertion_point(field_set:robot_service.Pose.theta)
}

// -------------------------------------------------------------------

// Vector3

// double x = 1;
inline void Vector3::clear_x() {
  x_ = 0;
}
inline double Vector3::_internal_x() const {
  return x_;
}
inline double Vector3::x() const {
  // @@protoc_insertion_point(field_get:robot_service.Vector3.x)
  return _internal_x();
}
inline void Vector3::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Vector3::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:robot_service.Vector3.x)
}

// double y = 2;
inline void Vector3::clear_y() {
  y_ = 0;
}
inline double Vector3::_internal_y() const {
  return y_;
}
inline double Vector3::y() const {
  // @@protoc_insertion_point(field_get:robot_service.Vector3.y)
  return _internal_y();
}
inline void Vector3::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Vector3::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:robot_service.Vector3.y)
}

// double z = 3;
inline void Vector3::clear_z() {
  z_ = 0;
}
inline double Vector3::_internal_z() const {
  return z_;
}
inline double Vector3::z() const {
  // @@protoc_insertion_point(field_get:robot_service.Vector3.z)
  return _internal_z();
}
inline void Vector3::_internal_set_z(double value) {
  
  z_ = value;
}
inline void Vector3::set_z(double value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:robot_service.Vector3.z)
}

// -------------------------------------------------------------------

// Quaternion

// double x = 1;
inline void Quaternion::clear_x() {
  x_ = 0;
}
inline double Quaternion::_internal_x() const {
  return x_;
}
inline double Quaternion::x() const {
  // @@protoc_insertion_point(field_get:robot_service.Quaternion.x)
  return _internal_x();
}
inline void Quaternion::_internal_set_x(double value) {
  
  x_ = value;
}
inline void Quaternion::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:robot_service.Quaternion.x)
}

// double y = 2;
inline void Quaternion::clear_y() {
  y_ = 0;
}
inline double Quaternion::_internal_y() const {
  return y_;
}
inline double Quaternion::y() const {
  // @@protoc_insertion_point(field_get:robot_service.Quaternion.y)
  return _internal_y();
}
inline void Quaternion::_internal_set_y(double value) {
  
  y_ = value;
}
inline void Quaternion::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:robot_service.Quaternion.y)
}

// double z = 3;
inline void Quaternion::clear_z() {
  z_ = 0;
}
inline double Quaternion::_internal_z() const {
  return z_;
}
inline double Quaternion::z() const {
  // @@protoc_insertion_point(field_get:robot_service.Quaternion.z)
  return _internal_z();
}
inline void Quaternion::_internal_set_z(double value) {
  
  z_ = value;
}
inline void Quaternion::set_z(double value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:robot_service.Quaternion.z)
}

// double w = 4;
inline void Quaternion::clear_w() {
  w_ = 0;
}
inline double Quaternion::_internal_w() const {
  return w_;
}
inline double Quaternion::w() const {
  // @@protoc_insertion_point(field_get:robot_service.Quaternion.w)
  return _internal_w();
}
inline void Quaternion::_internal_set_w(double value) {
  
  w_ = value;
}
inline void Quaternion::set_w(double value) {
  _internal_set_w(value);
  // @@protoc_insertion_point(field_set:robot_service.Quaternion.w)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace robot_service

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_nav_5fmsgs_2eproto
