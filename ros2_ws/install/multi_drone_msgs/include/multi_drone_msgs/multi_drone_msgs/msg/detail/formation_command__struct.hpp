// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_drone_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/formation_command.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_HPP_

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
# define DEPRECATED__multi_drone_msgs__msg__FormationCommand __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__msg__FormationCommand __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FormationCommand_
{
  using Type = FormationCommand_<ContainerAllocator>;

  explicit FormationCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pattern = "";
      this->spacing_m = 0.0f;
      this->heading_deg = 0.0f;
      this->altitude_m = 0.0f;
      this->altitude_offset_m = 0.0f;
      this->leader_vehicle_id = 0;
      this->has_target_position = false;
      this->target_latitude_deg = 0.0;
      this->target_longitude_deg = 0.0;
      this->target_altitude_m = 0.0f;
      this->max_speed_ms = 0.0f;
    }
  }

  explicit FormationCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pattern(_alloc),
    stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pattern = "";
      this->spacing_m = 0.0f;
      this->heading_deg = 0.0f;
      this->altitude_m = 0.0f;
      this->altitude_offset_m = 0.0f;
      this->leader_vehicle_id = 0;
      this->has_target_position = false;
      this->target_latitude_deg = 0.0;
      this->target_longitude_deg = 0.0;
      this->target_altitude_m = 0.0f;
      this->max_speed_ms = 0.0f;
    }
  }

  // field types and members
  using _pattern_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _pattern_type pattern;
  using _spacing_m_type =
    float;
  _spacing_m_type spacing_m;
  using _heading_deg_type =
    float;
  _heading_deg_type heading_deg;
  using _altitude_m_type =
    float;
  _altitude_m_type altitude_m;
  using _altitude_offset_m_type =
    float;
  _altitude_offset_m_type altitude_offset_m;
  using _leader_vehicle_id_type =
    uint8_t;
  _leader_vehicle_id_type leader_vehicle_id;
  using _has_target_position_type =
    bool;
  _has_target_position_type has_target_position;
  using _target_latitude_deg_type =
    double;
  _target_latitude_deg_type target_latitude_deg;
  using _target_longitude_deg_type =
    double;
  _target_longitude_deg_type target_longitude_deg;
  using _target_altitude_m_type =
    float;
  _target_altitude_m_type target_altitude_m;
  using _max_speed_ms_type =
    float;
  _max_speed_ms_type max_speed_ms;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__pattern(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->pattern = _arg;
    return *this;
  }
  Type & set__spacing_m(
    const float & _arg)
  {
    this->spacing_m = _arg;
    return *this;
  }
  Type & set__heading_deg(
    const float & _arg)
  {
    this->heading_deg = _arg;
    return *this;
  }
  Type & set__altitude_m(
    const float & _arg)
  {
    this->altitude_m = _arg;
    return *this;
  }
  Type & set__altitude_offset_m(
    const float & _arg)
  {
    this->altitude_offset_m = _arg;
    return *this;
  }
  Type & set__leader_vehicle_id(
    const uint8_t & _arg)
  {
    this->leader_vehicle_id = _arg;
    return *this;
  }
  Type & set__has_target_position(
    const bool & _arg)
  {
    this->has_target_position = _arg;
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
  Type & set__max_speed_ms(
    const float & _arg)
  {
    this->max_speed_ms = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::msg::FormationCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::msg::FormationCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::FormationCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::FormationCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__msg__FormationCommand
    std::shared_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__msg__FormationCommand
    std::shared_ptr<multi_drone_msgs::msg::FormationCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FormationCommand_ & other) const
  {
    if (this->pattern != other.pattern) {
      return false;
    }
    if (this->spacing_m != other.spacing_m) {
      return false;
    }
    if (this->heading_deg != other.heading_deg) {
      return false;
    }
    if (this->altitude_m != other.altitude_m) {
      return false;
    }
    if (this->altitude_offset_m != other.altitude_offset_m) {
      return false;
    }
    if (this->leader_vehicle_id != other.leader_vehicle_id) {
      return false;
    }
    if (this->has_target_position != other.has_target_position) {
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
    if (this->max_speed_ms != other.max_speed_ms) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const FormationCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FormationCommand_

// alias to use template instance with default allocator
using FormationCommand =
  multi_drone_msgs::msg::FormationCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_HPP_
