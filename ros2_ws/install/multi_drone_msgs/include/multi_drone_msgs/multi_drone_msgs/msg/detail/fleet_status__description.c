// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from multi_drone_msgs:msg/FleetStatus.idl
// generated code does not contain a copyright notice

#include "multi_drone_msgs/msg/detail/fleet_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_multi_drone_msgs
const rosidl_type_hash_t *
multi_drone_msgs__msg__FleetStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9c, 0xfb, 0x93, 0x69, 0x07, 0xa9, 0xca, 0x94,
      0x57, 0xa8, 0x21, 0x2d, 0x06, 0x02, 0x3f, 0xbe,
      0xad, 0x2b, 0x92, 0xa6, 0x00, 0x47, 0x27, 0xeb,
      0xe2, 0xee, 0x9c, 0x22, 0x3f, 0x7c, 0x07, 0x4c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "multi_drone_msgs/msg/detail/vehicle_status__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t multi_drone_msgs__msg__VehicleStatus__EXPECTED_HASH = {1, {
    0x29, 0x99, 0xba, 0xdf, 0x32, 0x69, 0xb8, 0xa8,
    0x64, 0xe1, 0x0b, 0x22, 0xc9, 0xab, 0x2a, 0xd3,
    0x94, 0xfd, 0x21, 0xf3, 0x02, 0x18, 0x34, 0x69,
    0xce, 0x98, 0x5d, 0xf8, 0x86, 0xf2, 0x20, 0xd0,
  }};
#endif

static char multi_drone_msgs__msg__FleetStatus__TYPE_NAME[] = "multi_drone_msgs/msg/FleetStatus";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char multi_drone_msgs__msg__VehicleStatus__TYPE_NAME[] = "multi_drone_msgs/msg/VehicleStatus";

// Define type names, field names, and default values
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__fleet_state[] = "fleet_state";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__vehicles[] = "vehicles";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__current_formation[] = "current_formation";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__formation_spacing_m[] = "formation_spacing_m";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__formation_heading_deg[] = "formation_heading_deg";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_registered[] = "num_vehicles_registered";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_connected[] = "num_vehicles_connected";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_armed[] = "num_vehicles_armed";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_airborne[] = "num_vehicles_airborne";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__min_inter_vehicle_distance_m[] = "min_inter_vehicle_distance_m";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__collision_warning[] = "collision_warning";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__stamp[] = "stamp";
static char multi_drone_msgs__msg__FleetStatus__FIELD_NAME__mission_elapsed_s[] = "mission_elapsed_s";

static rosidl_runtime_c__type_description__Field multi_drone_msgs__msg__FleetStatus__FIELDS[] = {
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__fleet_state, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__vehicles, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {multi_drone_msgs__msg__VehicleStatus__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__current_formation, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__formation_spacing_m, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__formation_heading_deg, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_registered, 23, 23},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_connected, 22, 22},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_armed, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__num_vehicles_airborne, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__min_inter_vehicle_distance_m, 28, 28},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__collision_warning, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__FleetStatus__FIELD_NAME__mission_elapsed_s, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription multi_drone_msgs__msg__FleetStatus__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {multi_drone_msgs__msg__VehicleStatus__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
multi_drone_msgs__msg__FleetStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {multi_drone_msgs__msg__FleetStatus__TYPE_NAME, 32, 32},
      {multi_drone_msgs__msg__FleetStatus__FIELDS, 13, 13},
    },
    {multi_drone_msgs__msg__FleetStatus__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&multi_drone_msgs__msg__VehicleStatus__EXPECTED_HASH, multi_drone_msgs__msg__VehicleStatus__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = multi_drone_msgs__msg__VehicleStatus__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# ============================================================\n"
  "# FleetStatus.msg \\xe2\\x80\\x94 Aggregated fleet-wide status\n"
  "# Published by the fleet_coordinator node\n"
  "# ============================================================\n"
  "\n"
  "# Fleet state\n"
  "string fleet_state          # IDLE, FORMING, IN_FORMATION, EXECUTING, SCATTERING, RTL_ALL\n"
  "\n"
  "# Per-vehicle statuses\n"
  "multi_drone_msgs/VehicleStatus[] vehicles\n"
  "\n"
  "# Formation info\n"
  "string current_formation    # \"none\", \"line\", \"v_formation\", \"circle\", \"diamond\"\n"
  "float32 formation_spacing_m\n"
  "float32 formation_heading_deg\n"
  "\n"
  "# Fleet health\n"
  "uint8 num_vehicles_registered\n"
  "uint8 num_vehicles_connected\n"
  "uint8 num_vehicles_armed\n"
  "uint8 num_vehicles_airborne\n"
  "\n"
  "# Safety\n"
  "float32 min_inter_vehicle_distance_m\n"
  "bool collision_warning\n"
  "\n"
  "# Timing\n"
  "builtin_interfaces/Time stamp\n"
  "float64 mission_elapsed_s";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
multi_drone_msgs__msg__FleetStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {multi_drone_msgs__msg__FleetStatus__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 809, 809},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
multi_drone_msgs__msg__FleetStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *multi_drone_msgs__msg__FleetStatus__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *multi_drone_msgs__msg__VehicleStatus__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
