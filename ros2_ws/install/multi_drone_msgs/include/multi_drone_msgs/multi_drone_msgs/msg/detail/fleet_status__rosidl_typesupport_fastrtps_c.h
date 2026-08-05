// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice
#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "multi_drone_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "multi_drone_msgs/msg/detail/fleet_status__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
bool cdr_serialize_multi_drone_msgs__msg__FleetStatus(
  const multi_drone_msgs__msg__FleetStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
bool cdr_deserialize_multi_drone_msgs__msg__FleetStatus(
  eprosima::fastcdr::Cdr &,
  multi_drone_msgs__msg__FleetStatus * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
size_t get_serialized_size_multi_drone_msgs__msg__FleetStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
size_t max_serialized_size_multi_drone_msgs__msg__FleetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
bool cdr_serialize_key_multi_drone_msgs__msg__FleetStatus(
  const multi_drone_msgs__msg__FleetStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
size_t get_serialized_size_key_multi_drone_msgs__msg__FleetStatus(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
size_t max_serialized_size_key_multi_drone_msgs__msg__FleetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_multi_drone_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, multi_drone_msgs, msg, FleetStatus)();

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
