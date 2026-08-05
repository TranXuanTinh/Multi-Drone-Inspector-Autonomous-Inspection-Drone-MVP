// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from multi_drone_msgs:srv/AssignMission.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "multi_drone_msgs/srv/detail/assign_mission__functions.h"
#include "multi_drone_msgs/srv/detail/assign_mission__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace multi_drone_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void AssignMission_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) multi_drone_msgs::srv::AssignMission_Request(_init);
}

void AssignMission_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<multi_drone_msgs::srv::AssignMission_Request *>(message_memory);
  typed_message->~AssignMission_Request();
}

size_t size_function__AssignMission_Request__waypoint_lats(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AssignMission_Request__waypoint_lats(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__AssignMission_Request__waypoint_lats(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__AssignMission_Request__waypoint_lats(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__AssignMission_Request__waypoint_lats(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__AssignMission_Request__waypoint_lats(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__AssignMission_Request__waypoint_lats(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__AssignMission_Request__waypoint_lats(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__AssignMission_Request__waypoint_lons(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AssignMission_Request__waypoint_lons(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__AssignMission_Request__waypoint_lons(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__AssignMission_Request__waypoint_lons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__AssignMission_Request__waypoint_lons(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__AssignMission_Request__waypoint_lons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__AssignMission_Request__waypoint_lons(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__AssignMission_Request__waypoint_lons(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__AssignMission_Request__waypoint_alts(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AssignMission_Request__waypoint_alts(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__AssignMission_Request__waypoint_alts(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__AssignMission_Request__waypoint_alts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__AssignMission_Request__waypoint_alts(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__AssignMission_Request__waypoint_alts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__AssignMission_Request__waypoint_alts(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__AssignMission_Request__waypoint_alts(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AssignMission_Request_message_member_array[6] = {
  {
    "vehicle_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Request, vehicle_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mission_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Request, mission_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "waypoint_lats",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Request, waypoint_lats),  // bytes offset in struct
    nullptr,  // default value
    size_function__AssignMission_Request__waypoint_lats,  // size() function pointer
    get_const_function__AssignMission_Request__waypoint_lats,  // get_const(index) function pointer
    get_function__AssignMission_Request__waypoint_lats,  // get(index) function pointer
    fetch_function__AssignMission_Request__waypoint_lats,  // fetch(index, &value) function pointer
    assign_function__AssignMission_Request__waypoint_lats,  // assign(index, value) function pointer
    resize_function__AssignMission_Request__waypoint_lats  // resize(index) function pointer
  },
  {
    "waypoint_lons",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Request, waypoint_lons),  // bytes offset in struct
    nullptr,  // default value
    size_function__AssignMission_Request__waypoint_lons,  // size() function pointer
    get_const_function__AssignMission_Request__waypoint_lons,  // get_const(index) function pointer
    get_function__AssignMission_Request__waypoint_lons,  // get(index) function pointer
    fetch_function__AssignMission_Request__waypoint_lons,  // fetch(index, &value) function pointer
    assign_function__AssignMission_Request__waypoint_lons,  // assign(index, value) function pointer
    resize_function__AssignMission_Request__waypoint_lons  // resize(index) function pointer
  },
  {
    "waypoint_alts",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Request, waypoint_alts),  // bytes offset in struct
    nullptr,  // default value
    size_function__AssignMission_Request__waypoint_alts,  // size() function pointer
    get_const_function__AssignMission_Request__waypoint_alts,  // get_const(index) function pointer
    get_function__AssignMission_Request__waypoint_alts,  // get(index) function pointer
    fetch_function__AssignMission_Request__waypoint_alts,  // fetch(index, &value) function pointer
    assign_function__AssignMission_Request__waypoint_alts,  // assign(index, value) function pointer
    resize_function__AssignMission_Request__waypoint_alts  // resize(index) function pointer
  },
  {
    "speed_ms",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Request, speed_ms),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AssignMission_Request_message_members = {
  "multi_drone_msgs::srv",  // message namespace
  "AssignMission_Request",  // message name
  6,  // number of fields
  sizeof(multi_drone_msgs::srv::AssignMission_Request),
  false,  // has_any_key_member_
  AssignMission_Request_message_member_array,  // message members
  AssignMission_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  AssignMission_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AssignMission_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AssignMission_Request_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__srv__AssignMission_Request__get_type_hash,
  &multi_drone_msgs__srv__AssignMission_Request__get_type_description,
  &multi_drone_msgs__srv__AssignMission_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace multi_drone_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Request>()
{
  return &::multi_drone_msgs::srv::rosidl_typesupport_introspection_cpp::AssignMission_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_drone_msgs, srv, AssignMission_Request)() {
  return &::multi_drone_msgs::srv::rosidl_typesupport_introspection_cpp::AssignMission_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__functions.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace multi_drone_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void AssignMission_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) multi_drone_msgs::srv::AssignMission_Response(_init);
}

void AssignMission_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<multi_drone_msgs::srv::AssignMission_Response *>(message_memory);
  typed_message->~AssignMission_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AssignMission_Response_message_member_array[3] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_waypoints_accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Response, num_waypoints_accepted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AssignMission_Response_message_members = {
  "multi_drone_msgs::srv",  // message namespace
  "AssignMission_Response",  // message name
  3,  // number of fields
  sizeof(multi_drone_msgs::srv::AssignMission_Response),
  false,  // has_any_key_member_
  AssignMission_Response_message_member_array,  // message members
  AssignMission_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  AssignMission_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AssignMission_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AssignMission_Response_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__srv__AssignMission_Response__get_type_hash,
  &multi_drone_msgs__srv__AssignMission_Response__get_type_description,
  &multi_drone_msgs__srv__AssignMission_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace multi_drone_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Response>()
{
  return &::multi_drone_msgs::srv::rosidl_typesupport_introspection_cpp::AssignMission_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_drone_msgs, srv, AssignMission_Response)() {
  return &::multi_drone_msgs::srv::rosidl_typesupport_introspection_cpp::AssignMission_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__functions.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace multi_drone_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void AssignMission_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) multi_drone_msgs::srv::AssignMission_Event(_init);
}

void AssignMission_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<multi_drone_msgs::srv::AssignMission_Event *>(message_memory);
  typed_message->~AssignMission_Event();
}

size_t size_function__AssignMission_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<multi_drone_msgs::srv::AssignMission_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AssignMission_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<multi_drone_msgs::srv::AssignMission_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__AssignMission_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<multi_drone_msgs::srv::AssignMission_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__AssignMission_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const multi_drone_msgs::srv::AssignMission_Request *>(
    get_const_function__AssignMission_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<multi_drone_msgs::srv::AssignMission_Request *>(untyped_value);
  value = item;
}

void assign_function__AssignMission_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<multi_drone_msgs::srv::AssignMission_Request *>(
    get_function__AssignMission_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const multi_drone_msgs::srv::AssignMission_Request *>(untyped_value);
  item = value;
}

void resize_function__AssignMission_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<multi_drone_msgs::srv::AssignMission_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__AssignMission_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<multi_drone_msgs::srv::AssignMission_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AssignMission_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<multi_drone_msgs::srv::AssignMission_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__AssignMission_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<multi_drone_msgs::srv::AssignMission_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__AssignMission_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const multi_drone_msgs::srv::AssignMission_Response *>(
    get_const_function__AssignMission_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<multi_drone_msgs::srv::AssignMission_Response *>(untyped_value);
  value = item;
}

void assign_function__AssignMission_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<multi_drone_msgs::srv::AssignMission_Response *>(
    get_function__AssignMission_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const multi_drone_msgs::srv::AssignMission_Response *>(untyped_value);
  item = value;
}

void resize_function__AssignMission_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<multi_drone_msgs::srv::AssignMission_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AssignMission_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__AssignMission_Event__request,  // size() function pointer
    get_const_function__AssignMission_Event__request,  // get_const(index) function pointer
    get_function__AssignMission_Event__request,  // get(index) function pointer
    fetch_function__AssignMission_Event__request,  // fetch(index, &value) function pointer
    assign_function__AssignMission_Event__request,  // assign(index, value) function pointer
    resize_function__AssignMission_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(multi_drone_msgs::srv::AssignMission_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__AssignMission_Event__response,  // size() function pointer
    get_const_function__AssignMission_Event__response,  // get_const(index) function pointer
    get_function__AssignMission_Event__response,  // get(index) function pointer
    fetch_function__AssignMission_Event__response,  // fetch(index, &value) function pointer
    assign_function__AssignMission_Event__response,  // assign(index, value) function pointer
    resize_function__AssignMission_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AssignMission_Event_message_members = {
  "multi_drone_msgs::srv",  // message namespace
  "AssignMission_Event",  // message name
  3,  // number of fields
  sizeof(multi_drone_msgs::srv::AssignMission_Event),
  false,  // has_any_key_member_
  AssignMission_Event_message_member_array,  // message members
  AssignMission_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  AssignMission_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AssignMission_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AssignMission_Event_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__srv__AssignMission_Event__get_type_hash,
  &multi_drone_msgs__srv__AssignMission_Event__get_type_description,
  &multi_drone_msgs__srv__AssignMission_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace multi_drone_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Event>()
{
  return &::multi_drone_msgs::srv::rosidl_typesupport_introspection_cpp::AssignMission_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_drone_msgs, srv, AssignMission_Event)() {
  return &::multi_drone_msgs::srv::rosidl_typesupport_introspection_cpp::AssignMission_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__functions.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace multi_drone_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers AssignMission_service_members = {
  "multi_drone_msgs::srv",  // service namespace
  "AssignMission",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<multi_drone_msgs::srv::AssignMission>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t AssignMission_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AssignMission_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_drone_msgs::srv::AssignMission_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<multi_drone_msgs::srv::AssignMission>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<multi_drone_msgs::srv::AssignMission>,
  &multi_drone_msgs__srv__AssignMission__get_type_hash,
  &multi_drone_msgs__srv__AssignMission__get_type_description,
  &multi_drone_msgs__srv__AssignMission__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace multi_drone_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<multi_drone_msgs::srv::AssignMission>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::multi_drone_msgs::srv::rosidl_typesupport_introspection_cpp::AssignMission_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::multi_drone_msgs::srv::AssignMission_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::multi_drone_msgs::srv::AssignMission_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::multi_drone_msgs::srv::AssignMission_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_drone_msgs, srv, AssignMission)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<multi_drone_msgs::srv::AssignMission>();
}

#ifdef __cplusplus
}
#endif
