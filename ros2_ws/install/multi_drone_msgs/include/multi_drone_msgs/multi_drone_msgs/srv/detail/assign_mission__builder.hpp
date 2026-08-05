// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_drone_msgs:srv/AssignMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/srv/assign_mission.hpp"


#ifndef MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__BUILDER_HPP_
#define MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_drone_msgs/srv/detail/assign_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_drone_msgs
{

namespace srv
{

namespace builder
{

class Init_AssignMission_Request_speed_ms
{
public:
  explicit Init_AssignMission_Request_speed_ms(::multi_drone_msgs::srv::AssignMission_Request & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::srv::AssignMission_Request speed_ms(::multi_drone_msgs::srv::AssignMission_Request::_speed_ms_type arg)
  {
    msg_.speed_ms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Request msg_;
};

class Init_AssignMission_Request_waypoint_alts
{
public:
  explicit Init_AssignMission_Request_waypoint_alts(::multi_drone_msgs::srv::AssignMission_Request & msg)
  : msg_(msg)
  {}
  Init_AssignMission_Request_speed_ms waypoint_alts(::multi_drone_msgs::srv::AssignMission_Request::_waypoint_alts_type arg)
  {
    msg_.waypoint_alts = std::move(arg);
    return Init_AssignMission_Request_speed_ms(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Request msg_;
};

class Init_AssignMission_Request_waypoint_lons
{
public:
  explicit Init_AssignMission_Request_waypoint_lons(::multi_drone_msgs::srv::AssignMission_Request & msg)
  : msg_(msg)
  {}
  Init_AssignMission_Request_waypoint_alts waypoint_lons(::multi_drone_msgs::srv::AssignMission_Request::_waypoint_lons_type arg)
  {
    msg_.waypoint_lons = std::move(arg);
    return Init_AssignMission_Request_waypoint_alts(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Request msg_;
};

class Init_AssignMission_Request_waypoint_lats
{
public:
  explicit Init_AssignMission_Request_waypoint_lats(::multi_drone_msgs::srv::AssignMission_Request & msg)
  : msg_(msg)
  {}
  Init_AssignMission_Request_waypoint_lons waypoint_lats(::multi_drone_msgs::srv::AssignMission_Request::_waypoint_lats_type arg)
  {
    msg_.waypoint_lats = std::move(arg);
    return Init_AssignMission_Request_waypoint_lons(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Request msg_;
};

class Init_AssignMission_Request_mission_type
{
public:
  explicit Init_AssignMission_Request_mission_type(::multi_drone_msgs::srv::AssignMission_Request & msg)
  : msg_(msg)
  {}
  Init_AssignMission_Request_waypoint_lats mission_type(::multi_drone_msgs::srv::AssignMission_Request::_mission_type_type arg)
  {
    msg_.mission_type = std::move(arg);
    return Init_AssignMission_Request_waypoint_lats(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Request msg_;
};

class Init_AssignMission_Request_vehicle_id
{
public:
  Init_AssignMission_Request_vehicle_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignMission_Request_mission_type vehicle_id(::multi_drone_msgs::srv::AssignMission_Request::_vehicle_id_type arg)
  {
    msg_.vehicle_id = std::move(arg);
    return Init_AssignMission_Request_mission_type(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::srv::AssignMission_Request>()
{
  return multi_drone_msgs::srv::builder::Init_AssignMission_Request_vehicle_id();
}

}  // namespace multi_drone_msgs


namespace multi_drone_msgs
{

namespace srv
{

namespace builder
{

class Init_AssignMission_Response_num_waypoints_accepted
{
public:
  explicit Init_AssignMission_Response_num_waypoints_accepted(::multi_drone_msgs::srv::AssignMission_Response & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::srv::AssignMission_Response num_waypoints_accepted(::multi_drone_msgs::srv::AssignMission_Response::_num_waypoints_accepted_type arg)
  {
    msg_.num_waypoints_accepted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Response msg_;
};

class Init_AssignMission_Response_message
{
public:
  explicit Init_AssignMission_Response_message(::multi_drone_msgs::srv::AssignMission_Response & msg)
  : msg_(msg)
  {}
  Init_AssignMission_Response_num_waypoints_accepted message(::multi_drone_msgs::srv::AssignMission_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_AssignMission_Response_num_waypoints_accepted(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Response msg_;
};

class Init_AssignMission_Response_success
{
public:
  Init_AssignMission_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignMission_Response_message success(::multi_drone_msgs::srv::AssignMission_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_AssignMission_Response_message(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::srv::AssignMission_Response>()
{
  return multi_drone_msgs::srv::builder::Init_AssignMission_Response_success();
}

}  // namespace multi_drone_msgs


namespace multi_drone_msgs
{

namespace srv
{

namespace builder
{

class Init_AssignMission_Event_response
{
public:
  explicit Init_AssignMission_Event_response(::multi_drone_msgs::srv::AssignMission_Event & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::srv::AssignMission_Event response(::multi_drone_msgs::srv::AssignMission_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Event msg_;
};

class Init_AssignMission_Event_request
{
public:
  explicit Init_AssignMission_Event_request(::multi_drone_msgs::srv::AssignMission_Event & msg)
  : msg_(msg)
  {}
  Init_AssignMission_Event_response request(::multi_drone_msgs::srv::AssignMission_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_AssignMission_Event_response(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Event msg_;
};

class Init_AssignMission_Event_info
{
public:
  Init_AssignMission_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AssignMission_Event_request info(::multi_drone_msgs::srv::AssignMission_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_AssignMission_Event_request(msg_);
  }

private:
  ::multi_drone_msgs::srv::AssignMission_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::srv::AssignMission_Event>()
{
  return multi_drone_msgs::srv::builder::Init_AssignMission_Event_info();
}

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__BUILDER_HPP_
