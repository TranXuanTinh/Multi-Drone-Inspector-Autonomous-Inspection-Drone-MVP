// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_drone_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/formation_command.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__TRAITS_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_drone_msgs/msg/detail/formation_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace multi_drone_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FormationCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: pattern
  {
    out << "pattern: ";
    rosidl_generator_traits::value_to_yaml(msg.pattern, out);
    out << ", ";
  }

  // member: spacing_m
  {
    out << "spacing_m: ";
    rosidl_generator_traits::value_to_yaml(msg.spacing_m, out);
    out << ", ";
  }

  // member: heading_deg
  {
    out << "heading_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_deg, out);
    out << ", ";
  }

  // member: altitude_m
  {
    out << "altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_m, out);
    out << ", ";
  }

  // member: altitude_offset_m
  {
    out << "altitude_offset_m: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_offset_m, out);
    out << ", ";
  }

  // member: leader_vehicle_id
  {
    out << "leader_vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.leader_vehicle_id, out);
    out << ", ";
  }

  // member: has_target_position
  {
    out << "has_target_position: ";
    rosidl_generator_traits::value_to_yaml(msg.has_target_position, out);
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

  // member: max_speed_ms
  {
    out << "max_speed_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed_ms, out);
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
  const FormationCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pattern
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pattern: ";
    rosidl_generator_traits::value_to_yaml(msg.pattern, out);
    out << "\n";
  }

  // member: spacing_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spacing_m: ";
    rosidl_generator_traits::value_to_yaml(msg.spacing_m, out);
    out << "\n";
  }

  // member: heading_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_deg, out);
    out << "\n";
  }

  // member: altitude_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_m, out);
    out << "\n";
  }

  // member: altitude_offset_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude_offset_m: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_offset_m, out);
    out << "\n";
  }

  // member: leader_vehicle_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "leader_vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.leader_vehicle_id, out);
    out << "\n";
  }

  // member: has_target_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "has_target_position: ";
    rosidl_generator_traits::value_to_yaml(msg.has_target_position, out);
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

  // member: max_speed_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_speed_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed_ms, out);
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

inline std::string to_yaml(const FormationCommand & msg, bool use_flow_style = false)
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
  const multi_drone_msgs::msg::FormationCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_drone_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_drone_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_drone_msgs::msg::FormationCommand & msg)
{
  return multi_drone_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_drone_msgs::msg::FormationCommand>()
{
  return "multi_drone_msgs::msg::FormationCommand";
}

template<>
inline const char * name<multi_drone_msgs::msg::FormationCommand>()
{
  return "multi_drone_msgs/msg/FormationCommand";
}

template<>
struct has_fixed_size<multi_drone_msgs::msg::FormationCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_drone_msgs::msg::FormationCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_drone_msgs::msg::FormationCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__TRAITS_HPP_
