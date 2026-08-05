// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/fleet_status.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__STRUCT_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'vehicles'
#include "multi_drone_msgs/msg/detail/vehicle_status__struct.hpp"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__msg__FleetStatus __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__msg__FleetStatus __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FleetStatus_
{
  using Type = FleetStatus_<ContainerAllocator>;

  explicit FleetStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fleet_state = "";
      this->current_formation = "";
      this->formation_spacing_m = 0.0f;
      this->formation_heading_deg = 0.0f;
      this->num_vehicles_registered = 0;
      this->num_vehicles_connected = 0;
      this->num_vehicles_armed = 0;
      this->num_vehicles_airborne = 0;
      this->min_inter_vehicle_distance_m = 0.0f;
      this->collision_warning = false;
      this->mission_elapsed_s = 0.0;
    }
  }

  explicit FleetStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fleet_state(_alloc),
    current_formation(_alloc),
    stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fleet_state = "";
      this->current_formation = "";
      this->formation_spacing_m = 0.0f;
      this->formation_heading_deg = 0.0f;
      this->num_vehicles_registered = 0;
      this->num_vehicles_connected = 0;
      this->num_vehicles_armed = 0;
      this->num_vehicles_airborne = 0;
      this->min_inter_vehicle_distance_m = 0.0f;
      this->collision_warning = false;
      this->mission_elapsed_s = 0.0;
    }
  }

  // field types and members
  using _fleet_state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _fleet_state_type fleet_state;
  using _vehicles_type =
    std::vector<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>>>;
  _vehicles_type vehicles;
  using _current_formation_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _current_formation_type current_formation;
  using _formation_spacing_m_type =
    float;
  _formation_spacing_m_type formation_spacing_m;
  using _formation_heading_deg_type =
    float;
  _formation_heading_deg_type formation_heading_deg;
  using _num_vehicles_registered_type =
    uint8_t;
  _num_vehicles_registered_type num_vehicles_registered;
  using _num_vehicles_connected_type =
    uint8_t;
  _num_vehicles_connected_type num_vehicles_connected;
  using _num_vehicles_armed_type =
    uint8_t;
  _num_vehicles_armed_type num_vehicles_armed;
  using _num_vehicles_airborne_type =
    uint8_t;
  _num_vehicles_airborne_type num_vehicles_airborne;
  using _min_inter_vehicle_distance_m_type =
    float;
  _min_inter_vehicle_distance_m_type min_inter_vehicle_distance_m;
  using _collision_warning_type =
    bool;
  _collision_warning_type collision_warning;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _mission_elapsed_s_type =
    double;
  _mission_elapsed_s_type mission_elapsed_s;

  // setters for named parameter idiom
  Type & set__fleet_state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->fleet_state = _arg;
    return *this;
  }
  Type & set__vehicles(
    const std::vector<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>>> & _arg)
  {
    this->vehicles = _arg;
    return *this;
  }
  Type & set__current_formation(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->current_formation = _arg;
    return *this;
  }
  Type & set__formation_spacing_m(
    const float & _arg)
  {
    this->formation_spacing_m = _arg;
    return *this;
  }
  Type & set__formation_heading_deg(
    const float & _arg)
  {
    this->formation_heading_deg = _arg;
    return *this;
  }
  Type & set__num_vehicles_registered(
    const uint8_t & _arg)
  {
    this->num_vehicles_registered = _arg;
    return *this;
  }
  Type & set__num_vehicles_connected(
    const uint8_t & _arg)
  {
    this->num_vehicles_connected = _arg;
    return *this;
  }
  Type & set__num_vehicles_armed(
    const uint8_t & _arg)
  {
    this->num_vehicles_armed = _arg;
    return *this;
  }
  Type & set__num_vehicles_airborne(
    const uint8_t & _arg)
  {
    this->num_vehicles_airborne = _arg;
    return *this;
  }
  Type & set__min_inter_vehicle_distance_m(
    const float & _arg)
  {
    this->min_inter_vehicle_distance_m = _arg;
    return *this;
  }
  Type & set__collision_warning(
    const bool & _arg)
  {
    this->collision_warning = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__mission_elapsed_s(
    const double & _arg)
  {
    this->mission_elapsed_s = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::msg::FleetStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::msg::FleetStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::FleetStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::FleetStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__msg__FleetStatus
    std::shared_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__msg__FleetStatus
    std::shared_ptr<multi_drone_msgs::msg::FleetStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FleetStatus_ & other) const
  {
    if (this->fleet_state != other.fleet_state) {
      return false;
    }
    if (this->vehicles != other.vehicles) {
      return false;
    }
    if (this->current_formation != other.current_formation) {
      return false;
    }
    if (this->formation_spacing_m != other.formation_spacing_m) {
      return false;
    }
    if (this->formation_heading_deg != other.formation_heading_deg) {
      return false;
    }
    if (this->num_vehicles_registered != other.num_vehicles_registered) {
      return false;
    }
    if (this->num_vehicles_connected != other.num_vehicles_connected) {
      return false;
    }
    if (this->num_vehicles_armed != other.num_vehicles_armed) {
      return false;
    }
    if (this->num_vehicles_airborne != other.num_vehicles_airborne) {
      return false;
    }
    if (this->min_inter_vehicle_distance_m != other.min_inter_vehicle_distance_m) {
      return false;
    }
    if (this->collision_warning != other.collision_warning) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->mission_elapsed_s != other.mission_elapsed_s) {
      return false;
    }
    return true;
  }
  bool operator!=(const FleetStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FleetStatus_

// alias to use template instance with default allocator
using FleetStatus =
  multi_drone_msgs::msg::FleetStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FLEET_STATUS__STRUCT_HPP_
