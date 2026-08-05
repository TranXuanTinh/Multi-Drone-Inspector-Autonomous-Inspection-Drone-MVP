// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from multi_drone_msgs:srv/AssignMission.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "multi_drone_msgs/srv/detail/assign_mission__rosidl_typesupport_introspection_c.h"
#include "multi_drone_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "multi_drone_msgs/srv/detail/assign_mission__functions.h"
#include "multi_drone_msgs/srv/detail/assign_mission__struct.h"


// Include directives for member types
// Member `mission_type`
#include "rosidl_runtime_c/string_functions.h"
// Member `waypoint_lats`
// Member `waypoint_lons`
// Member `waypoint_alts`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  multi_drone_msgs__srv__AssignMission_Request__init(message_memory);
}

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_fini_function(void * message_memory)
{
  multi_drone_msgs__srv__AssignMission_Request__fini(message_memory);
}

size_t multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__size_function__AssignMission_Request__waypoint_lats(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_lats(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_lats(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Request__waypoint_lats(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_lats(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__assign_function__AssignMission_Request__waypoint_lats(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_lats(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__resize_function__AssignMission_Request__waypoint_lats(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__size_function__AssignMission_Request__waypoint_lons(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_lons(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_lons(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Request__waypoint_lons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_lons(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__assign_function__AssignMission_Request__waypoint_lons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_lons(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__resize_function__AssignMission_Request__waypoint_lons(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__size_function__AssignMission_Request__waypoint_alts(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_alts(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_alts(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Request__waypoint_alts(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_alts(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__assign_function__AssignMission_Request__waypoint_alts(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_alts(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__resize_function__AssignMission_Request__waypoint_alts(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_member_array[6] = {
  {
    "vehicle_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Request, vehicle_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mission_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Request, mission_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoint_lats",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Request, waypoint_lats),  // bytes offset in struct
    NULL,  // default value
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__size_function__AssignMission_Request__waypoint_lats,  // size() function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_lats,  // get_const(index) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_lats,  // get(index) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Request__waypoint_lats,  // fetch(index, &value) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__assign_function__AssignMission_Request__waypoint_lats,  // assign(index, value) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__resize_function__AssignMission_Request__waypoint_lats  // resize(index) function pointer
  },
  {
    "waypoint_lons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Request, waypoint_lons),  // bytes offset in struct
    NULL,  // default value
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__size_function__AssignMission_Request__waypoint_lons,  // size() function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_lons,  // get_const(index) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_lons,  // get(index) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Request__waypoint_lons,  // fetch(index, &value) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__assign_function__AssignMission_Request__waypoint_lons,  // assign(index, value) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__resize_function__AssignMission_Request__waypoint_lons  // resize(index) function pointer
  },
  {
    "waypoint_alts",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Request, waypoint_alts),  // bytes offset in struct
    NULL,  // default value
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__size_function__AssignMission_Request__waypoint_alts,  // size() function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Request__waypoint_alts,  // get_const(index) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__get_function__AssignMission_Request__waypoint_alts,  // get(index) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Request__waypoint_alts,  // fetch(index, &value) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__assign_function__AssignMission_Request__waypoint_alts,  // assign(index, value) function pointer
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__resize_function__AssignMission_Request__waypoint_alts  // resize(index) function pointer
  },
  {
    "speed_ms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Request, speed_ms),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_members = {
  "multi_drone_msgs__srv",  // message namespace
  "AssignMission_Request",  // message name
  6,  // number of fields
  sizeof(multi_drone_msgs__srv__AssignMission_Request),
  false,  // has_any_key_member_
  multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_member_array,  // message members
  multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_type_support_handle = {
  0,
  &multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__srv__AssignMission_Request__get_type_hash,
  &multi_drone_msgs__srv__AssignMission_Request__get_type_description,
  &multi_drone_msgs__srv__AssignMission_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_drone_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Request)() {
  if (!multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_type_support_handle.typesupport_identifier) {
    multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "multi_drone_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__functions.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  multi_drone_msgs__srv__AssignMission_Response__init(message_memory);
}

void multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_fini_function(void * message_memory)
{
  multi_drone_msgs__srv__AssignMission_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_member_array[3] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_waypoints_accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Response, num_waypoints_accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_members = {
  "multi_drone_msgs__srv",  // message namespace
  "AssignMission_Response",  // message name
  3,  // number of fields
  sizeof(multi_drone_msgs__srv__AssignMission_Response),
  false,  // has_any_key_member_
  multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_member_array,  // message members
  multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_type_support_handle = {
  0,
  &multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__srv__AssignMission_Response__get_type_hash,
  &multi_drone_msgs__srv__AssignMission_Response__get_type_description,
  &multi_drone_msgs__srv__AssignMission_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_drone_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Response)() {
  if (!multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_type_support_handle.typesupport_identifier) {
    multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "multi_drone_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__functions.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "multi_drone_msgs/srv/assign_mission.h"
// Member `request`
// Member `response`
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  multi_drone_msgs__srv__AssignMission_Event__init(message_memory);
}

void multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_fini_function(void * message_memory)
{
  multi_drone_msgs__srv__AssignMission_Event__fini(message_memory);
}

size_t multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__size_function__AssignMission_Event__request(
  const void * untyped_member)
{
  const multi_drone_msgs__srv__AssignMission_Request__Sequence * member =
    (const multi_drone_msgs__srv__AssignMission_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Event__request(
  const void * untyped_member, size_t index)
{
  const multi_drone_msgs__srv__AssignMission_Request__Sequence * member =
    (const multi_drone_msgs__srv__AssignMission_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_function__AssignMission_Event__request(
  void * untyped_member, size_t index)
{
  multi_drone_msgs__srv__AssignMission_Request__Sequence * member =
    (multi_drone_msgs__srv__AssignMission_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const multi_drone_msgs__srv__AssignMission_Request * item =
    ((const multi_drone_msgs__srv__AssignMission_Request *)
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Event__request(untyped_member, index));
  multi_drone_msgs__srv__AssignMission_Request * value =
    (multi_drone_msgs__srv__AssignMission_Request *)(untyped_value);
  *value = *item;
}

void multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__assign_function__AssignMission_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  multi_drone_msgs__srv__AssignMission_Request * item =
    ((multi_drone_msgs__srv__AssignMission_Request *)
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_function__AssignMission_Event__request(untyped_member, index));
  const multi_drone_msgs__srv__AssignMission_Request * value =
    (const multi_drone_msgs__srv__AssignMission_Request *)(untyped_value);
  *item = *value;
}

bool multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__resize_function__AssignMission_Event__request(
  void * untyped_member, size_t size)
{
  multi_drone_msgs__srv__AssignMission_Request__Sequence * member =
    (multi_drone_msgs__srv__AssignMission_Request__Sequence *)(untyped_member);
  multi_drone_msgs__srv__AssignMission_Request__Sequence__fini(member);
  return multi_drone_msgs__srv__AssignMission_Request__Sequence__init(member, size);
}

size_t multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__size_function__AssignMission_Event__response(
  const void * untyped_member)
{
  const multi_drone_msgs__srv__AssignMission_Response__Sequence * member =
    (const multi_drone_msgs__srv__AssignMission_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Event__response(
  const void * untyped_member, size_t index)
{
  const multi_drone_msgs__srv__AssignMission_Response__Sequence * member =
    (const multi_drone_msgs__srv__AssignMission_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_function__AssignMission_Event__response(
  void * untyped_member, size_t index)
{
  multi_drone_msgs__srv__AssignMission_Response__Sequence * member =
    (multi_drone_msgs__srv__AssignMission_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const multi_drone_msgs__srv__AssignMission_Response * item =
    ((const multi_drone_msgs__srv__AssignMission_Response *)
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Event__response(untyped_member, index));
  multi_drone_msgs__srv__AssignMission_Response * value =
    (multi_drone_msgs__srv__AssignMission_Response *)(untyped_value);
  *value = *item;
}

void multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__assign_function__AssignMission_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  multi_drone_msgs__srv__AssignMission_Response * item =
    ((multi_drone_msgs__srv__AssignMission_Response *)
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_function__AssignMission_Event__response(untyped_member, index));
  const multi_drone_msgs__srv__AssignMission_Response * value =
    (const multi_drone_msgs__srv__AssignMission_Response *)(untyped_value);
  *item = *value;
}

bool multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__resize_function__AssignMission_Event__response(
  void * untyped_member, size_t size)
{
  multi_drone_msgs__srv__AssignMission_Response__Sequence * member =
    (multi_drone_msgs__srv__AssignMission_Response__Sequence *)(untyped_member);
  multi_drone_msgs__srv__AssignMission_Response__Sequence__fini(member);
  return multi_drone_msgs__srv__AssignMission_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Event, request),  // bytes offset in struct
    NULL,  // default value
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__size_function__AssignMission_Event__request,  // size() function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Event__request,  // get_const(index) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_function__AssignMission_Event__request,  // get(index) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Event__request,  // fetch(index, &value) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__assign_function__AssignMission_Event__request,  // assign(index, value) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__resize_function__AssignMission_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(multi_drone_msgs__srv__AssignMission_Event, response),  // bytes offset in struct
    NULL,  // default value
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__size_function__AssignMission_Event__response,  // size() function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_const_function__AssignMission_Event__response,  // get_const(index) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__get_function__AssignMission_Event__response,  // get(index) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__fetch_function__AssignMission_Event__response,  // fetch(index, &value) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__assign_function__AssignMission_Event__response,  // assign(index, value) function pointer
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__resize_function__AssignMission_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_members = {
  "multi_drone_msgs__srv",  // message namespace
  "AssignMission_Event",  // message name
  3,  // number of fields
  sizeof(multi_drone_msgs__srv__AssignMission_Event),
  false,  // has_any_key_member_
  multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_member_array,  // message members
  multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_type_support_handle = {
  0,
  &multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_members,
  get_message_typesupport_handle_function,
  &multi_drone_msgs__srv__AssignMission_Event__get_type_hash,
  &multi_drone_msgs__srv__AssignMission_Event__get_type_description,
  &multi_drone_msgs__srv__AssignMission_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_drone_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Event)() {
  multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Request)();
  multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Response)();
  if (!multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_type_support_handle.typesupport_identifier) {
    multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "multi_drone_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "multi_drone_msgs/srv/detail/assign_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_service_members = {
  "multi_drone_msgs__srv",  // service namespace
  "AssignMission",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_Request_message_type_support_handle,
  NULL,  // response message
  // multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_Response_message_type_support_handle
  NULL  // event_message
  // multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_Response_message_type_support_handle
};


static rosidl_service_type_support_t multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_service_type_support_handle = {
  0,
  &multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_service_members,
  get_service_typesupport_handle_function,
  &multi_drone_msgs__srv__AssignMission_Request__rosidl_typesupport_introspection_c__AssignMission_Request_message_type_support_handle,
  &multi_drone_msgs__srv__AssignMission_Response__rosidl_typesupport_introspection_c__AssignMission_Response_message_type_support_handle,
  &multi_drone_msgs__srv__AssignMission_Event__rosidl_typesupport_introspection_c__AssignMission_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    multi_drone_msgs,
    srv,
    AssignMission
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    multi_drone_msgs,
    srv,
    AssignMission
  ),
  &multi_drone_msgs__srv__AssignMission__get_type_hash,
  &multi_drone_msgs__srv__AssignMission__get_type_description,
  &multi_drone_msgs__srv__AssignMission__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_multi_drone_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission)(void) {
  if (!multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_service_type_support_handle.typesupport_identifier) {
    multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, multi_drone_msgs, srv, AssignMission_Event)()->data;
  }

  return &multi_drone_msgs__srv__detail__assign_mission__rosidl_typesupport_introspection_c__AssignMission_service_type_support_handle;
}
