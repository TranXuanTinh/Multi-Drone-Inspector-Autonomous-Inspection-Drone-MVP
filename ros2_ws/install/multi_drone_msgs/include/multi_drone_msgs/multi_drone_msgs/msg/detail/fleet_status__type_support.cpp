// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "multi_drone_msgs/msg/detail/fleet_status__functions.h"
#include "multi_drone_msgs/msg/detail/fleet_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace multi_drone_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FleetStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) multi_drone_msgs::msg::FleetStatus(_init);
}

void FleetStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<multi_drone_msgs::msg::FleetStatus *>(message_memory);
  typed_message->~FleetStatus();
}

size_t size_function__FleetStatus__vehicles(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<multi_drone_msgs::msg::VehicleStatus> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FleetStatus__vehicles(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<multi_drone_msgs::msg::VehicleStatus> *>(untyped_member);
  return &member[index];
}

void * get_function__FleetStatus__vehicles(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<multi_drone_msgs::msg::VehicleStatus> *>(untyped_member);
  return &member[index];
}

void fetch_function__FleetStatus__vehicles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const multi_drone_msgs::msg::VehicleStatus *>(
    get_const_function__FleetStatus__vehicles(untyped_member, index));
  auto & value = *reinterpret_cast<multi_drone_msgs::msg::VehicleStatus *>(untyped_value);
  value = item;
}

void assign_function__FleetStatus__vehicles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<multi_drone_msgs::msg::VehicleStatus *>(
    get_function__FleetStatus__vehicles(untyped_member, index));
  const auto & value = *reinterpret_cast<const multi_drone_msgs::msg::VehicleStatus *>(untyped_value);
  item = value;
}

void resize_function__FleetStatus__vehicles(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<multi_drone_msgs::msg::VehicleStatus> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FleetStatus_message_member_array[13] = {
  {
    "fleet_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, fleet_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "vehicles",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<multi_drone_msgs::msg::VehicleStatus>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, vehicles),  // bytes offset in struct
    nullptr,  // default value
    size_function__FleetStatus__vehicles,  // size() function pointer
    get_const_function__FleetStatus__vehicles,  // get_const(index) function pointer
    get_function__FleetStatus__vehicles,  // get(index) function pointer
    fetch_function__FleetStatus__vehicles,  // fetch(index, &value) function pointer
    assign_function__FleetStatus__vehicles,  // assign(index, value) function pointer
    resize_function__FleetStatus__vehicles  // resize(index) function pointer
  },
  {
    "current_formation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, current_formation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "formation_spacing_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, formation_spacing_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "formation_heading_deg",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, formation_heading_deg),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_vehicles_registered",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, num_vehicles_registered),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_vehicles_connected",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, num_vehicles_connected),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_vehicles_armed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, num_vehicles_armed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "num_vehicles_airborne",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, num_vehicles_airborne),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "min_inter_vehicle_distance_m",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, min_inter_vehicle_distance_m),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "collision_warning",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, collision_warning),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mission_elapsed_s",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs::msg::FleetStatus, mission_elapsed_s),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FleetStatus_message_members = {
  "multi_drone_msgs::msg",  // message namespace
  "FleetStatus",  // message name
  13,  // number of fields
  sizeof(multi_drone_msgs::msg::FleetStatus),
  false,  // has_any_key_member_
  FleetStatus_message_member_array,  // message members
  FleetStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  FleetStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FleetStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FleetStatus_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__msg__FleetStatus__get_type_hash,
  &multi_drone_msgs__msg__FleetStatus__get_type_description,
  &multi_drone_msgs__msg__FleetStatus__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace multi_drone_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<multi_drone_msgs::msg::FleetStatus>()
{
  return &::multi_drone_msgs::msg::rosidl_typesupport_introspection_cpp::FleetStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, multi_drone_msgs, msg, FleetStatus)() {
  return &::multi_drone_msgs::msg::rosidl_typesupport_introspection_cpp::FleetStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
