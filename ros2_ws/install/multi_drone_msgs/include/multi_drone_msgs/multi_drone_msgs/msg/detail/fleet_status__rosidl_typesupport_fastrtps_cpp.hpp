// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "multi_drone_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "multi_drone_msgs/msg/detail/fleet_status__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace multi_drone_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
cdr_serialize(
  const multi_drone_msgs::msg::FleetStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  multi_drone_msgs::msg::FleetStatus & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
get_serialized_size(
  const multi_drone_msgs::msg::FleetStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
max_serialized_size_FleetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
cdr_serialize_key(
  const multi_drone_msgs::msg::FleetStatus & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
get_serialized_size_key(
  const multi_drone_msgs::msg::FleetStatus & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
max_serialized_size_key_FleetStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace multi_drone_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_multi_drone_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, multi_drone_msgs, msg, FleetStatus)();

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
