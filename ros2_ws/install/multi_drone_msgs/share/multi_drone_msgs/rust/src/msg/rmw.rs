#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__VehicleStatus() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__msg__VehicleStatus__init(msg: *mut VehicleStatus) -> bool;
    fn multi_drone_msgs__msg__VehicleStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VehicleStatus>, size: usize) -> bool;
    fn multi_drone_msgs__msg__VehicleStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VehicleStatus>);
    fn multi_drone_msgs__msg__VehicleStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VehicleStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<VehicleStatus>) -> bool;
}

// Corresponds to multi_drone_msgs__msg__VehicleStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// VehicleStatus.msg — Per-vehicle telemetry and status
/// Published by each vehicle_controller node
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VehicleStatus {
    /// Vehicle identity
    pub vehicle_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vehicle_namespace: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,

    /// Position & attitude
    pub latitude_deg: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub longitude_deg: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub absolute_altitude_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub relative_altitude_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub heading_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub roll_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pitch_deg: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub yaw_deg: f32,

    /// Velocity
    pub groundspeed_ms: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity_north_ms: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity_east_ms: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity_down_ms: f32,

    /// Battery
    pub battery_percent: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub battery_voltage: f32,

    /// Flight state
    pub flight_mode: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub armed: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub offboard_active: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mission_state: rosidl_runtime_rs::String,

    /// Health & connectivity
    pub connected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gps_fix_type: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub gps_num_satellites: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_healthy: bool,

    /// Local position (NED frame, meters from home)
    pub local_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub local_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub local_z: f32,

    /// Timestamp
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for VehicleStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__msg__VehicleStatus__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__msg__VehicleStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VehicleStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__VehicleStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__VehicleStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__VehicleStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VehicleStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VehicleStatus where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/msg/VehicleStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__VehicleStatus() }
  }
}


#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__FleetStatus() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__msg__FleetStatus__init(msg: *mut FleetStatus) -> bool;
    fn multi_drone_msgs__msg__FleetStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FleetStatus>, size: usize) -> bool;
    fn multi_drone_msgs__msg__FleetStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FleetStatus>);
    fn multi_drone_msgs__msg__FleetStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FleetStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<FleetStatus>) -> bool;
}

// Corresponds to multi_drone_msgs__msg__FleetStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// FleetStatus.msg — Aggregated fleet-wide status
/// Published by the fleet_coordinator node
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FleetStatus {
    /// Fleet state
    /// IDLE, FORMING, IN_FORMATION, EXECUTING, SCATTERING, RTL_ALL
    pub fleet_state: rosidl_runtime_rs::String,

    /// Per-vehicle statuses
    pub vehicles: rosidl_runtime_rs::Sequence<super::super::msg::rmw::VehicleStatus>,

    /// Formation info
    /// "none", "line", "v_formation", "circle", "diamond"
    pub current_formation: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub formation_spacing_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub formation_heading_deg: f32,

    /// Fleet health
    pub num_vehicles_registered: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub num_vehicles_connected: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub num_vehicles_armed: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub num_vehicles_airborne: u8,

    /// Safety
    pub min_inter_vehicle_distance_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub collision_warning: bool,

    /// Timing
    pub stamp: builtin_interfaces::msg::rmw::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mission_elapsed_s: f64,

}



impl Default for FleetStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__msg__FleetStatus__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__msg__FleetStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FleetStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__FleetStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__FleetStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__FleetStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FleetStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FleetStatus where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/msg/FleetStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__FleetStatus() }
  }
}


#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__FormationCommand() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__msg__FormationCommand__init(msg: *mut FormationCommand) -> bool;
    fn multi_drone_msgs__msg__FormationCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<FormationCommand>, size: usize) -> bool;
    fn multi_drone_msgs__msg__FormationCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<FormationCommand>);
    fn multi_drone_msgs__msg__FormationCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<FormationCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<FormationCommand>) -> bool;
}

// Corresponds to multi_drone_msgs__msg__FormationCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// FormationCommand.msg — Command to set or change formation
/// Published by fleet_coordinator or dashboard
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FormationCommand {
    /// Formation pattern
    /// "line", "v_formation", "circle", "diamond", "custom"
    pub pattern: rosidl_runtime_rs::String,

    /// Formation parameters
    /// Inter-vehicle distance
    pub spacing_m: f32,

    /// Formation heading direction
    pub heading_deg: f32,

    /// Formation altitude (0 = maintain current)
    pub altitude_m: f32,

    /// Per-vehicle altitude stagger
    pub altitude_offset_m: f32,

    /// Leader specification
    /// Which vehicle leads the formation
    pub leader_vehicle_id: u8,

    /// Target position for formation center (optional)
    pub has_target_position: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_latitude_deg: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_longitude_deg: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_altitude_m: f32,

    /// Speed
    /// Formation movement speed
    pub max_speed_ms: f32,

    /// Timestamp
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for FormationCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__msg__FormationCommand__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__msg__FormationCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for FormationCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__FormationCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__FormationCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__FormationCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for FormationCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for FormationCommand where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/msg/FormationCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__FormationCommand() }
  }
}


#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__MissionCommand() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__msg__MissionCommand__init(msg: *mut MissionCommand) -> bool;
    fn multi_drone_msgs__msg__MissionCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MissionCommand>, size: usize) -> bool;
    fn multi_drone_msgs__msg__MissionCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MissionCommand>);
    fn multi_drone_msgs__msg__MissionCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MissionCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<MissionCommand>) -> bool;
}

// Corresponds to multi_drone_msgs__msg__MissionCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// ============================================================
/// MissionCommand.msg — Multi-vehicle mission command
/// Published by dashboard or mission planner
/// ============================================================

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MissionCommand {
    /// Command type
    pub command: u8,

    /// Target vehicle (255 = broadcast to all)
    pub target_vehicle_id: u8,

    /// Parameters (command-specific)
    /// e.g., takeoff altitude
    pub param1: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub param2: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub param3: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub param4: f32,

    /// GPS target (for CMD_GOTO)
    pub target_latitude_deg: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_longitude_deg: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_altitude_m: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub target_yaw_deg: f32,

    /// Timestamp
    pub stamp: builtin_interfaces::msg::rmw::Time,

}

impl MissionCommand {
    /// Command constants
    pub const CMD_TAKEOFF_ALL: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_LAND_ALL: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_RTL_ALL: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_ARM_ALL: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_DISARM_ALL: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_OFFBOARD_START: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_OFFBOARD_STOP: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_GOTO: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_HOLD_ALL: u8 = 8;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_ABORT_ALL: u8 = 9;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CMD_SINGLE_VEHICLE: u8 = 10;

}


impl Default for MissionCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__msg__MissionCommand__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__msg__MissionCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MissionCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__MissionCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__MissionCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__msg__MissionCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MissionCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MissionCommand where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/msg/MissionCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__msg__MissionCommand() }
  }
}


