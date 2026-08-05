// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_drone_msgs:srv/RegisterVehicle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/srv/register_vehicle.h"


#ifndef MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__STRUCT_H_
#define MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'vehicle_namespace'
// Member 'name'
// Member 'model'
// Member 'role'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RegisterVehicle in the package multi_drone_msgs.
typedef struct multi_drone_msgs__srv__RegisterVehicle_Request
{
  /// Request
  uint8_t vehicle_id;
  rosidl_runtime_c__String vehicle_namespace;
  rosidl_runtime_c__String name;
  /// e.g., "x500"
  rosidl_runtime_c__String model;
  /// "leader" or "follower"
  rosidl_runtime_c__String role;
} multi_drone_msgs__srv__RegisterVehicle_Request;

// Struct for a sequence of multi_drone_msgs__srv__RegisterVehicle_Request.
typedef struct multi_drone_msgs__srv__RegisterVehicle_Request__Sequence
{
  multi_drone_msgs__srv__RegisterVehicle_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__srv__RegisterVehicle_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RegisterVehicle in the package multi_drone_msgs.
typedef struct multi_drone_msgs__srv__RegisterVehicle_Response
{
  bool success;
  rosidl_runtime_c__String message;
} multi_drone_msgs__srv__RegisterVehicle_Response;

// Struct for a sequence of multi_drone_msgs__srv__RegisterVehicle_Response.
typedef struct multi_drone_msgs__srv__RegisterVehicle_Response__Sequence
{
  multi_drone_msgs__srv__RegisterVehicle_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__srv__RegisterVehicle_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  multi_drone_msgs__srv__RegisterVehicle_Event__request__MAX_SIZE = 1
};
// response
enum
{
  multi_drone_msgs__srv__RegisterVehicle_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/RegisterVehicle in the package multi_drone_msgs.
typedef struct multi_drone_msgs__srv__RegisterVehicle_Event
{
  service_msgs__msg__ServiceEventInfo info;
  multi_drone_msgs__srv__RegisterVehicle_Request__Sequence request;
  multi_drone_msgs__srv__RegisterVehicle_Response__Sequence response;
} multi_drone_msgs__srv__RegisterVehicle_Event;

// Struct for a sequence of multi_drone_msgs__srv__RegisterVehicle_Event.
typedef struct multi_drone_msgs__srv__RegisterVehicle_Event__Sequence
{
  multi_drone_msgs__srv__RegisterVehicle_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__srv__RegisterVehicle_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__SRV__DETAIL__REGISTER_VEHICLE__STRUCT_H_
