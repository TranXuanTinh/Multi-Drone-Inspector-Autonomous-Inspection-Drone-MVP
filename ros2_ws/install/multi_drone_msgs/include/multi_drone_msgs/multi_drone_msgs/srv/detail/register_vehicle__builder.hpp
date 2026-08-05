// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_drone_msgs:srv/RegisterVehicle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/srv/register_vehicle.hpp"


#ifndef MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__BUILDER_HPP_
#define MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_drone_msgs/srv/detail/register_vehicle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_drone_msgs
{

namespace srv
{

namespace builder
{

class Init_RegisterVehicle_Request_role
{
public:
  explicit Init_RegisterVehicle_Request_role(::multi_drone_msgs::srv::RegisterVehicle_Request & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::srv::RegisterVehicle_Request role(::multi_drone_msgs::srv::RegisterVehicle_Request::_role_type arg)
  {
    msg_.role = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Request msg_;
};

class Init_RegisterVehicle_Request_model
{
public:
  explicit Init_RegisterVehicle_Request_model(::multi_drone_msgs::srv::RegisterVehicle_Request & msg)
  : msg_(msg)
  {}
  Init_RegisterVehicle_Request_role model(::multi_drone_msgs::srv::RegisterVehicle_Request::_model_type arg)
  {
    msg_.model = std::move(arg);
    return Init_RegisterVehicle_Request_role(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Request msg_;
};

class Init_RegisterVehicle_Request_name
{
public:
  explicit Init_RegisterVehicle_Request_name(::multi_drone_msgs::srv::RegisterVehicle_Request & msg)
  : msg_(msg)
  {}
  Init_RegisterVehicle_Request_model name(::multi_drone_msgs::srv::RegisterVehicle_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_RegisterVehicle_Request_model(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Request msg_;
};

class Init_RegisterVehicle_Request_vehicle_namespace
{
public:
  explicit Init_RegisterVehicle_Request_vehicle_namespace(::multi_drone_msgs::srv::RegisterVehicle_Request & msg)
  : msg_(msg)
  {}
  Init_RegisterVehicle_Request_name vehicle_namespace(::multi_drone_msgs::srv::RegisterVehicle_Request::_vehicle_namespace_type arg)
  {
    msg_.vehicle_namespace = std::move(arg);
    return Init_RegisterVehicle_Request_name(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Request msg_;
};

class Init_RegisterVehicle_Request_vehicle_id
{
public:
  Init_RegisterVehicle_Request_vehicle_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RegisterVehicle_Request_vehicle_namespace vehicle_id(::multi_drone_msgs::srv::RegisterVehicle_Request::_vehicle_id_type arg)
  {
    msg_.vehicle_id = std::move(arg);
    return Init_RegisterVehicle_Request_vehicle_namespace(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::srv::RegisterVehicle_Request>()
{
  return multi_drone_msgs::srv::builder::Init_RegisterVehicle_Request_vehicle_id();
}

}  // namespace multi_drone_msgs


namespace multi_drone_msgs
{

namespace srv
{

namespace builder
{

class Init_RegisterVehicle_Response_message
{
public:
  explicit Init_RegisterVehicle_Response_message(::multi_drone_msgs::srv::RegisterVehicle_Response & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::srv::RegisterVehicle_Response message(::multi_drone_msgs::srv::RegisterVehicle_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Response msg_;
};

class Init_RegisterVehicle_Response_success
{
public:
  Init_RegisterVehicle_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RegisterVehicle_Response_message success(::multi_drone_msgs::srv::RegisterVehicle_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_RegisterVehicle_Response_message(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::srv::RegisterVehicle_Response>()
{
  return multi_drone_msgs::srv::builder::Init_RegisterVehicle_Response_success();
}

}  // namespace multi_drone_msgs


namespace multi_drone_msgs
{

namespace srv
{

namespace builder
{

class Init_RegisterVehicle_Event_response
{
public:
  explicit Init_RegisterVehicle_Event_response(::multi_drone_msgs::srv::RegisterVehicle_Event & msg)
  : msg_(msg)
  {}
  ::multi_drone_msgs::srv::RegisterVehicle_Event response(::multi_drone_msgs::srv::RegisterVehicle_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Event msg_;
};

class Init_RegisterVehicle_Event_request
{
public:
  explicit Init_RegisterVehicle_Event_request(::multi_drone_msgs::srv::RegisterVehicle_Event & msg)
  : msg_(msg)
  {}
  Init_RegisterVehicle_Event_response request(::multi_drone_msgs::srv::RegisterVehicle_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_RegisterVehicle_Event_response(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Event msg_;
};

class Init_RegisterVehicle_Event_info
{
public:
  Init_RegisterVehicle_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RegisterVehicle_Event_request info(::multi_drone_msgs::srv::RegisterVehicle_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_RegisterVehicle_Event_request(msg_);
  }

private:
  ::multi_drone_msgs::srv::RegisterVehicle_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_drone_msgs::srv::RegisterVehicle_Event>()
{
  return multi_drone_msgs::srv::builder::Init_RegisterVehicle_Event_info();
}

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__BUILDER_HPP_
