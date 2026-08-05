// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_drone_msgs:msg/MissionCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/mission_command.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__STRUCT_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__msg__MissionCommand __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__msg__MissionCommand __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MissionCommand_
{
  using Type = MissionCommand_<ContainerAllocator>;

  explicit MissionCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->target_vehicle_id = 0;
      this->param1 = 0.0f;
      this->param2 = 0.0f;
      this->param3 = 0.0f;
      this->param4 = 0.0f;
      this->target_latitude_deg = 0.0;
      this->target_longitude_deg = 0.0;
      this->target_altitude_m = 0.0f;
      this->target_yaw_deg = 0.0f;
    }
  }

  explicit MissionCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->target_vehicle_id = 0;
      this->param1 = 0.0f;
      this->param2 = 0.0f;
      this->param3 = 0.0f;
      this->param4 = 0.0f;
      this->target_latitude_deg = 0.0;
      this->target_longitude_deg = 0.0;
      this->target_altitude_m = 0.0f;
      this->target_yaw_deg = 0.0f;
    }
  }

  // field types and members
  using _command_type =
    uint8_t;
  _command_type command;
  using _target_vehicle_id_type =
    uint8_t;
  _target_vehicle_id_type target_vehicle_id;
  using _param1_type =
    float;
  _param1_type param1;
  using _param2_type =
    float;
  _param2_type param2;
  using _param3_type =
    float;
  _param3_type param3;
  using _param4_type =
    float;
  _param4_type param4;
  using _target_latitude_deg_type =
    double;
  _target_latitude_deg_type target_latitude_deg;
  using _target_longitude_deg_type =
    double;
  _target_longitude_deg_type target_longitude_deg;
  using _target_altitude_m_type =
    float;
  _target_altitude_m_type target_altitude_m;
  using _target_yaw_deg_type =
    float;
  _target_yaw_deg_type target_yaw_deg;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__command(
    const uint8_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__target_vehicle_id(
    const uint8_t & _arg)
  {
    this->target_vehicle_id = _arg;
    return *this;
  }
  Type & set__param1(
    const float & _arg)
  {
    this->param1 = _arg;
    return *this;
  }
  Type & set__param2(
    const float & _arg)
  {
    this->param2 = _arg;
    return *this;
  }
  Type & set__param3(
    const float & _arg)
  {
    this->param3 = _arg;
    return *this;
  }
  Type & set__param4(
    const float & _arg)
  {
    this->param4 = _arg;
    return *this;
  }
  Type & set__target_latitude_deg(
    const double & _arg)
  {
    this->target_latitude_deg = _arg;
    return *this;
  }
  Type & set__target_longitude_deg(
    const double & _arg)
  {
    this->target_longitude_deg = _arg;
    return *this;
  }
  Type & set__target_altitude_m(
    const float & _arg)
  {
    this->target_altitude_m = _arg;
    return *this;
  }
  Type & set__target_yaw_deg(
    const float & _arg)
  {
    this->target_yaw_deg = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CMD_TAKEOFF_ALL =
    0u;
  static constexpr uint8_t CMD_LAND_ALL =
    1u;
  static constexpr uint8_t CMD_RTL_ALL =
    2u;
  static constexpr uint8_t CMD_ARM_ALL =
    3u;
  static constexpr uint8_t CMD_DISARM_ALL =
    4u;
  static constexpr uint8_t CMD_OFFBOARD_START =
    5u;
  static constexpr uint8_t CMD_OFFBOARD_STOP =
    6u;
  static constexpr uint8_t CMD_GOTO =
    7u;
  static constexpr uint8_t CMD_HOLD_ALL =
    8u;
  static constexpr uint8_t CMD_ABORT_ALL =
    9u;
  static constexpr uint8_t CMD_SINGLE_VEHICLE =
    10u;

  // pointer types
  using RawPtr =
    multi_drone_msgs::msg::MissionCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::msg::MissionCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::MissionCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::MissionCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__msg__MissionCommand
    std::shared_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__msg__MissionCommand
    std::shared_ptr<multi_drone_msgs::msg::MissionCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MissionCommand_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->target_vehicle_id != other.target_vehicle_id) {
      return false;
    }
    if (this->param1 != other.param1) {
      return false;
    }
    if (this->param2 != other.param2) {
      return false;
    }
    if (this->param3 != other.param3) {
      return false;
    }
    if (this->param4 != other.param4) {
      return false;
    }
    if (this->target_latitude_deg != other.target_latitude_deg) {
      return false;
    }
    if (this->target_longitude_deg != other.target_longitude_deg) {
      return false;
    }
    if (this->target_altitude_m != other.target_altitude_m) {
      return false;
    }
    if (this->target_yaw_deg != other.target_yaw_deg) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const MissionCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MissionCommand_

// alias to use template instance with default allocator
using MissionCommand =
  multi_drone_msgs::msg::MissionCommand_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_TAKEOFF_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_LAND_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_RTL_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_ARM_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_DISARM_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_OFFBOARD_START;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_OFFBOARD_STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_GOTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_HOLD_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_ABORT_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MissionCommand_<ContainerAllocator>::CMD_SINGLE_VEHICLE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__MISSION_COMMAND__STRUCT_HPP_
