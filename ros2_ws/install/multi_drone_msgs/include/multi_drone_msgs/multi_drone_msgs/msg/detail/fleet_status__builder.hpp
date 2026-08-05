// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/fleet_status.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__BUILDER_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_drone_msgs/msg/detail/fleet_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_drone_msgs
{

namespace msg
{

namespace builder
{

class Init_FleetStatus_mission_elapsed_s
{
public:
  explicit Init_FleetStatus_mission_elapsed_s(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::msg::FleetStatus mission_elapsed_s(::multi_drone_msgs::msg::FleetStatus::_mission_elapsed_s_type arg)
  {
    msg_.mission_elapsed_s = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_stamp
{
public:
  explicit Init_FleetStatus_stamp(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_mission_elapsed_s stamp(::multi_drone_msgs::msg::FleetStatus::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_FleetStatus_mission_elapsed_s(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_collision_warning
{
public:
  explicit Init_FleetStatus_collision_warning(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_stamp collision_warning(::multi_drone_msgs::msg::FleetStatus::_collision_warning_type arg)
  {
    msg_.collision_warning = std::move(arg);
    return Init_FleetStatus_stamp(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_min_inter_vehicle_distance_m
{
public:
  explicit Init_FleetStatus_min_inter_vehicle_distance_m(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_collision_warning min_inter_vehicle_distance_m(::multi_drone_msgs::msg::FleetStatus::_min_inter_vehicle_distance_m_type arg)
  {
    msg_.min_inter_vehicle_distance_m = std::move(arg);
    return Init_FleetStatus_collision_warning(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_num_vehicles_airborne
{
public:
  explicit Init_FleetStatus_num_vehicles_airborne(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_min_inter_vehicle_distance_m num_vehicles_airborne(::multi_drone_msgs::msg::FleetStatus::_num_vehicles_airborne_type arg)
  {
    msg_.num_vehicles_airborne = std::move(arg);
    return Init_FleetStatus_min_inter_vehicle_distance_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_num_vehicles_armed
{
public:
  explicit Init_FleetStatus_num_vehicles_armed(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_num_vehicles_airborne num_vehicles_armed(::multi_drone_msgs::msg::FleetStatus::_num_vehicles_armed_type arg)
  {
    msg_.num_vehicles_armed = std::move(arg);
    return Init_FleetStatus_num_vehicles_airborne(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_num_vehicles_connected
{
public:
  explicit Init_FleetStatus_num_vehicles_connected(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_num_vehicles_armed num_vehicles_connected(::multi_drone_msgs::msg::FleetStatus::_num_vehicles_connected_type arg)
  {
    msg_.num_vehicles_connected = std::move(arg);
    return Init_FleetStatus_num_vehicles_armed(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_num_vehicles_registered
{
public:
  explicit Init_FleetStatus_num_vehicles_registered(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_num_vehicles_connected num_vehicles_registered(::multi_drone_msgs::msg::FleetStatus::_num_vehicles_registered_type arg)
  {
    msg_.num_vehicles_registered = std::move(arg);
    return Init_FleetStatus_num_vehicles_connected(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_formation_heading_deg
{
public:
  explicit Init_FleetStatus_formation_heading_deg(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_num_vehicles_registered formation_heading_deg(::multi_drone_msgs::msg::FleetStatus::_formation_heading_deg_type arg)
  {
    msg_.formation_heading_deg = std::move(arg);
    return Init_FleetStatus_num_vehicles_registered(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_formation_spacing_m
{
public:
  explicit Init_FleetStatus_formation_spacing_m(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_formation_heading_deg formation_spacing_m(::multi_drone_msgs::msg::FleetStatus::_formation_spacing_m_type arg)
  {
    msg_.formation_spacing_m = std::move(arg);
    return Init_FleetStatus_formation_heading_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_current_formation
{
public:
  explicit Init_FleetStatus_current_formation(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_formation_spacing_m current_formation(::multi_drone_msgs::msg::FleetStatus::_current_formation_type arg)
  {
    msg_.current_formation = std::move(arg);
    return Init_FleetStatus_formation_spacing_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_vehicles
{
public:
  explicit Init_FleetStatus_vehicles(::multi_drone_msgs::msg::FleetStatus & msg)
  : msg_(msg)
  {}
  Init_FleetStatus_current_formation vehicles(::multi_drone_msgs::msg::FleetStatus::_vehicles_type arg)
  {
    msg_.vehicles = std::move(arg);
    return Init_FleetStatus_current_formation(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

class Init_FleetStatus_fleet_state
{
public:
  Init_FleetStatus_fleet_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FleetStatus_vehicles fleet_state(::multi_drone_msgs::msg::FleetStatus::_fleet_state_type arg)
  {
    msg_.fleet_state = std::move(arg);
    return Init_FleetStatus_vehicles(msg_);
  }

private:
  ::multi_drone_msgs::msg::FleetStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::msg::FleetStatus>()
{
  return multi_drone_msgs::msg::builder::Init_FleetStatus_fleet_state();
}

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__BUILDER_HPP_
