#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to multi_drone_msgs__srv__RegisterVehicle_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterVehicle_Request {
    /// Request
    pub vehicle_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vehicle_namespace: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,

    /// e.g., "x500"
    pub model: std::string::String,

    /// "leader" or "follower"
    pub role: std::string::String,

}



impl Default for RegisterVehicle_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RegisterVehicle_Request::default())
  }
}

impl rosidl_runtime_rs::Message for RegisterVehicle_Request {
  type RmwMsg = super::srv::rmw::RegisterVehicle_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vehicle_id: msg.vehicle_id,
        vehicle_namespace: msg.vehicle_namespace.as_str().into(),
        name: msg.name.as_str().into(),
        model: msg.model.as_str().into(),
        role: msg.role.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      vehicle_id: msg.vehicle_id,
        vehicle_namespace: msg.vehicle_namespace.as_str().into(),
        name: msg.name.as_str().into(),
        model: msg.model.as_str().into(),
        role: msg.role.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      vehicle_id: msg.vehicle_id,
      vehicle_namespace: msg.vehicle_namespace.to_string(),
      name: msg.name.to_string(),
      model: msg.model.to_string(),
      role: msg.role.to_string(),
    }
  }
}


// Corresponds to multi_drone_msgs__srv__RegisterVehicle_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterVehicle_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for RegisterVehicle_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::RegisterVehicle_Response::default())
  }
}

impl rosidl_runtime_rs::Message for RegisterVehicle_Response {
  type RmwMsg = super::srv::rmw::RegisterVehicle_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to multi_drone_msgs__srv__AssignMission_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignMission_Request {
    /// Request
    pub vehicle_id: u8,

    /// "inspection", "patrol", "hover", "goto"
    pub mission_type: std::string::String,

    /// Latitude array
    pub waypoint_lats: Vec<f64>,

    /// Longitude array
    pub waypoint_lons: Vec<f64>,

    /// Altitude array
    pub waypoint_alts: Vec<f32>,

    /// Max mission speed
    pub speed_ms: f32,

}



impl Default for AssignMission_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AssignMission_Request::default())
  }
}

impl rosidl_runtime_rs::Message for AssignMission_Request {
  type RmwMsg = super::srv::rmw::AssignMission_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vehicle_id: msg.vehicle_id,
        mission_type: msg.mission_type.as_str().into(),
        waypoint_lats: msg.waypoint_lats.into(),
        waypoint_lons: msg.waypoint_lons.into(),
        waypoint_alts: msg.waypoint_alts.into(),
        speed_ms: msg.speed_ms,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      vehicle_id: msg.vehicle_id,
        mission_type: msg.mission_type.as_str().into(),
        waypoint_lats: msg.waypoint_lats.as_slice().into(),
        waypoint_lons: msg.waypoint_lons.as_slice().into(),
        waypoint_alts: msg.waypoint_alts.as_slice().into(),
      speed_ms: msg.speed_ms,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      vehicle_id: msg.vehicle_id,
      mission_type: msg.mission_type.to_string(),
      waypoint_lats: msg.waypoint_lats
          .into_iter()
          .collect(),
      waypoint_lons: msg.waypoint_lons
          .into_iter()
          .collect(),
      waypoint_alts: msg.waypoint_alts
          .into_iter()
          .collect(),
      speed_ms: msg.speed_ms,
    }
  }
}


// Corresponds to multi_drone_msgs__srv__AssignMission_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignMission_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub num_waypoints_accepted: u32,

}



impl Default for AssignMission_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::AssignMission_Response::default())
  }
}

impl rosidl_runtime_rs::Message for AssignMission_Response {
  type RmwMsg = super::srv::rmw::AssignMission_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        num_waypoints_accepted: msg.num_waypoints_accepted,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      num_waypoints_accepted: msg.num_waypoints_accepted,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      num_waypoints_accepted: msg.num_waypoints_accepted,
    }
  }
}






#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__multi_drone_msgs__srv__RegisterVehicle() -> *const std::ffi::c_void;
}

// Corresponds to multi_drone_msgs__srv__RegisterVehicle
#[allow(missing_docs, non_camel_case_types)]
pub struct RegisterVehicle;

impl rosidl_runtime_rs::Service for RegisterVehicle {
    type Request = RegisterVehicle_Request;
    type Response = RegisterVehicle_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__multi_drone_msgs__srv__RegisterVehicle() }
    }
}




#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__multi_drone_msgs__srv__AssignMission() -> *const std::ffi::c_void;
}

// Corresponds to multi_drone_msgs__srv__AssignMission
#[allow(missing_docs, non_camel_case_types)]
pub struct AssignMission;

impl rosidl_runtime_rs::Service for AssignMission {
    type Request = AssignMission_Request;
    type Response = AssignMission_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__multi_drone_msgs__srv__AssignMission() }
    }
}


