// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_drone_msgs:srv/RegisterVehicle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/srv/register_vehicle.hpp"


#ifndef MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__STRUCT_HPP_
#define MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Request __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Request __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RegisterVehicle_Request_
{
  using Type = RegisterVehicle_Request_<ContainerAllocator>;

  explicit RegisterVehicle_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicle_id = 0;
      this->vehicle_namespace = "";
      this->name = "";
      this->model = "";
      this->role = "";
    }
  }

  explicit RegisterVehicle_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vehicle_namespace(_alloc),
    name(_alloc),
    model(_alloc),
    role(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vehicle_id = 0;
      this->vehicle_namespace = "";
      this->name = "";
      this->model = "";
      this->role = "";
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
  using _model_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _model_type model;
  using _role_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _role_type role;

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
  Type & set__model(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->model = _arg;
    return *this;
  }
  Type & set__role(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->role = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Request
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Request
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RegisterVehicle_Request_ & other) const
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
    if (this->model != other.model) {
      return false;
    }
    if (this->role != other.role) {
      return false;
    }
    return true;
  }
  bool operator!=(const RegisterVehicle_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RegisterVehicle_Request_

// alias to use template instance with default allocator
using RegisterVehicle_Request =
  multi_drone_msgs::srv::RegisterVehicle_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_drone_msgs


#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Response __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Response __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RegisterVehicle_Response_
{
  using Type = RegisterVehicle_Response_<ContainerAllocator>;

  explicit RegisterVehicle_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit RegisterVehicle_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

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

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Response
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Response
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RegisterVehicle_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const RegisterVehicle_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RegisterVehicle_Response_

// alias to use template instance with default allocator
using RegisterVehicle_Response =
  multi_drone_msgs::srv::RegisterVehicle_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_drone_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Event __attribute__((deprecated))
#else
# define DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Event __declspec(deprecated)
#endif

namespace multi_drone_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RegisterVehicle_Event_
{
  using Type = RegisterVehicle_Event_<ContainerAllocator>;

  explicit RegisterVehicle_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit RegisterVehicle_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::RegisterVehicle_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<multi_drone_msgs::srv::RegisterVehicle_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Event
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_drone_msgs__srv__RegisterVehicle_Event
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RegisterVehicle_Event_ & other) const
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
  bool operator!=(const RegisterVehicle_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RegisterVehicle_Event_

// alias to use template instance with default allocator
using RegisterVehicle_Event =
  multi_drone_msgs::srv::RegisterVehicle_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_drone_msgs

namespace multi_drone_msgs
{

namespace srv
{

struct RegisterVehicle
{
  using Request = multi_drone_msgs::srv::RegisterVehicle_Request;
  using Response = multi_drone_msgs::srv::RegisterVehicle_Response;
  using Event = multi_drone_msgs::srv::RegisterVehicle_Event;
};

}  // namespace srv

}  // namespace multi_drone_msgs

#endif  // MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__STRUCT_HPP_
