// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: haha2.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_haha2_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_haha2_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_haha2_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_haha2_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_haha2_2eproto;
class User;
class UserDefaultTypeInternal;
extern UserDefaultTypeInternal _User_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::User* Arena::CreateMaybeMessage<::User>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class User PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:User) */ {
 public:
  inline User() : User(nullptr) {}
  virtual ~User();

  User(const User& from);
  User(User&& from) noexcept
    : User() {
    *this = ::std::move(from);
  }

  inline User& operator=(const User& from) {
    CopyFrom(from);
    return *this;
  }
  inline User& operator=(User&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const User& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const User* internal_default_instance() {
    return reinterpret_cast<const User*>(
               &_User_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(User& a, User& b) {
    a.Swap(&b);
  }
  inline void Swap(User* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(User* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline User* New() const final {
    return CreateMaybeMessage<User>(nullptr);
  }

  User* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<User>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const User& from);
  void MergeFrom(const User& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(User* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "User";
  }
  protected:
  explicit User(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_haha2_2eproto);
    return ::descriptor_table_haha2_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
    kDisplayNameFieldNumber = 2,
    kAddressFieldNumber = 4,
    kAgeFieldNumber = 3,
    kBirthYearFieldNumber = 5,
  };
  // string Id = 1;
  void clear_id();
  const std::string& id() const;
  void set_id(const std::string& value);
  void set_id(std::string&& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  std::string* mutable_id();
  std::string* release_id();
  void set_allocated_id(std::string* id);
  private:
  const std::string& _internal_id() const;
  void _internal_set_id(const std::string& value);
  std::string* _internal_mutable_id();
  public:

  // string DisplayName = 2;
  void clear_displayname();
  const std::string& displayname() const;
  void set_displayname(const std::string& value);
  void set_displayname(std::string&& value);
  void set_displayname(const char* value);
  void set_displayname(const char* value, size_t size);
  std::string* mutable_displayname();
  std::string* release_displayname();
  void set_allocated_displayname(std::string* displayname);
  private:
  const std::string& _internal_displayname() const;
  void _internal_set_displayname(const std::string& value);
  std::string* _internal_mutable_displayname();
  public:

  // string Address = 4;
  void clear_address();
  const std::string& address() const;
  void set_address(const std::string& value);
  void set_address(std::string&& value);
  void set_address(const char* value);
  void set_address(const char* value, size_t size);
  std::string* mutable_address();
  std::string* release_address();
  void set_allocated_address(std::string* address);
  private:
  const std::string& _internal_address() const;
  void _internal_set_address(const std::string& value);
  std::string* _internal_mutable_address();
  public:

  // int32 Age = 3;
  void clear_age();
  ::PROTOBUF_NAMESPACE_ID::int32 age() const;
  void set_age(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_age() const;
  void _internal_set_age(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 BirthYear = 5;
  void clear_birthyear();
  ::PROTOBUF_NAMESPACE_ID::int32 birthyear() const;
  void set_birthyear(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_birthyear() const;
  void _internal_set_birthyear(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:User)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr displayname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr address_;
  ::PROTOBUF_NAMESPACE_ID::int32 age_;
  ::PROTOBUF_NAMESPACE_ID::int32 birthyear_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_haha2_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// User

// string Id = 1;
inline void User::clear_id() {
  id_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& User::id() const {
  // @@protoc_insertion_point(field_get:User.Id)
  return _internal_id();
}
inline void User::set_id(const std::string& value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:User.Id)
}
inline std::string* User::mutable_id() {
  // @@protoc_insertion_point(field_mutable:User.Id)
  return _internal_mutable_id();
}
inline const std::string& User::_internal_id() const {
  return id_.Get();
}
inline void User::_internal_set_id(const std::string& value) {
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void User::set_id(std::string&& value) {
  
  id_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:User.Id)
}
inline void User::set_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:User.Id)
}
inline void User::set_id(const char* value,
    size_t size) {
  
  id_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:User.Id)
}
inline std::string* User::_internal_mutable_id() {
  
  return id_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* User::release_id() {
  // @@protoc_insertion_point(field_release:User.Id)
  return id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void User::set_allocated_id(std::string* id) {
  if (id != nullptr) {
    
  } else {
    
  }
  id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:User.Id)
}

// string DisplayName = 2;
inline void User::clear_displayname() {
  displayname_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& User::displayname() const {
  // @@protoc_insertion_point(field_get:User.DisplayName)
  return _internal_displayname();
}
inline void User::set_displayname(const std::string& value) {
  _internal_set_displayname(value);
  // @@protoc_insertion_point(field_set:User.DisplayName)
}
inline std::string* User::mutable_displayname() {
  // @@protoc_insertion_point(field_mutable:User.DisplayName)
  return _internal_mutable_displayname();
}
inline const std::string& User::_internal_displayname() const {
  return displayname_.Get();
}
inline void User::_internal_set_displayname(const std::string& value) {
  
  displayname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void User::set_displayname(std::string&& value) {
  
  displayname_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:User.DisplayName)
}
inline void User::set_displayname(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  displayname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:User.DisplayName)
}
inline void User::set_displayname(const char* value,
    size_t size) {
  
  displayname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:User.DisplayName)
}
inline std::string* User::_internal_mutable_displayname() {
  
  return displayname_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* User::release_displayname() {
  // @@protoc_insertion_point(field_release:User.DisplayName)
  return displayname_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void User::set_allocated_displayname(std::string* displayname) {
  if (displayname != nullptr) {
    
  } else {
    
  }
  displayname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), displayname,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:User.DisplayName)
}

// int32 Age = 3;
inline void User::clear_age() {
  age_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 User::_internal_age() const {
  return age_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 User::age() const {
  // @@protoc_insertion_point(field_get:User.Age)
  return _internal_age();
}
inline void User::_internal_set_age(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  age_ = value;
}
inline void User::set_age(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_age(value);
  // @@protoc_insertion_point(field_set:User.Age)
}

// string Address = 4;
inline void User::clear_address() {
  address_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& User::address() const {
  // @@protoc_insertion_point(field_get:User.Address)
  return _internal_address();
}
inline void User::set_address(const std::string& value) {
  _internal_set_address(value);
  // @@protoc_insertion_point(field_set:User.Address)
}
inline std::string* User::mutable_address() {
  // @@protoc_insertion_point(field_mutable:User.Address)
  return _internal_mutable_address();
}
inline const std::string& User::_internal_address() const {
  return address_.Get();
}
inline void User::_internal_set_address(const std::string& value) {
  
  address_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void User::set_address(std::string&& value) {
  
  address_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:User.Address)
}
inline void User::set_address(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  address_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:User.Address)
}
inline void User::set_address(const char* value,
    size_t size) {
  
  address_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:User.Address)
}
inline std::string* User::_internal_mutable_address() {
  
  return address_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* User::release_address() {
  // @@protoc_insertion_point(field_release:User.Address)
  return address_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void User::set_allocated_address(std::string* address) {
  if (address != nullptr) {
    
  } else {
    
  }
  address_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), address,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:User.Address)
}

// int32 BirthYear = 5;
inline void User::clear_birthyear() {
  birthyear_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 User::_internal_birthyear() const {
  return birthyear_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 User::birthyear() const {
  // @@protoc_insertion_point(field_get:User.BirthYear)
  return _internal_birthyear();
}
inline void User::_internal_set_birthyear(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  birthyear_ = value;
}
inline void User::set_birthyear(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_birthyear(value);
  // @@protoc_insertion_point(field_set:User.BirthYear)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_haha2_2eproto