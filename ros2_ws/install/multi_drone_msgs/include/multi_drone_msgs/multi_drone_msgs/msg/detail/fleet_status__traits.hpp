// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/fleet_status.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__TRAITS_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_drone_msgs/msg/detail/fleet_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'vehicles'
#include "multi_drone_msgs/msg/detail/vehicle_status__traits.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace multi_drone_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FleetStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: fleet_state
  {
    out << "fleet_state: ";
    rosidl_generator_traits::value_to_yaml(msg.fleet_state, out);
    out << ", ";
  }

  // member: vehicles
  {
    if (msg.vehicles.size() == 0) {
      out << "vehicles: []";
    } else {
      out << "vehicles: [";
      size_t pending_items = msg.vehicles.size();
      for (auto item : msg.vehicles) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: current_formation
  {
    out << "current_formation: ";
    rosidl_generator_traits::value_to_yaml(msg.current_formation, out);
    out << ", ";
  }

  // member: formation_spacing_m
  {
    out << "formation_spacing_m: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_spacing_m, out);
    out << ", ";
  }

  // member: formation_heading_deg
  {
    out << "formation_heading_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_heading_deg, out);
    out << ", ";
  }

  // member: num_vehicles_registered
  {
    out << "num_vehicles_registered: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_registered, out);
    out << ", ";
  }

  // member: num_vehicles_connected
  {
    out << "num_vehicles_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_connected, out);
    out << ", ";
  }

  // member: num_vehicles_armed
  {
    out << "num_vehicles_armed: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_armed, out);
    out << ", ";
  }

  // member: num_vehicles_airborne
  {
    out << "num_vehicles_airborne: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_airborne, out);
    out << ", ";
  }

  // member: min_inter_vehicle_distance_m
  {
    out << "min_inter_vehicle_distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.min_inter_vehicle_distance_m, out);
    out << ", ";
  }

  // member: collision_warning
  {
    out << "collision_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.collision_warning, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: mission_elapsed_s
  {
    out << "mission_elapsed_s: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_elapsed_s, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FleetStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fleet_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fleet_state: ";
    rosidl_generator_traits::value_to_yaml(msg.fleet_state, out);
    out << "\n";
  }

  // member: vehicles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.vehicles.size() == 0) {
      out << "vehicles: []\n";
    } else {
      out << "vehicles:\n";
      for (auto item : msg.vehicles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: current_formation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_formation: ";
    rosidl_generator_traits::value_to_yaml(msg.current_formation, out);
    out << "\n";
  }

  // member: formation_spacing_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formation_spacing_m: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_spacing_m, out);
    out << "\n";
  }

  // member: formation_heading_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "formation_heading_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.formation_heading_deg, out);
    out << "\n";
  }

  // member: num_vehicles_registered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_vehicles_registered: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_registered, out);
    out << "\n";
  }

  // member: num_vehicles_connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_vehicles_connected: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_connected, out);
    out << "\n";
  }

  // member: num_vehicles_armed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_vehicles_armed: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_armed, out);
    out << "\n";
  }

  // member: num_vehicles_airborne
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_vehicles_airborne: ";
    rosidl_generator_traits::value_to_yaml(msg.num_vehicles_airborne, out);
    out << "\n";
  }

  // member: min_inter_vehicle_distance_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_inter_vehicle_distance_m: ";
    rosidl_generator_traits::value_to_yaml(msg.min_inter_vehicle_distance_m, out);
    out << "\n";
  }

  // member: collision_warning
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "collision_warning: ";
    rosidl_generator_traits::value_to_yaml(msg.collision_warning, out);
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

  // member: mission_elapsed_s
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_elapsed_s: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_elapsed_s, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FleetStatus & msg, bool use_flow_style = false)
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
  const multi_drone_msgs::msg::FleetStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_drone_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_drone_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const multi_drone_msgs::msg::FleetStatus & msg)
{
  return multi_drone_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<multi_drone_msgs::msg::FleetStatus>()
{
  return "multi_drone_msgs::msg::FleetStatus";
}

template<>
inline const char * name<multi_drone_msgs::msg::FleetStatus>()
{
  return "multi_drone_msgs/msg/FleetStatus";
}

template<>
struct has_fixed_size<multi_drone_msgs::msg::FleetStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_drone_msgs::msg::FleetStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_drone_msgs::msg::FleetStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__TRAITS_HPP_
