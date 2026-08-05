// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "multi_drone_msgs/msg/detail/fleet_status__rosidl_typesupport_introspection_c.h"
#include "multi_drone_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "multi_drone_msgs/msg/detail/fleet_status__functions.h"
#include "multi_drone_msgs/msg/detail/fleet_status__struct.h"


// Include directives for member types
// Member `fleet_state`
// Member `current_formation`
#include "rosidl_runtime_c/string_functions.h"
// Member `vehicles`
#include "multi_drone_msgs/msg/vehicle_status.h"
// Member `vehicles`
#include "multi_drone_msgs/msg/detail/vehicle_status__rosidl_typesupport_introspection_c.h"
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  multi_drone_msgs__msg__FleetStatus__init(message_memory);
}

void multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_fini_function(void * message_memory)
{
  multi_drone_msgs__msg__FleetStatus__fini(message_memory);
}

size_t multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__size_function__FleetStatus__vehicles(
  const void * untyped_member)
{
  const multi_drone_msgs__msg__VehicleStatus__Sequence * member =
    (const multi_drone_msgs__msg__VehicleStatus__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__get_const_function__FleetStatus__vehicles(
  const void * untyped_member, size_t index)
{
  const multi_drone_msgs__msg__VehicleStatus__Sequence * member =
    (const multi_drone_msgs__msg__VehicleStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__get_function__FleetStatus__vehicles(
  void * untyped_member, size_t index)
{
  multi_drone_msgs__msg__VehicleStatus__Sequence * member =
    (multi_drone_msgs__msg__VehicleStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__fetch_function__FleetStatus__vehicles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const multi_drone_msgs__msg__VehicleStatus * item =
    ((const multi_drone_msgs__msg__VehicleStatus *)
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__get_const_function__FleetStatus__vehicles(untyped_member, index));
  multi_drone_msgs__msg__VehicleStatus * value =
    (multi_drone_msgs__msg__VehicleStatus *)(untyped_value);
  *value = *item;
}

void multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__assign_function__FleetStatus__vehicles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  multi_drone_msgs__msg__VehicleStatus * item =
    ((multi_drone_msgs__msg__VehicleStatus *)
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__get_function__FleetStatus__vehicles(untyped_member, index));
  const multi_drone_msgs__msg__VehicleStatus * value =
    (const multi_drone_msgs__msg__VehicleStatus *)(untyped_value);
  *item = *value;
}

bool multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__resize_function__FleetStatus__vehicles(
  void * untyped_member, size_t size)
{
  multi_drone_msgs__msg__VehicleStatus__Sequence * member =
    (multi_drone_msgs__msg__VehicleStatus__Sequence *)(untyped_member);
  multi_drone_msgs__msg__VehicleStatus__Sequence__fini(member);
  return multi_drone_msgs__msg__VehicleStatus__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_member_array[13] = {
  {
    "fleet_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, fleet_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vehicles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, vehicles),  // bytes offset in struct
    NULL,  // default value
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__size_function__FleetStatus__vehicles,  // size() function pointer
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__get_const_function__FleetStatus__vehicles,  // get_const(index) function pointer
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__get_function__FleetStatus__vehicles,  // get(index) function pointer
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__fetch_function__FleetStatus__vehicles,  // fetch(index, &value) function pointer
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__assign_function__FleetStatus__vehicles,  // assign(index, value) function pointer
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__resize_function__FleetStatus__vehicles  // resize(index) function pointer
  },
  {
    "current_formation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, current_formation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "formation_spacing_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, formation_spacing_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "formation_heading_deg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, formation_heading_deg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_vehicles_registered",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, num_vehicles_registered),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_vehicles_connected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, num_vehicles_connected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_vehicles_armed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, num_vehicles_armed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_vehicles_airborne",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, num_vehicles_airborne),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "min_inter_vehicle_distance_m",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, min_inter_vehicle_distance_m),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "collision_warning",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, collision_warning),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mission_elapsed_s",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__msg__FleetStatus, mission_elapsed_s),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_members = {
  "multi_drone_msgs__msg",  // message namespace
  "FleetStatus",  // message name
  13,  // number of fields
  sizeof(multi_drone_msgs__msg__FleetStatus),
  false,  // has_any_key_member_
  multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_member_array,  // message members
  multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_type_support_handle = {
  0,
  &multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__msg__FleetStatus__get_type_hash,
  &multi_drone_msgs__msg__FleetStatus__get_type_description,
  &multi_drone_msgs__msg__FleetStatus__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_drone_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, msg, FleetStatus)() {
  multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, msg, VehicleStatus)();
  multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_member_array[11].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_type_support_handle.typesupport_identifier) {
    multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &multi_drone_msgs__msg__FleetStatus__rosidl_typesupport_introspection_c__FleetStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
