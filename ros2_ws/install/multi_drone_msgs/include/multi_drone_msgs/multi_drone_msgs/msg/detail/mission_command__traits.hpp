// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_drone_msgs:msg/MissionCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/mission_command.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__TRAITS_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_drone_msgs/msg/detail/mission_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace multi_drone_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MissionCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: target_vehicle_id
  {
    out << "target_vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_vehicle_id, out);
    out << ", ";
  }

  // member: param1
  {
    out << "param1: ";
    rosidl_generator_traits::value_to_yaml(msg.param1, out);
    out << ", ";
  }

  // member: param2
  {
    out << "param2: ";
    rosidl_generator_traits::value_to_yaml(msg.param2, out);
    out << ", ";
  }

  // member: param3
  {
    out << "param3: ";
    rosidl_generator_traits::value_to_yaml(msg.param3, out);
    out << ", ";
  }

  // member: param4
  {
    out << "param4: ";
    rosidl_generator_traits::value_to_yaml(msg.param4, out);
    out << ", ";
  }

  // member: target_latitude_deg
  {
    out << "target_latitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.target_latitude_deg, out);
    out << ", ";
  }

  // member: target_longitude_deg
  {
    out << "target_longitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.target_longitude_deg, out);
    out << ", ";
  }

  // member: target_altitude_m
  {
    out << "target_altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.target_altitude_m, out);
    out << ", ";
  }

  // member: target_yaw_deg
  {
    out << "target_yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.target_yaw_deg, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MissionCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: target_vehicle_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.target_vehicle_id, out);
    out << "\n";
  }

  // member: param1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param1: ";
    rosidl_generator_traits::value_to_yaml(msg.param1, out);
    out << "\n";
  }

  // member: param2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param2: ";
    rosidl_generator_traits::value_to_yaml(msg.param2, out);
    out << "\n";
  }

  // member: param3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param3: ";
    rosidl_generator_traits::value_to_yaml(msg.param3, out);
    out << "\n";
  }

  // member: param4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param4: ";
    rosidl_generator_traits::value_to_yaml(msg.param4, out);
    out << "\n";
  }

  // member: target_latitude_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_latitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.target_latitude_deg, out);
    out << "\n";
  }

  // member: target_longitude_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_longitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.target_longitude_deg, out);
    out << "\n";
  }

  // member: target_altitude_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.target_altitude_m, out);
    out << "\n";
  }

  // member: target_yaw_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.target_yaw_deg, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MissionCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace multi_drone_msgs

namespace rosidl_generator_traits
{

[[deprecated("use multi_drone_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_drone_msgs::msg::MissionCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_drone_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_drone_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_drone_msgs::msg::MissionCommand & msg)
{
  return multi_drone_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_drone_msgs::msg::MissionCommand>()
{
  return "multi_drone_msgs::msg::MissionCommand";
}

template<>
inline const char * name<multi_drone_msgs::msg::MissionCommand>()
{
  return "multi_drone_msgs/msg/MissionCommand";
}

template<>
struct has_fixed_size<multi_drone_msgs::msg::MissionCommand>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<multi_drone_msgs::msg::MissionCommand>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<multi_drone_msgs::msg::MissionCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__TRAITS_HPP_
