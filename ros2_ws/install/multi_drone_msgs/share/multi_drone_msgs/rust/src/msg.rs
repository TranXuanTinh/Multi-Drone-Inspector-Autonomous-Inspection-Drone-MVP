#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to multi_drone_msgs__msg__VehicleStatus
/// ============================================================
/// VehicleStatus.msg — Per-vehicle telemetry and status
/// Published by each vehicle_controller node
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VehicleStatus {
    /// Vehicle identity
    pub vehicle_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vehicle_namespace: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,

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
    pub flight_mode: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub armed: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub offboard_active: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mission_state: std::string::String,

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
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for VehicleStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::VehicleStatus::default())
  }
}

impl rosidl_runtime_rs::Message for VehicleStatus {
  type RmwMsg = super::msg::rmw::VehicleStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vehicle_id: msg.vehicle_id,
        vehicle_namespace: msg.vehicle_namespace.as_str().into(),
        name: msg.name.as_str().into(),
        latitude_deg: msg.latitude_deg,
        longitude_deg: msg.longitude_deg,
        absolute_altitude_m: msg.absolute_altitude_m,
        relative_altitude_m: msg.relative_altitude_m,
        heading_deg: msg.heading_deg,
        roll_deg: msg.roll_deg,
        pitch_deg: msg.pitch_deg,
        yaw_deg: msg.yaw_deg,
        groundspeed_ms: msg.groundspeed_ms,
        velocity_north_ms: msg.velocity_north_ms,
        velocity_east_ms: msg.velocity_east_ms,
        velocity_down_ms: msg.velocity_down_ms,
        battery_percent: msg.battery_percent,
        battery_voltage: msg.battery_voltage,
        flight_mode: msg.flight_mode.as_str().into(),
        armed: msg.armed,
        offboard_active: msg.offboard_active,
        mission_state: msg.mission_state.as_str().into(),
        connected: msg.connected,
        gps_fix_type: msg.gps_fix_type,
        gps_num_satellites: msg.gps_num_satellites,
        is_healthy: msg.is_healthy,
        local_x: msg.local_x,
        local_y: msg.local_y,
        local_z: msg.local_z,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      vehicle_id: msg.vehicle_id,
        vehicle_namespace: msg.vehicle_namespace.as_str().into(),
        name: msg.name.as_str().into(),
      latitude_deg: msg.latitude_deg,
      longitude_deg: msg.longitude_deg,
      absolute_altitude_m: msg.absolute_altitude_m,
      relative_altitude_m: msg.relative_altitude_m,
      heading_deg: msg.heading_deg,
      roll_deg: msg.roll_deg,
      pitch_deg: msg.pitch_deg,
      yaw_deg: msg.yaw_deg,
      groundspeed_ms: msg.groundspeed_ms,
      velocity_north_ms: msg.velocity_north_ms,
      velocity_east_ms: msg.velocity_east_ms,
      velocity_down_ms: msg.velocity_down_ms,
      battery_percent: msg.battery_percent,
      battery_voltage: msg.battery_voltage,
        flight_mode: msg.flight_mode.as_str().into(),
      armed: msg.armed,
      offboard_active: msg.offboard_active,
        mission_state: msg.mission_state.as_str().into(),
      connected: msg.connected,
      gps_fix_type: msg.gps_fix_type,
      gps_num_satellites: msg.gps_num_satellites,
      is_healthy: msg.is_healthy,
      local_x: msg.local_x,
      local_y: msg.local_y,
      local_z: msg.local_z,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      vehicle_id: msg.vehicle_id,
      vehicle_namespace: msg.vehicle_namespace.to_string(),
      name: msg.name.to_string(),
      latitude_deg: msg.latitude_deg,
      longitude_deg: msg.longitude_deg,
      absolute_altitude_m: msg.absolute_altitude_m,
      relative_altitude_m: msg.relative_altitude_m,
      heading_deg: msg.heading_deg,
      roll_deg: msg.roll_deg,
      pitch_deg: msg.pitch_deg,
      yaw_deg: msg.yaw_deg,
      groundspeed_ms: msg.groundspeed_ms,
      velocity_north_ms: msg.velocity_north_ms,
      velocity_east_ms: msg.velocity_east_ms,
      velocity_down_ms: msg.velocity_down_ms,
      battery_percent: msg.battery_percent,
      battery_voltage: msg.battery_voltage,
      flight_mode: msg.flight_mode.to_string(),
      armed: msg.armed,
      offboard_active: msg.offboard_active,
      mission_state: msg.mission_state.to_string(),
      connected: msg.connected,
      gps_fix_type: msg.gps_fix_type,
      gps_num_satellites: msg.gps_num_satellites,
      is_healthy: msg.is_healthy,
      local_x: msg.local_x,
      local_y: msg.local_y,
      local_z: msg.local_z,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to multi_drone_msgs__msg__FleetStatus
/// ============================================================
/// FleetStatus.msg — Aggregated fleet-wide status
/// Published by the fleet_coordinator node
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FleetStatus {
    /// Fleet state
    /// IDLE, FORMING, IN_FORMATION, EXECUTING, SCATTERING, RTL_ALL
    pub fleet_state: std::string::String,

    /// Per-vehicle statuses
    pub vehicles: Vec<super::msg::VehicleStatus>,

    /// Formation info
    /// "none", "line", "v_formation", "circle", "diamond"
    pub current_formation: std::string::String,


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
    pub stamp: builtin_interfaces::msg::Time,


    // This member is not documented.
    #[allow(missing_docs)]
    pub mission_elapsed_s: f64,

}



impl Default for FleetStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FleetStatus::default())
  }
}

impl rosidl_runtime_rs::Message for FleetStatus {
  type RmwMsg = super::msg::rmw::FleetStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        fleet_state: msg.fleet_state.as_str().into(),
        vehicles: msg.vehicles
          .into_iter()
          .map(|elem| super::msg::VehicleStatus::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        current_formation: msg.current_formation.as_str().into(),
        formation_spacing_m: msg.formation_spacing_m,
        formation_heading_deg: msg.formation_heading_deg,
        num_vehicles_registered: msg.num_vehicles_registered,
        num_vehicles_connected: msg.num_vehicles_connected,
        num_vehicles_armed: msg.num_vehicles_armed,
        num_vehicles_airborne: msg.num_vehicles_airborne,
        min_inter_vehicle_distance_m: msg.min_inter_vehicle_distance_m,
        collision_warning: msg.collision_warning,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        mission_elapsed_s: msg.mission_elapsed_s,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        fleet_state: msg.fleet_state.as_str().into(),
        vehicles: msg.vehicles
          .iter()
          .map(|elem| super::msg::VehicleStatus::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        current_formation: msg.current_formation.as_str().into(),
      formation_spacing_m: msg.formation_spacing_m,
      formation_heading_deg: msg.formation_heading_deg,
      num_vehicles_registered: msg.num_vehicles_registered,
      num_vehicles_connected: msg.num_vehicles_connected,
      num_vehicles_armed: msg.num_vehicles_armed,
      num_vehicles_airborne: msg.num_vehicles_airborne,
      min_inter_vehicle_distance_m: msg.min_inter_vehicle_distance_m,
      collision_warning: msg.collision_warning,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      mission_elapsed_s: msg.mission_elapsed_s,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      fleet_state: msg.fleet_state.to_string(),
      vehicles: msg.vehicles
          .into_iter()
          .map(super::msg::VehicleStatus::from_rmw_message)
          .collect(),
      current_formation: msg.current_formation.to_string(),
      formation_spacing_m: msg.formation_spacing_m,
      formation_heading_deg: msg.formation_heading_deg,
      num_vehicles_registered: msg.num_vehicles_registered,
      num_vehicles_connected: msg.num_vehicles_connected,
      num_vehicles_armed: msg.num_vehicles_armed,
      num_vehicles_airborne: msg.num_vehicles_airborne,
      min_inter_vehicle_distance_m: msg.min_inter_vehicle_distance_m,
      collision_warning: msg.collision_warning,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      mission_elapsed_s: msg.mission_elapsed_s,
    }
  }
}


// Corresponds to multi_drone_msgs__msg__FormationCommand
/// ============================================================
/// FormationCommand.msg — Command to set or change formation
/// Published by fleet_coordinator or dashboard
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct FormationCommand {
    /// Formation pattern
    /// "line", "v_formation", "circle", "diamond", "custom"
    pub pattern: std::string::String,

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
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for FormationCommand {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::FormationCommand::default())
  }
}

impl rosidl_runtime_rs::Message for FormationCommand {
  type RmwMsg = super::msg::rmw::FormationCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pattern: msg.pattern.as_str().into(),
        spacing_m: msg.spacing_m,
        heading_deg: msg.heading_deg,
        altitude_m: msg.altitude_m,
        altitude_offset_m: msg.altitude_offset_m,
        leader_vehicle_id: msg.leader_vehicle_id,
        has_target_position: msg.has_target_position,
        target_latitude_deg: msg.target_latitude_deg,
        target_longitude_deg: msg.target_longitude_deg,
        target_altitude_m: msg.target_altitude_m,
        max_speed_ms: msg.max_speed_ms,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pattern: msg.pattern.as_str().into(),
      spacing_m: msg.spacing_m,
      heading_deg: msg.heading_deg,
      altitude_m: msg.altitude_m,
      altitude_offset_m: msg.altitude_offset_m,
      leader_vehicle_id: msg.leader_vehicle_id,
      has_target_position: msg.has_target_position,
      target_latitude_deg: msg.target_latitude_deg,
      target_longitude_deg: msg.target_longitude_deg,
      target_altitude_m: msg.target_altitude_m,
      max_speed_ms: msg.max_speed_ms,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pattern: msg.pattern.to_string(),
      spacing_m: msg.spacing_m,
      heading_deg: msg.heading_deg,
      altitude_m: msg.altitude_m,
      altitude_offset_m: msg.altitude_offset_m,
      leader_vehicle_id: msg.leader_vehicle_id,
      has_target_position: msg.has_target_position,
      target_latitude_deg: msg.target_latitude_deg,
      target_longitude_deg: msg.target_longitude_deg,
      target_altitude_m: msg.target_altitude_m,
      max_speed_ms: msg.max_speed_ms,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to multi_drone_msgs__msg__MissionCommand
/// ============================================================
/// MissionCommand.msg — Multi-vehicle mission command
/// Published by dashboard or mission planner
/// ============================================================

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub stamp: builtin_interfaces::msg::Time,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MissionCommand::default())
  }
}

impl rosidl_runtime_rs::Message for MissionCommand {
  type RmwMsg = super::msg::rmw::MissionCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command,
        target_vehicle_id: msg.target_vehicle_id,
        param1: msg.param1,
        param2: msg.param2,
        param3: msg.param3,
        param4: msg.param4,
        target_latitude_deg: msg.target_latitude_deg,
        target_longitude_deg: msg.target_longitude_deg,
        target_altitude_m: msg.target_altitude_m,
        target_yaw_deg: msg.target_yaw_deg,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      command: msg.command,
      target_vehicle_id: msg.target_vehicle_id,
      param1: msg.param1,
      param2: msg.param2,
      param3: msg.param3,
      param4: msg.param4,
      target_latitude_deg: msg.target_latitude_deg,
      target_longitude_deg: msg.target_longitude_deg,
      target_altitude_m: msg.target_altitude_m,
      target_yaw_deg: msg.target_yaw_deg,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      command: msg.command,
      target_vehicle_id: msg.target_vehicle_id,
      param1: msg.param1,
      param2: msg.param2,
      param3: msg.param3,
      param4: msg.param4,
      target_latitude_deg: msg.target_latitude_deg,
      target_longitude_deg: msg.target_longitude_deg,
      target_altitude_m: msg.target_altitude_m,
      target_yaw_deg: msg.target_yaw_deg,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


