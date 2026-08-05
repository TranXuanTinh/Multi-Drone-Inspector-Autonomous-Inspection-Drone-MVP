// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_drone_msgs:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/vehicle_status.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__BUILDER_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_drone_msgs/msg/detail/vehicle_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_drone_msgs
{

namespace msg
{

namespace builder
{

class Init_VehicleStatus_stamp
{
public:
  explicit Init_VehicleStatus_stamp(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::msg::VehicleStatus stamp(::multi_drone_msgs::msg::VehicleStatus::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_local_z
{
public:
  explicit Init_VehicleStatus_local_z(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_stamp local_z(::multi_drone_msgs::msg::VehicleStatus::_local_z_type arg)
  {
    msg_.local_z = std::move(arg);
    return Init_VehicleStatus_stamp(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_local_y
{
public:
  explicit Init_VehicleStatus_local_y(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_local_z local_y(::multi_drone_msgs::msg::VehicleStatus::_local_y_type arg)
  {
    msg_.local_y = std::move(arg);
    return Init_VehicleStatus_local_z(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_local_x
{
public:
  explicit Init_VehicleStatus_local_x(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_local_y local_x(::multi_drone_msgs::msg::VehicleStatus::_local_x_type arg)
  {
    msg_.local_x = std::move(arg);
    return Init_VehicleStatus_local_y(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_is_healthy
{
public:
  explicit Init_VehicleStatus_is_healthy(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_local_x is_healthy(::multi_drone_msgs::msg::VehicleStatus::_is_healthy_type arg)
  {
    msg_.is_healthy = std::move(arg);
    return Init_VehicleStatus_local_x(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_gps_num_satellites
{
public:
  explicit Init_VehicleStatus_gps_num_satellites(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_is_healthy gps_num_satellites(::multi_drone_msgs::msg::VehicleStatus::_gps_num_satellites_type arg)
  {
    msg_.gps_num_satellites = std::move(arg);
    return Init_VehicleStatus_is_healthy(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_gps_fix_type
{
public:
  explicit Init_VehicleStatus_gps_fix_type(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_gps_num_satellites gps_fix_type(::multi_drone_msgs::msg::VehicleStatus::_gps_fix_type_type arg)
  {
    msg_.gps_fix_type = std::move(arg);
    return Init_VehicleStatus_gps_num_satellites(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_connected
{
public:
  explicit Init_VehicleStatus_connected(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_gps_fix_type connected(::multi_drone_msgs::msg::VehicleStatus::_connected_type arg)
  {
    msg_.connected = std::move(arg);
    return Init_VehicleStatus_gps_fix_type(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_mission_state
{
public:
  explicit Init_VehicleStatus_mission_state(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_connected mission_state(::multi_drone_msgs::msg::VehicleStatus::_mission_state_type arg)
  {
    msg_.mission_state = std::move(arg);
    return Init_VehicleStatus_connected(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_offboard_active
{
public:
  explicit Init_VehicleStatus_offboard_active(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_mission_state offboard_active(::multi_drone_msgs::msg::VehicleStatus::_offboard_active_type arg)
  {
    msg_.offboard_active = std::move(arg);
    return Init_VehicleStatus_mission_state(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_armed
{
public:
  explicit Init_VehicleStatus_armed(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_offboard_active armed(::multi_drone_msgs::msg::VehicleStatus::_armed_type arg)
  {
    msg_.armed = std::move(arg);
    return Init_VehicleStatus_offboard_active(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_flight_mode
{
public:
  explicit Init_VehicleStatus_flight_mode(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_armed flight_mode(::multi_drone_msgs::msg::VehicleStatus::_flight_mode_type arg)
  {
    msg_.flight_mode = std::move(arg);
    return Init_VehicleStatus_armed(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_battery_voltage
{
public:
  explicit Init_VehicleStatus_battery_voltage(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_flight_mode battery_voltage(::multi_drone_msgs::msg::VehicleStatus::_battery_voltage_type arg)
  {
    msg_.battery_voltage = std::move(arg);
    return Init_VehicleStatus_flight_mode(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_battery_percent
{
public:
  explicit Init_VehicleStatus_battery_percent(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_battery_voltage battery_percent(::multi_drone_msgs::msg::VehicleStatus::_battery_percent_type arg)
  {
    msg_.battery_percent = std::move(arg);
    return Init_VehicleStatus_battery_voltage(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_velocity_down_ms
{
public:
  explicit Init_VehicleStatus_velocity_down_ms(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_battery_percent velocity_down_ms(::multi_drone_msgs::msg::VehicleStatus::_velocity_down_ms_type arg)
  {
    msg_.velocity_down_ms = std::move(arg);
    return Init_VehicleStatus_battery_percent(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_velocity_east_ms
{
public:
  explicit Init_VehicleStatus_velocity_east_ms(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_velocity_down_ms velocity_east_ms(::multi_drone_msgs::msg::VehicleStatus::_velocity_east_ms_type arg)
  {
    msg_.velocity_east_ms = std::move(arg);
    return Init_VehicleStatus_velocity_down_ms(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_velocity_north_ms
{
public:
  explicit Init_VehicleStatus_velocity_north_ms(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_velocity_east_ms velocity_north_ms(::multi_drone_msgs::msg::VehicleStatus::_velocity_north_ms_type arg)
  {
    msg_.velocity_north_ms = std::move(arg);
    return Init_VehicleStatus_velocity_east_ms(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_groundspeed_ms
{
public:
  explicit Init_VehicleStatus_groundspeed_ms(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_velocity_north_ms groundspeed_ms(::multi_drone_msgs::msg::VehicleStatus::_groundspeed_ms_type arg)
  {
    msg_.groundspeed_ms = std::move(arg);
    return Init_VehicleStatus_velocity_north_ms(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_yaw_deg
{
public:
  explicit Init_VehicleStatus_yaw_deg(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_groundspeed_ms yaw_deg(::multi_drone_msgs::msg::VehicleStatus::_yaw_deg_type arg)
  {
    msg_.yaw_deg = std::move(arg);
    return Init_VehicleStatus_groundspeed_ms(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_pitch_deg
{
public:
  explicit Init_VehicleStatus_pitch_deg(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_yaw_deg pitch_deg(::multi_drone_msgs::msg::VehicleStatus::_pitch_deg_type arg)
  {
    msg_.pitch_deg = std::move(arg);
    return Init_VehicleStatus_yaw_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_roll_deg
{
public:
  explicit Init_VehicleStatus_roll_deg(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_pitch_deg roll_deg(::multi_drone_msgs::msg::VehicleStatus::_roll_deg_type arg)
  {
    msg_.roll_deg = std::move(arg);
    return Init_VehicleStatus_pitch_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_heading_deg
{
public:
  explicit Init_VehicleStatus_heading_deg(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_roll_deg heading_deg(::multi_drone_msgs::msg::VehicleStatus::_heading_deg_type arg)
  {
    msg_.heading_deg = std::move(arg);
    return Init_VehicleStatus_roll_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_relative_altitude_m
{
public:
  explicit Init_VehicleStatus_relative_altitude_m(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_heading_deg relative_altitude_m(::multi_drone_msgs::msg::VehicleStatus::_relative_altitude_m_type arg)
  {
    msg_.relative_altitude_m = std::move(arg);
    return Init_VehicleStatus_heading_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_absolute_altitude_m
{
public:
  explicit Init_VehicleStatus_absolute_altitude_m(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_relative_altitude_m absolute_altitude_m(::multi_drone_msgs::msg::VehicleStatus::_absolute_altitude_m_type arg)
  {
    msg_.absolute_altitude_m = std::move(arg);
    return Init_VehicleStatus_relative_altitude_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_longitude_deg
{
public:
  explicit Init_VehicleStatus_longitude_deg(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_absolute_altitude_m longitude_deg(::multi_drone_msgs::msg::VehicleStatus::_longitude_deg_type arg)
  {
    msg_.longitude_deg = std::move(arg);
    return Init_VehicleStatus_absolute_altitude_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_latitude_deg
{
public:
  explicit Init_VehicleStatus_latitude_deg(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_longitude_deg latitude_deg(::multi_drone_msgs::msg::VehicleStatus::_latitude_deg_type arg)
  {
    msg_.latitude_deg = std::move(arg);
    return Init_VehicleStatus_longitude_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_name
{
public:
  explicit Init_VehicleStatus_name(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_latitude_deg name(::multi_drone_msgs::msg::VehicleStatus::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_VehicleStatus_latitude_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_vehicle_namespace
{
public:
  explicit Init_VehicleStatus_vehicle_namespace(::multi_drone_msgs::msg::VehicleStatus & msg)
  : msg_(msg)
  {}
  Init_VehicleStatus_name vehicle_namespace(::multi_drone_msgs::msg::VehicleStatus::_vehicle_namespace_type arg)
  {
    msg_.vehicle_namespace = std::move(arg);
    return Init_VehicleStatus_name(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

class Init_VehicleStatus_vehicle_id
{
public:
  Init_VehicleStatus_vehicle_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleStatus_vehicle_namespace vehicle_id(::multi_drone_msgs::msg::VehicleStatus::_vehicle_id_type arg)
  {
    msg_.vehicle_id = std::move(arg);
    return Init_VehicleStatus_vehicle_namespace(msg_);
  }

private:
  ::multi_drone_msgs::msg::VehicleStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::msg::VehicleStatus>()
{
  return multi_drone_msgs::msg::builder::Init_VehicleStatus_vehicle_id();
}

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__BUILDER_HPP_
