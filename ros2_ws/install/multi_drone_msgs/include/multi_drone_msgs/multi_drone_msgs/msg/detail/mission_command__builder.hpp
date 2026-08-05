// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_drone_msgs:msg/MissionCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/mission_command.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__BUILDER_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_drone_msgs/msg/detail/mission_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_drone_msgs
{

namespace msg
{

namespace builder
{

class Init_MissionCommand_stamp
{
public:
  explicit Init_MissionCommand_stamp(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::msg::MissionCommand stamp(::multi_drone_msgs::msg::MissionCommand::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_target_yaw_deg
{
public:
  explicit Init_MissionCommand_target_yaw_deg(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_stamp target_yaw_deg(::multi_drone_msgs::msg::MissionCommand::_target_yaw_deg_type arg)
  {
    msg_.target_yaw_deg = std::move(arg);
    return Init_MissionCommand_stamp(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_target_altitude_m
{
public:
  explicit Init_MissionCommand_target_altitude_m(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_target_yaw_deg target_altitude_m(::multi_drone_msgs::msg::MissionCommand::_target_altitude_m_type arg)
  {
    msg_.target_altitude_m = std::move(arg);
    return Init_MissionCommand_target_yaw_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_target_longitude_deg
{
public:
  explicit Init_MissionCommand_target_longitude_deg(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_target_altitude_m target_longitude_deg(::multi_drone_msgs::msg::MissionCommand::_target_longitude_deg_type arg)
  {
    msg_.target_longitude_deg = std::move(arg);
    return Init_MissionCommand_target_altitude_m(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_target_latitude_deg
{
public:
  explicit Init_MissionCommand_target_latitude_deg(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_target_longitude_deg target_latitude_deg(::multi_drone_msgs::msg::MissionCommand::_target_latitude_deg_type arg)
  {
    msg_.target_latitude_deg = std::move(arg);
    return Init_MissionCommand_target_longitude_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_param4
{
public:
  explicit Init_MissionCommand_param4(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_target_latitude_deg param4(::multi_drone_msgs::msg::MissionCommand::_param4_type arg)
  {
    msg_.param4 = std::move(arg);
    return Init_MissionCommand_target_latitude_deg(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_param3
{
public:
  explicit Init_MissionCommand_param3(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_param4 param3(::multi_drone_msgs::msg::MissionCommand::_param3_type arg)
  {
    msg_.param3 = std::move(arg);
    return Init_MissionCommand_param4(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_param2
{
public:
  explicit Init_MissionCommand_param2(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_param3 param2(::multi_drone_msgs::msg::MissionCommand::_param2_type arg)
  {
    msg_.param2 = std::move(arg);
    return Init_MissionCommand_param3(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_param1
{
public:
  explicit Init_MissionCommand_param1(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_param2 param1(::multi_drone_msgs::msg::MissionCommand::_param1_type arg)
  {
    msg_.param1 = std::move(arg);
    return Init_MissionCommand_param2(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_target_vehicle_id
{
public:
  explicit Init_MissionCommand_target_vehicle_id(::multi_drone_msgs::msg::MissionCommand & msg)
  : msg_(msg)
  {}
  Init_MissionCommand_param1 target_vehicle_id(::multi_drone_msgs::msg::MissionCommand::_target_vehicle_id_type arg)
  {
    msg_.target_vehicle_id = std::move(arg);
    return Init_MissionCommand_param1(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

class Init_MissionCommand_command
{
public:
  Init_MissionCommand_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MissionCommand_target_vehicle_id command(::multi_drone_msgs::msg::MissionCommand::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_MissionCommand_target_vehicle_id(msg_);
  }

private:
  ::multi_drone_msgs::msg::MissionCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::msg::MissionCommand>()
{
  return multi_drone_msgs::msg::builder::Init_MissionCommand_command();
}

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__BUILDER_HPP_
