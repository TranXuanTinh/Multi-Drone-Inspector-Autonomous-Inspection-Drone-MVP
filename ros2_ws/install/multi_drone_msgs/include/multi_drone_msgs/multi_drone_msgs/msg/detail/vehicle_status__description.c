// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_drone_msgs:msg/VehicleStatus.idl
// generated code does not contain a copyright notice

#include "multi_drone_msgs/msg/detail/vehicle_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_drone_msgs
const rosidl_type_hash_t *
multi_drone_msgs__msg__VehicleStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x29, 0x99, 0xba, 0xdf, 0x32, 0x69, 0xb8, 0xa8,
      0x64, 0xe1, 0x0b, 0x22, 0xc9, 0xab, 0x2a, 0xd3,
      0x94, 0xfd, 0x21, 0xf3, 0x02, 0x18, 0x34, 0x69,
      0xce, 0x98, 0x5d, 0xf8, 0x86, 0xf2, 0x20, 0xd0,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
#endif

static char multi_drone_msgs__msg__VehicleStatus__TYPE_NAME[] = "multi_drone_msgs/msg/VehicleStatus";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";

// Define type names, field names, and default values
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__vehicle_id[] = "vehicle_id";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__vehicle_namespace[] = "vehicle_namespace";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__name[] = "name";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__latitude_deg[] = "latitude_deg";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__longitude_deg[] = "longitude_deg";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__absolute_altitude_m[] = "absolute_altitude_m";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__relative_altitude_m[] = "relative_altitude_m";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__heading_deg[] = "heading_deg";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__roll_deg[] = "roll_deg";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__pitch_deg[] = "pitch_deg";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__yaw_deg[] = "yaw_deg";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__groundspeed_ms[] = "groundspeed_ms";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__velocity_north_ms[] = "velocity_north_ms";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__velocity_east_ms[] = "velocity_east_ms";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__velocity_down_ms[] = "velocity_down_ms";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__battery_percent[] = "battery_percent";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__battery_voltage[] = "battery_voltage";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__flight_mode[] = "flight_mode";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__armed[] = "armed";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__offboard_active[] = "offboard_active";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__mission_state[] = "mission_state";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__connected[] = "connected";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__gps_fix_type[] = "gps_fix_type";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__gps_num_satellites[] = "gps_num_satellites";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__is_healthy[] = "is_healthy";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__local_x[] = "local_x";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__local_y[] = "local_y";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__local_z[] = "local_z";
static char multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__stamp[] = "stamp";

static rosidl_runtime_c__type_description__Field multi_drone_msgs__msg__VehicleStatus__FIELDS[] = {
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__vehicle_id, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__vehicle_namespace, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__latitude_deg, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__longitude_deg, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__absolute_altitude_m, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__relative_altitude_m, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__heading_deg, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__roll_deg, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__pitch_deg, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__yaw_deg, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__groundspeed_ms, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__velocity_north_ms, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__velocity_east_ms, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__velocity_down_ms, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__battery_percent, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__battery_voltage, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__flight_mode, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__armed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__offboard_active, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__mission_state, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__connected, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__gps_fix_type, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__gps_num_satellites, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__is_healthy, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__local_x, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__local_y, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__local_z, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_drone_msgs__msg__VehicleStatus__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_drone_msgs__msg__VehicleStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_drone_msgs__msg__VehicleStatus__TYPE_NAME, 34, 34},
      {multi_drone_msgs__msg__VehicleStatus__FIELDS, 29, 29},
    },
    {multi_drone_msgs__msg__VehicleStatus__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ============================================================\n"
  "# VehicleStatus.msg \\xe2\\x80\\x94 Per-vehicle telemetry and status\n"
  "# Published by each vehicle_controller node\n"
  "# ============================================================\n"
  "\n"
  "# Vehicle identity\n"
  "uint8 vehicle_id\n"
  "string vehicle_namespace\n"
  "string name\n"
  "\n"
  "# Position & attitude\n"
  "float64 latitude_deg\n"
  "float64 longitude_deg\n"
  "float32 absolute_altitude_m\n"
  "float32 relative_altitude_m\n"
  "float32 heading_deg\n"
  "float32 roll_deg\n"
  "float32 pitch_deg\n"
  "float32 yaw_deg\n"
  "\n"
  "# Velocity\n"
  "float32 groundspeed_ms\n"
  "float32 velocity_north_ms\n"
  "float32 velocity_east_ms\n"
  "float32 velocity_down_ms\n"
  "\n"
  "# Battery\n"
  "float32 battery_percent\n"
  "float32 battery_voltage\n"
  "\n"
  "# Flight state\n"
  "string flight_mode\n"
  "bool armed\n"
  "bool offboard_active\n"
  "string mission_state\n"
  "\n"
  "# Health & connectivity\n"
  "bool connected\n"
  "uint8 gps_fix_type\n"
  "uint8 gps_num_satellites\n"
  "bool is_healthy\n"
  "\n"
  "# Local position (NED frame, meters from home)\n"
  "float32 local_x\n"
  "float32 local_y\n"
  "float32 local_z\n"
  "\n"
  "# Timestamp\n"
  "builtin_interfaces/Time stamp";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_drone_msgs__msg__VehicleStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_drone_msgs__msg__VehicleStatus__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 989, 989},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_drone_msgs__msg__VehicleStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_drone_msgs__msg__VehicleStatus__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
