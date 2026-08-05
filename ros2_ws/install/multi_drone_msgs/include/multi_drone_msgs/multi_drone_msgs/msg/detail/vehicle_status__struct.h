// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_drone_msgs:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/vehicle_status.h"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__STRUCT_H_
#define MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__STRUCT_H_

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
// Member 'flight_mode'
// Member 'mission_state'
#include "rosidl_runtime_c/string.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/VehicleStatus in the package multi_drone_msgs.
/**
  * ============================================================
  * VehicleStatus.msg — Per-vehicle telemetry and status
  * Published by each vehicle_controller node
  * ============================================================
 */
typedef struct multi_drone_msgs__msg__VehicleStatus
{
  /// Vehicle identity
  uint8_t vehicle_id;
  rosidl_runtime_c__String vehicle_namespace;
  rosidl_runtime_c__String name;
  /// Position & attitude
  double latitude_deg;
  double longitude_deg;
  float absolute_altitude_m;
  float relative_altitude_m;
  float heading_deg;
  float roll_deg;
  float pitch_deg;
  float yaw_deg;
  /// Velocity
  float groundspeed_ms;
  float velocity_north_ms;
  float velocity_east_ms;
  float velocity_down_ms;
  /// Battery
  float battery_percent;
  float battery_voltage;
  /// Flight state
  rosidl_runtime_c__String flight_mode;
  bool armed;
  bool offboard_active;
  rosidl_runtime_c__String mission_state;
  /// Health & connectivity
  bool connected;
  uint8_t gps_fix_type;
  uint8_t gps_num_satellites;
  bool is_healthy;
  /// Local position (NED frame, meters from home)
  float local_x;
  float local_y;
  float local_z;
  /// Timestamp
  builtin_interfaces__msg__Time stamp;
} multi_drone_msgs__msg__VehicleStatus;

// Struct for a sequence of multi_drone_msgs__msg__VehicleStatus.
typedef struct multi_drone_msgs__msg__VehicleStatus__Sequence
{
  multi_drone_msgs__msg__VehicleStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__msg__VehicleStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__VEHICLE_STATUS__STRUCT_H_
