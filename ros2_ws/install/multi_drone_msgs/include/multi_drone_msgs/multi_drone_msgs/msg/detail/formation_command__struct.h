// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_drone_msgs:msg/FormationCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/msg/formation_command.h"


#ifndef MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_H_
#define MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'pattern'
#include "rosidl_runtime_c/string.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/FormationCommand in the package multi_drone_msgs.
/**
  * ============================================================
  * FormationCommand.msg — Command to set or change formation
  * Published by fleet_coordinator or dashboard
  * ============================================================
 */
typedef struct multi_drone_msgs__msg__FormationCommand
{
  /// Formation pattern
  /// "line", "v_formation", "circle", "diamond", "custom"
  rosidl_runtime_c__String pattern;
  /// Formation parameters
  /// Inter-vehicle distance
  float spacing_m;
  /// Formation heading direction
  float heading_deg;
  /// Formation altitude (0 = maintain current)
  float altitude_m;
  /// Per-vehicle altitude stagger
  float altitude_offset_m;
  /// Leader specification
  /// Which vehicle leads the formation
  uint8_t leader_vehicle_id;
  /// Target position for formation center (optional)
  bool has_target_position;
  double target_latitude_deg;
  double target_longitude_deg;
  float target_altitude_m;
  /// Speed
  /// Formation movement speed
  float max_speed_ms;
  /// Timestamp
  builtin_interfaces__msg__Time stamp;
} multi_drone_msgs__msg__FormationCommand;

// Struct for a sequence of multi_drone_msgs__msg__FormationCommand.
typedef struct multi_drone_msgs__msg__FormationCommand__Sequence
{
  multi_drone_msgs__msg__FormationCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_drone_msgs__msg__FormationCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_DRONE_MSGS__MSG__DETAIL__FORMATION_COMMAND__STRUCT_H_
