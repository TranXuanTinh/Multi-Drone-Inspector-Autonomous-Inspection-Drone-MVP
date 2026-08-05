// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_drone_msgs:srv/AssignMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/srv/assign_mission.hpp"


#ifndef MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__STRUCT_HPP_
#define MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__srv__AssignMission_Request __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__srv__AssignMission_Request __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignMission_Request_
{
  using Type = AssignMission_Request_<ContainerAllocator>;

  explicit AssignMission_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicle_id = 0;
      this->mission_type = "";
      this->speed_ms = 0.0f;
    }
  }

  explicit AssignMission_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mission_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicle_id = 0;
      this->mission_type = "";
      this->speed_ms = 0.0f;
    }
  }

  // field types and members
  using _vehicle_id_type =
    uint8_t;
  _vehicle_id_type vehicle_id;
  using _mission_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mission_type_type mission_type;
  using _waypoint_lats_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _waypoint_lats_type waypoint_lats;
  using _waypoint_lons_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _waypoint_lons_type waypoint_lons;
  using _waypoint_alts_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _waypoint_alts_type waypoint_alts;
  using _speed_ms_type =
    float;
  _speed_ms_type speed_ms;

  // setters for named parameter idiom
  Type & set__vehicle_id(
    const uint8_t & _arg)
  {
    this->vehicle_id = _arg;
    return *this;
  }
  Type & set__mission_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mission_type = _arg;
    return *this;
  }
  Type & set__waypoint_lats(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->waypoint_lats = _arg;
    return *this;
  }
  Type & set__waypoint_lons(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->waypoint_lons = _arg;
    return *this;
  }
  Type & set__waypoint_alts(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->waypoint_alts = _arg;
    return *this;
  }
  Type & set__speed_ms(
    const float & _arg)
  {
    this->speed_ms = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__srv__AssignMission_Request
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__srv__AssignMission_Request
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignMission_Request_ & other) const
  {
    if (this->vehicle_id != other.vehicle_id) {
      return false;
    }
    if (this->mission_type != other.mission_type) {
      return false;
    }
    if (this->waypoint_lats != other.waypoint_lats) {
      return false;
    }
    if (this->waypoint_lons != other.waypoint_lons) {
      return false;
    }
    if (this->waypoint_alts != other.waypoint_alts) {
      return false;
    }
    if (this->speed_ms != other.speed_ms) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignMission_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignMission_Request_

// alias to use template instance with default allocator
using AssignMission_Request =
  multi_drone_msgs::srv::AssignMission_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_drone_msgs


#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__srv__AssignMission_Response __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__srv__AssignMission_Response __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignMission_Response_
{
  using Type = AssignMission_Response_<ContainerAllocator>;

  explicit AssignMission_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->num_waypoints_accepted = 0ul;
    }
  }

  explicit AssignMission_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->num_waypoints_accepted = 0ul;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _num_waypoints_accepted_type =
    uint32_t;
  _num_waypoints_accepted_type num_waypoints_accepted;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__num_waypoints_accepted(
    const uint32_t & _arg)
  {
    this->num_waypoints_accepted = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__srv__AssignMission_Response
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__srv__AssignMission_Response
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignMission_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->num_waypoints_accepted != other.num_waypoints_accepted) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignMission_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignMission_Response_

// alias to use template instance with default allocator
using AssignMission_Response =
  multi_drone_msgs::srv::AssignMission_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_drone_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__srv__AssignMission_Event __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__srv__AssignMission_Event __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AssignMission_Event_
{
  using Type = AssignMission_Event_<ContainerAllocator>;

  explicit AssignMission_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit AssignMission_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::AssignMission_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::AssignMission_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__srv__AssignMission_Event
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__srv__AssignMission_Event
    std::shared_ptr<multi_drone_msgs::srv::AssignMission_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AssignMission_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const AssignMission_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AssignMission_Event_

// alias to use template instance with default allocator
using AssignMission_Event =
  multi_drone_msgs::srv::AssignMission_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_drone_msgs

namespace multi_drone_msgs
{

namespace srv
{

struct AssignMission
{
  using Request = multi_drone_msgs::srv::AssignMission_Request;
  using Response = multi_drone_msgs::srv::AssignMission_Response;
  using Event = multi_drone_msgs::srv::AssignMission_Event;
};

}  // namespace srv

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__STRUCT_HPP_
