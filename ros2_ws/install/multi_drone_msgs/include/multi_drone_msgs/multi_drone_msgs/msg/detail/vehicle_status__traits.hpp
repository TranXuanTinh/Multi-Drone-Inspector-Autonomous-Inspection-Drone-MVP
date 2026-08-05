// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_drone_msgs:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/vehicle_status.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__TRAITS_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_drone_msgs/msg/detail/vehicle_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace multi_drone_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: vehicle_id
  {
    out << "vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_id, out);
    out << ", ";
  }

  // member: vehicle_namespace
  {
    out << "vehicle_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_namespace, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: latitude_deg
  {
    out << "latitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude_deg, out);
    out << ", ";
  }

  // member: longitude_deg
  {
    out << "longitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude_deg, out);
    out << ", ";
  }

  // member: absolute_altitude_m
  {
    out << "absolute_altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.absolute_altitude_m, out);
    out << ", ";
  }

  // member: relative_altitude_m
  {
    out << "relative_altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_altitude_m, out);
    out << ", ";
  }

  // member: heading_deg
  {
    out << "heading_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_deg, out);
    out << ", ";
  }

  // member: roll_deg
  {
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << ", ";
  }

  // member: pitch_deg
  {
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << ", ";
  }

  // member: yaw_deg
  {
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << ", ";
  }

  // member: groundspeed_ms
  {
    out << "groundspeed_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.groundspeed_ms, out);
    out << ", ";
  }

  // member: velocity_north_ms
  {
    out << "velocity_north_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_north_ms, out);
    out << ", ";
  }

  // member: velocity_east_ms
  {
    out << "velocity_east_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_east_ms, out);
    out << ", ";
  }

  // member: velocity_down_ms
  {
    out << "velocity_down_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_down_ms, out);
    out << ", ";
  }

  // member: battery_percent
  {
    out << "battery_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_percent, out);
    out << ", ";
  }

  // member: battery_voltage
  {
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << ", ";
  }

  // member: flight_mode
  {
    out << "flight_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.flight_mode, out);
    out << ", ";
  }

  // member: armed
  {
    out << "armed: ";
    rosidl_generator_traits::value_to_yaml(msg.armed, out);
    out << ", ";
  }

  // member: offboard_active
  {
    out << "offboard_active: ";
    rosidl_generator_traits::value_to_yaml(msg.offboard_active, out);
    out << ", ";
  }

  // member: mission_state
  {
    out << "mission_state: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_state, out);
    out << ", ";
  }

  // member: connected
  {
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
    out << ", ";
  }

  // member: gps_fix_type
  {
    out << "gps_fix_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_fix_type, out);
    out << ", ";
  }

  // member: gps_num_satellites
  {
    out << "gps_num_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_num_satellites, out);
    out << ", ";
  }

  // member: is_healthy
  {
    out << "is_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.is_healthy, out);
    out << ", ";
  }

  // member: local_x
  {
    out << "local_x: ";
    rosidl_generator_traits::value_to_yaml(msg.local_x, out);
    out << ", ";
  }

  // member: local_y
  {
    out << "local_y: ";
    rosidl_generator_traits::value_to_yaml(msg.local_y, out);
    out << ", ";
  }

  // member: local_z
  {
    out << "local_z: ";
    rosidl_generator_traits::value_to_yaml(msg.local_z, out);
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
  const VehicleStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vehicle_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_id, out);
    out << "\n";
  }

  // member: vehicle_namespace
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vehicle_namespace: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_namespace, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: latitude_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude_deg, out);
    out << "\n";
  }

  // member: longitude_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude_deg, out);
    out << "\n";
  }

  // member: absolute_altitude_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "absolute_altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.absolute_altitude_m, out);
    out << "\n";
  }

  // member: relative_altitude_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_altitude_m, out);
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

  // member: roll_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.roll_deg, out);
    out << "\n";
  }

  // member: pitch_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch_deg, out);
    out << "\n";
  }

  // member: yaw_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << "\n";
  }

  // member: groundspeed_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "groundspeed_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.groundspeed_ms, out);
    out << "\n";
  }

  // member: velocity_north_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_north_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_north_ms, out);
    out << "\n";
  }

  // member: velocity_east_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_east_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_east_ms, out);
    out << "\n";
  }

  // member: velocity_down_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity_down_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity_down_ms, out);
    out << "\n";
  }

  // member: battery_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_percent, out);
    out << "\n";
  }

  // member: battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << "\n";
  }

  // member: flight_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flight_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.flight_mode, out);
    out << "\n";
  }

  // member: armed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "armed: ";
    rosidl_generator_traits::value_to_yaml(msg.armed, out);
    out << "\n";
  }

  // member: offboard_active
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offboard_active: ";
    rosidl_generator_traits::value_to_yaml(msg.offboard_active, out);
    out << "\n";
  }

  // member: mission_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_state: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_state, out);
    out << "\n";
  }

  // member: connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connected: ";
    rosidl_generator_traits::value_to_yaml(msg.connected, out);
    out << "\n";
  }

  // member: gps_fix_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_fix_type: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_fix_type, out);
    out << "\n";
  }

  // member: gps_num_satellites
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gps_num_satellites: ";
    rosidl_generator_traits::value_to_yaml(msg.gps_num_satellites, out);
    out << "\n";
  }

  // member: is_healthy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.is_healthy, out);
    out << "\n";
  }

  // member: local_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_x: ";
    rosidl_generator_traits::value_to_yaml(msg.local_x, out);
    out << "\n";
  }

  // member: local_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_y: ";
    rosidl_generator_traits::value_to_yaml(msg.local_y, out);
    out << "\n";
  }

  // member: local_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "local_z: ";
    rosidl_generator_traits::value_to_yaml(msg.local_z, out);
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

inline std::string to_yaml(const VehicleStatus & msg, bool use_flow_style = false)
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
  const multi_drone_msgs::msg::VehicleStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_drone_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_drone_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_drone_msgs::msg::VehicleStatus & msg)
{
  return multi_drone_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_drone_msgs::msg::VehicleStatus>()
{
  return "multi_drone_msgs::msg::VehicleStatus";
}

template<>
inline const char * name<multi_drone_msgs::msg::VehicleStatus>()
{
  return "multi_drone_msgs/msg/VehicleStatus";
}

template<>
struct has_fixed_size<multi_drone_msgs::msg::VehicleStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_drone_msgs::msg::VehicleStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_drone_msgs::msg::VehicleStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__TRAITS_HPP_
