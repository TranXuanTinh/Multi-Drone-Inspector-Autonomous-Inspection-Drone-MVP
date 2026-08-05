#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__RegisterVehicle_Request() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__srv__RegisterVehicle_Request__init(msg: *mut RegisterVehicle_Request) -> bool;
    fn multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RegisterVehicle_Request>, size: usize) -> bool;
    fn multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RegisterVehicle_Request>);
    fn multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RegisterVehicle_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<RegisterVehicle_Request>) -> bool;
}

// Corresponds to multi_drone_msgs__srv__RegisterVehicle_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterVehicle_Request {
    /// Request
    pub vehicle_id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vehicle_namespace: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,

    /// e.g., "x500"
    pub model: rosidl_runtime_rs::String,

    /// "leader" or "follower"
    pub role: rosidl_runtime_rs::String,

}



impl Default for RegisterVehicle_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__srv__RegisterVehicle_Request__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__srv__RegisterVehicle_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RegisterVehicle_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__RegisterVehicle_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RegisterVehicle_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RegisterVehicle_Request where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/srv/RegisterVehicle_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__RegisterVehicle_Request() }
  }
}


#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__RegisterVehicle_Response() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__srv__RegisterVehicle_Response__init(msg: *mut RegisterVehicle_Response) -> bool;
    fn multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RegisterVehicle_Response>, size: usize) -> bool;
    fn multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RegisterVehicle_Response>);
    fn multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RegisterVehicle_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<RegisterVehicle_Response>) -> bool;
}

// Corresponds to multi_drone_msgs__srv__RegisterVehicle_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RegisterVehicle_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for RegisterVehicle_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__srv__RegisterVehicle_Response__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__srv__RegisterVehicle_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RegisterVehicle_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__RegisterVehicle_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RegisterVehicle_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RegisterVehicle_Response where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/srv/RegisterVehicle_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__RegisterVehicle_Response() }
  }
}


#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__AssignMission_Request() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__srv__AssignMission_Request__init(msg: *mut AssignMission_Request) -> bool;
    fn multi_drone_msgs__srv__AssignMission_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AssignMission_Request>, size: usize) -> bool;
    fn multi_drone_msgs__srv__AssignMission_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AssignMission_Request>);
    fn multi_drone_msgs__srv__AssignMission_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AssignMission_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<AssignMission_Request>) -> bool;
}

// Corresponds to multi_drone_msgs__srv__AssignMission_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignMission_Request {
    /// Request
    pub vehicle_id: u8,

    /// "inspection", "patrol", "hover", "goto"
    pub mission_type: rosidl_runtime_rs::String,

    /// Latitude array
    pub waypoint_lats: rosidl_runtime_rs::Sequence<f64>,

    /// Longitude array
    pub waypoint_lons: rosidl_runtime_rs::Sequence<f64>,

    /// Altitude array
    pub waypoint_alts: rosidl_runtime_rs::Sequence<f32>,

    /// Max mission speed
    pub speed_ms: f32,

}



impl Default for AssignMission_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__srv__AssignMission_Request__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__srv__AssignMission_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AssignMission_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__AssignMission_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__AssignMission_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__AssignMission_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AssignMission_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AssignMission_Request where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/srv/AssignMission_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__AssignMission_Request() }
  }
}


#[link(name = "multi_drone_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__AssignMission_Response() -> *const std::ffi::c_void;
}

#[link(name = "multi_drone_msgs__rosidl_generator_c")]
extern "C" {
    fn multi_drone_msgs__srv__AssignMission_Response__init(msg: *mut AssignMission_Response) -> bool;
    fn multi_drone_msgs__srv__AssignMission_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<AssignMission_Response>, size: usize) -> bool;
    fn multi_drone_msgs__srv__AssignMission_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<AssignMission_Response>);
    fn multi_drone_msgs__srv__AssignMission_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<AssignMission_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<AssignMission_Response>) -> bool;
}

// Corresponds to multi_drone_msgs__srv__AssignMission_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AssignMission_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub num_waypoints_accepted: u32,

}



impl Default for AssignMission_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !multi_drone_msgs__srv__AssignMission_Response__init(&mut msg as *mut _) {
        panic!("Call to multi_drone_msgs__srv__AssignMission_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for AssignMission_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__AssignMission_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__AssignMission_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { multi_drone_msgs__srv__AssignMission_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for AssignMission_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for AssignMission_Response where Self: Sized {
  const TYPE_NAME: &'static str = "multi_drone_msgs/srv/AssignMission_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__multi_drone_msgs__srv__AssignMission_Response() }
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


