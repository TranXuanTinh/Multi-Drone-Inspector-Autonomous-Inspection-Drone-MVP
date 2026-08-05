// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_drone_msgs:srv/AssignMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/srv/assign_mission.h"


#ifndef MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__STRUCT_H_
#define MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mission_type'
#include "rosidl_runtime_c/string.h"
// Member 'waypoint_lats'
// Member 'waypoint_lons'
// Member 'waypoint_alts'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/AssignMission in the package multi_drone_msgs.
typedef struct multi_drone_msgs__srv__AssignMission_Request
{
  /// Request
  uint8_t vehicle_id;
  /// "inspection", "patrol", "hover", "goto"
  rosidl_runtime_c__String mission_type;
  /// Latitude array
  rosidl_runtime_c__double__Sequence waypoint_lats;
  /// Longitude array
  rosidl_runtime_c__double__Sequence waypoint_lons;
  /// Altitude array
  rosidl_runtime_c__float__Sequence waypoint_alts;
  /// Max mission speed
  float speed_ms;
} multi_drone_msgs__srv__AssignMission_Request;

// Struct for a sequence of multi_drone_msgs__srv__AssignMission_Request.
typedef struct multi_drone_msgs__srv__AssignMission_Request__Sequence
{
  multi_drone_msgs__srv__AssignMission_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__srv__AssignMission_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/AssignMission in the package multi_drone_msgs.
typedef struct multi_drone_msgs__srv__AssignMission_Response
{
  bool success;
  rosidl_runtime_c__String message;
  uint32_t num_waypoints_accepted;
} multi_drone_msgs__srv__AssignMission_Response;

// Struct for a sequence of multi_drone_msgs__srv__AssignMission_Response.
typedef struct multi_drone_msgs__srv__AssignMission_Response__Sequence
{
  multi_drone_msgs__srv__AssignMission_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__srv__AssignMission_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  multi_drone_msgs__srv__AssignMission_Event__request__MAX_SIZE = 1
};
// response
enum
{
  multi_drone_msgs__srv__AssignMission_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/AssignMission in the package multi_drone_msgs.
typedef struct multi_drone_msgs__srv__AssignMission_Event
{
  service_msgs__msg__ServiceEventInfo info;
  multi_drone_msgs__srv__AssignMission_Request__Sequence request;
  multi_drone_msgs__srv__AssignMission_Response__Sequence response;
} multi_drone_msgs__srv__AssignMission_Event;

// Struct for a sequence of multi_drone_msgs__srv__AssignMission_Event.
typedef struct multi_drone_msgs__srv__AssignMission_Event__Sequence
{
  multi_drone_msgs__srv__AssignMission_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__srv__AssignMission_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__STRUCT_H_
