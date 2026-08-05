// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_drone_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/formation_command.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__BUILDER_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_drone_msgs/msg/detail/formation_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_drone_msgs
{

namespace msg
{

namespace builder
{

class Init_FormationCommand_stamp
{
public:
  explicit Init_FormationCommand_stamp(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::msg::FormationCommand stamp(::multi_drone_msgs::msg::FormationCommand::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_max_speed_ms
{
public:
  explicit Init_FormationCommand_max_speed_ms(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_stamp max_speed_ms(::multi_drone_msgs::msg::FormationCommand::_max_speed_ms_type arg)
  {
    msg_.max_speed_ms = std::move(arg);
    return Init_FormationCommand_stamp(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_target_altitude_m
{
public:
  explicit Init_FormationCommand_target_altitude_m(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_max_speed_ms target_altitude_m(::multi_drone_msgs::msg::FormationCommand::_target_altitude_m_type arg)
  {
    msg_.target_altitude_m = std::move(arg);
    return Init_FormationCommand_max_speed_ms(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_target_longitude_deg
{
public:
  explicit Init_FormationCommand_target_longitude_deg(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_target_altitude_m target_longitude_deg(::multi_drone_msgs::msg::FormationCommand::_target_longitude_deg_type arg)
  {
    msg_.target_longitude_deg = std::move(arg);
    return Init_FormationCommand_target_altitude_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_target_latitude_deg
{
public:
  explicit Init_FormationCommand_target_latitude_deg(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_target_longitude_deg target_latitude_deg(::multi_drone_msgs::msg::FormationCommand::_target_latitude_deg_type arg)
  {
    msg_.target_latitude_deg = std::move(arg);
    return Init_FormationCommand_target_longitude_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_has_target_position
{
public:
  explicit Init_FormationCommand_has_target_position(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_target_latitude_deg has_target_position(::multi_drone_msgs::msg::FormationCommand::_has_target_position_type arg)
  {
    msg_.has_target_position = std::move(arg);
    return Init_FormationCommand_target_latitude_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_leader_vehicle_id
{
public:
  explicit Init_FormationCommand_leader_vehicle_id(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_has_target_position leader_vehicle_id(::multi_drone_msgs::msg::FormationCommand::_leader_vehicle_id_type arg)
  {
    msg_.leader_vehicle_id = std::move(arg);
    return Init_FormationCommand_has_target_position(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_altitude_offset_m
{
public:
  explicit Init_FormationCommand_altitude_offset_m(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_leader_vehicle_id altitude_offset_m(::multi_drone_msgs::msg::FormationCommand::_altitude_offset_m_type arg)
  {
    msg_.altitude_offset_m = std::move(arg);
    return Init_FormationCommand_leader_vehicle_id(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_altitude_m
{
public:
  explicit Init_FormationCommand_altitude_m(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_altitude_offset_m altitude_m(::multi_drone_msgs::msg::FormationCommand::_altitude_m_type arg)
  {
    msg_.altitude_m = std::move(arg);
    return Init_FormationCommand_altitude_offset_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_heading_deg
{
public:
  explicit Init_FormationCommand_heading_deg(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_altitude_m heading_deg(::multi_drone_msgs::msg::FormationCommand::_heading_deg_type arg)
  {
    msg_.heading_deg = std::move(arg);
    return Init_FormationCommand_altitude_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_spacing_m
{
public:
  explicit Init_FormationCommand_spacing_m(::multi_drone_msgs::msg::FormationCommand & msg)
  : msg_(msg)
  {}
  Init_FormationCommand_heading_deg spacing_m(::multi_drone_msgs::msg::FormationCommand::_spacing_m_type arg)
  {
    msg_.spacing_m = std::move(arg);
    return Init_FormationCommand_heading_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

class Init_FormationCommand_pattern
{
public:
  Init_FormationCommand_pattern()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FormationCommand_spacing_m pattern(::multi_drone_msgs::msg::FormationCommand::_pattern_type arg)
  {
    msg_.pattern = std::move(arg);
    return Init_FormationCommand_spacing_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::FormationCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::msg::FormationCommand>()
{
  return multi_drone_msgs::msg::builder::Init_FormationCommand_pattern();
}

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__BUILDER_HPP_
