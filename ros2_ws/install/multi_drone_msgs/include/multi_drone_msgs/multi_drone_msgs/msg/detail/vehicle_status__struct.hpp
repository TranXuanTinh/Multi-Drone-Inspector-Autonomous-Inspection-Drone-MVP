// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_drone_msgs:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/vehicle_status.hpp"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__STRUCT_HPP_
#define MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__STRUCT_HPP_

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
# define DEPRECATED__multi_drone_msgs__msg__VehicleStatus __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__msg__VehicleStatus __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleStatus_
{
  using Type = VehicleStatus_<ContainerAllocator>;

  explicit VehicleStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicle_id = 0;
      this->vehicle_namespace = "";
      this->name = "";
      this->latitude_deg = 0.0;
      this->longitude_deg = 0.0;
      this->absolute_altitude_m = 0.0f;
      this->relative_altitude_m = 0.0f;
      this->heading_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->pitch_deg = 0.0f;
      this->yaw_deg = 0.0f;
      this->groundspeed_ms = 0.0f;
      this->velocity_north_ms = 0.0f;
      this->velocity_east_ms = 0.0f;
      this->velocity_down_ms = 0.0f;
      this->battery_percent = 0.0f;
      this->battery_voltage = 0.0f;
      this->flight_mode = "";
      this->armed = false;
      this->offboard_active = false;
      this->mission_state = "";
      this->connected = false;
      this->gps_fix_type = 0;
      this->gps_num_satellites = 0;
      this->is_healthy = false;
      this->local_x = 0.0f;
      this->local_y = 0.0f;
      this->local_z = 0.0f;
    }
  }

  explicit VehicleStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vehicle_namespace(_alloc),
    name(_alloc),
    flight_mode(_alloc),
    mission_state(_alloc),
    stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicle_id = 0;
      this->vehicle_namespace = "";
      this->name = "";
      this->latitude_deg = 0.0;
      this->longitude_deg = 0.0;
      this->absolute_altitude_m = 0.0f;
      this->relative_altitude_m = 0.0f;
      this->heading_deg = 0.0f;
      this->roll_deg = 0.0f;
      this->pitch_deg = 0.0f;
      this->yaw_deg = 0.0f;
      this->groundspeed_ms = 0.0f;
      this->velocity_north_ms = 0.0f;
      this->velocity_east_ms = 0.0f;
      this->velocity_down_ms = 0.0f;
      this->battery_percent = 0.0f;
      this->battery_voltage = 0.0f;
      this->flight_mode = "";
      this->armed = false;
      this->offboard_active = false;
      this->mission_state = "";
      this->connected = false;
      this->gps_fix_type = 0;
      this->gps_num_satellites = 0;
      this->is_healthy = false;
      this->local_x = 0.0f;
      this->local_y = 0.0f;
      this->local_z = 0.0f;
    }
  }

  // field types and members
  using _vehicle_id_type =
    uint8_t;
  _vehicle_id_type vehicle_id;
  using _vehicle_namespace_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _vehicle_namespace_type vehicle_namespace;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _latitude_deg_type =
    double;
  _latitude_deg_type latitude_deg;
  using _longitude_deg_type =
    double;
  _longitude_deg_type longitude_deg;
  using _absolute_altitude_m_type =
    float;
  _absolute_altitude_m_type absolute_altitude_m;
  using _relative_altitude_m_type =
    float;
  _relative_altitude_m_type relative_altitude_m;
  using _heading_deg_type =
    float;
  _heading_deg_type heading_deg;
  using _roll_deg_type =
    float;
  _roll_deg_type roll_deg;
  using _pitch_deg_type =
    float;
  _pitch_deg_type pitch_deg;
  using _yaw_deg_type =
    float;
  _yaw_deg_type yaw_deg;
  using _groundspeed_ms_type =
    float;
  _groundspeed_ms_type groundspeed_ms;
  using _velocity_north_ms_type =
    float;
  _velocity_north_ms_type velocity_north_ms;
  using _velocity_east_ms_type =
    float;
  _velocity_east_ms_type velocity_east_ms;
  using _velocity_down_ms_type =
    float;
  _velocity_down_ms_type velocity_down_ms;
  using _battery_percent_type =
    float;
  _battery_percent_type battery_percent;
  using _battery_voltage_type =
    float;
  _battery_voltage_type battery_voltage;
  using _flight_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _flight_mode_type flight_mode;
  using _armed_type =
    bool;
  _armed_type armed;
  using _offboard_active_type =
    bool;
  _offboard_active_type offboard_active;
  using _mission_state_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mission_state_type mission_state;
  using _connected_type =
    bool;
  _connected_type connected;
  using _gps_fix_type_type =
    uint8_t;
  _gps_fix_type_type gps_fix_type;
  using _gps_num_satellites_type =
    uint8_t;
  _gps_num_satellites_type gps_num_satellites;
  using _is_healthy_type =
    bool;
  _is_healthy_type is_healthy;
  using _local_x_type =
    float;
  _local_x_type local_x;
  using _local_y_type =
    float;
  _local_y_type local_y;
  using _local_z_type =
    float;
  _local_z_type local_z;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__vehicle_id(
    const uint8_t & _arg)
  {
    this->vehicle_id = _arg;
    return *this;
  }
  Type & set__vehicle_namespace(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->vehicle_namespace = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__latitude_deg(
    const double & _arg)
  {
    this->latitude_deg = _arg;
    return *this;
  }
  Type & set__longitude_deg(
    const double & _arg)
  {
    this->longitude_deg = _arg;
    return *this;
  }
  Type & set__absolute_altitude_m(
    const float & _arg)
  {
    this->absolute_altitude_m = _arg;
    return *this;
  }
  Type & set__relative_altitude_m(
    const float & _arg)
  {
    this->relative_altitude_m = _arg;
    return *this;
  }
  Type & set__heading_deg(
    const float & _arg)
  {
    this->heading_deg = _arg;
    return *this;
  }
  Type & set__roll_deg(
    const float & _arg)
  {
    this->roll_deg = _arg;
    return *this;
  }
  Type & set__pitch_deg(
    const float & _arg)
  {
    this->pitch_deg = _arg;
    return *this;
  }
  Type & set__yaw_deg(
    const float & _arg)
  {
    this->yaw_deg = _arg;
    return *this;
  }
  Type & set__groundspeed_ms(
    const float & _arg)
  {
    this->groundspeed_ms = _arg;
    return *this;
  }
  Type & set__velocity_north_ms(
    const float & _arg)
  {
    this->velocity_north_ms = _arg;
    return *this;
  }
  Type & set__velocity_east_ms(
    const float & _arg)
  {
    this->velocity_east_ms = _arg;
    return *this;
  }
  Type & set__velocity_down_ms(
    const float & _arg)
  {
    this->velocity_down_ms = _arg;
    return *this;
  }
  Type & set__battery_percent(
    const float & _arg)
  {
    this->battery_percent = _arg;
    return *this;
  }
  Type & set__battery_voltage(
    const float & _arg)
  {
    this->battery_voltage = _arg;
    return *this;
  }
  Type & set__flight_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->flight_mode = _arg;
    return *this;
  }
  Type & set__armed(
    const bool & _arg)
  {
    this->armed = _arg;
    return *this;
  }
  Type & set__offboard_active(
    const bool & _arg)
  {
    this->offboard_active = _arg;
    return *this;
  }
  Type & set__mission_state(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mission_state = _arg;
    return *this;
  }
  Type & set__connected(
    const bool & _arg)
  {
    this->connected = _arg;
    return *this;
  }
  Type & set__gps_fix_type(
    const uint8_t & _arg)
  {
    this->gps_fix_type = _arg;
    return *this;
  }
  Type & set__gps_num_satellites(
    const uint8_t & _arg)
  {
    this->gps_num_satellites = _arg;
    return *this;
  }
  Type & set__is_healthy(
    const bool & _arg)
  {
    this->is_healthy = _arg;
    return *this;
  }
  Type & set__local_x(
    const float & _arg)
  {
    this->local_x = _arg;
    return *this;
  }
  Type & set__local_y(
    const float & _arg)
  {
    this->local_y = _arg;
    return *this;
  }
  Type & set__local_z(
    const float & _arg)
  {
    this->local_z = _arg;
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
    multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__msg__VehicleStatus
    std::shared_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__msg__VehicleStatus
    std::shared_ptr<multi_drone_msgs::msg::VehicleStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleStatus_ & other) const
  {
    if (this->vehicle_id != other.vehicle_id) {
      return false;
    }
    if (this->vehicle_namespace != other.vehicle_namespace) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->latitude_deg != other.latitude_deg) {
      return false;
    }
    if (this->longitude_deg != other.longitude_deg) {
      return false;
    }
    if (this->absolute_altitude_m != other.absolute_altitude_m) {
      return false;
    }
    if (this->relative_altitude_m != other.relative_altitude_m) {
      return false;
    }
    if (this->heading_deg != other.heading_deg) {
      return false;
    }
    if (this->roll_deg != other.roll_deg) {
      return false;
    }
    if (this->pitch_deg != other.pitch_deg) {
      return false;
    }
    if (this->yaw_deg != other.yaw_deg) {
      return false;
    }
    if (this->groundspeed_ms != other.groundspeed_ms) {
      return false;
    }
    if (this->velocity_north_ms != other.velocity_north_ms) {
      return false;
    }
    if (this->velocity_east_ms != other.velocity_east_ms) {
      return false;
    }
    if (this->velocity_down_ms != other.velocity_down_ms) {
      return false;
    }
    if (this->battery_percent != other.battery_percent) {
      return false;
    }
    if (this->battery_voltage != other.battery_voltage) {
      return false;
    }
    if (this->flight_mode != other.flight_mode) {
      return false;
    }
    if (this->armed != other.armed) {
      return false;
    }
    if (this->offboard_active != other.offboard_active) {
      return false;
    }
    if (this->mission_state != other.mission_state) {
      return false;
    }
    if (this->connected != other.connected) {
      return false;
    }
    if (this->gps_fix_type != other.gps_fix_type) {
      return false;
    }
    if (this->gps_num_satellites != other.gps_num_satellites) {
      return false;
    }
    if (this->is_healthy != other.is_healthy) {
      return false;
    }
    if (this->local_x != other.local_x) {
      return false;
    }
    if (this->local_y != other.local_y) {
      return false;
    }
    if (this->local_z != other.local_z) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleStatus_

// alias to use template instance with default allocator
using VehicleStatus =
  multi_drone_msgs::msg::VehicleStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__STRUCT_HPP_
