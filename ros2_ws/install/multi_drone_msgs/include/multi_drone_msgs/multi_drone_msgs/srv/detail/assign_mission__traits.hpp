// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_drone_msgs:srv/AssignMission.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "multi_drone_msgs/srv/assign_mission.hpp"


#ifndef MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__TRAITS_HPP_
#define MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_drone_msgs/srv/detail/assign_mission__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace multi_drone_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignMission_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: vehicle_id
  {
    out << "vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_id, out);
    out << ", ";
  }

  // member: mission_type
  {
    out << "mission_type: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_type, out);
    out << ", ";
  }

  // member: waypoint_lats
  {
    if (msg.waypoint_lats.size() == 0) {
      out << "waypoint_lats: []";
    } else {
      out << "waypoint_lats: [";
      size_t pending_items = msg.waypoint_lats.size();
      for (auto item : msg.waypoint_lats) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: waypoint_lons
  {
    if (msg.waypoint_lons.size() == 0) {
      out << "waypoint_lons: []";
    } else {
      out << "waypoint_lons: [";
      size_t pending_items = msg.waypoint_lons.size();
      for (auto item : msg.waypoint_lons) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: waypoint_alts
  {
    if (msg.waypoint_alts.size() == 0) {
      out << "waypoint_alts: []";
    } else {
      out << "waypoint_alts: [";
      size_t pending_items = msg.waypoint_alts.size();
      for (auto item : msg.waypoint_alts) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: speed_ms
  {
    out << "speed_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_ms, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignMission_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vehicle_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vehicle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vehicle_id, out);
    out << "\n";
  }

  // member: mission_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_type: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_type, out);
    out << "\n";
  }

  // member: waypoint_lats
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoint_lats.size() == 0) {
      out << "waypoint_lats: []\n";
    } else {
      out << "waypoint_lats:\n";
      for (auto item : msg.waypoint_lats) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: waypoint_lons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoint_lons.size() == 0) {
      out << "waypoint_lons: []\n";
    } else {
      out << "waypoint_lons:\n";
      for (auto item : msg.waypoint_lons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: waypoint_alts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoint_alts.size() == 0) {
      out << "waypoint_alts: []\n";
    } else {
      out << "waypoint_alts:\n";
      for (auto item : msg.waypoint_alts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: speed_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_ms, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignMission_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace multi_drone_msgs

namespace rosidl_generator_traits
{

[[deprecated("use multi_drone_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_drone_msgs::srv::AssignMission_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_drone_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_drone_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const multi_drone_msgs::srv::AssignMission_Request & msg)
{
  return multi_drone_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<multi_drone_msgs::srv::AssignMission_Request>()
{
  return "multi_drone_msgs::srv::AssignMission_Request";
}

template<>
inline const char * name<multi_drone_msgs::srv::AssignMission_Request>()
{
  return "multi_drone_msgs/srv/AssignMission_Request";
}

template<>
struct has_fixed_size<multi_drone_msgs::srv::AssignMission_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_drone_msgs::srv::AssignMission_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_drone_msgs::srv::AssignMission_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace multi_drone_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignMission_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: num_waypoints_accepted
  {
    out << "num_waypoints_accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.num_waypoints_accepted, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignMission_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: num_waypoints_accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_waypoints_accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.num_waypoints_accepted, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignMission_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace multi_drone_msgs

namespace rosidl_generator_traits
{

[[deprecated("use multi_drone_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_drone_msgs::srv::AssignMission_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_drone_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_drone_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const multi_drone_msgs::srv::AssignMission_Response & msg)
{
  return multi_drone_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<multi_drone_msgs::srv::AssignMission_Response>()
{
  return "multi_drone_msgs::srv::AssignMission_Response";
}

template<>
inline const char * name<multi_drone_msgs::srv::AssignMission_Response>()
{
  return "multi_drone_msgs/srv/AssignMission_Response";
}

template<>
struct has_fixed_size<multi_drone_msgs::srv::AssignMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_drone_msgs::srv::AssignMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_drone_msgs::srv::AssignMission_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace multi_drone_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AssignMission_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AssignMission_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AssignMission_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace multi_drone_msgs

namespace rosidl_generator_traits
{

[[deprecated("use multi_drone_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_drone_msgs::srv::AssignMission_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_drone_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_drone_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const multi_drone_msgs::srv::AssignMission_Event & msg)
{
  return multi_drone_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<multi_drone_msgs::srv::AssignMission_Event>()
{
  return "multi_drone_msgs::srv::AssignMission_Event";
}

template<>
inline const char * name<multi_drone_msgs::srv::AssignMission_Event>()
{
  return "multi_drone_msgs/srv/AssignMission_Event";
}

template<>
struct has_fixed_size<multi_drone_msgs::srv::AssignMission_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_drone_msgs::srv::AssignMission_Event>
  : std::integral_constant<bool, has_bounded_size<multi_drone_msgs::srv::AssignMission_Request>::value && has_bounded_size<multi_drone_msgs::srv::AssignMission_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<multi_drone_msgs::srv::AssignMission_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<multi_drone_msgs::srv::AssignMission>()
{
  return "multi_drone_msgs::srv::AssignMission";
}

template<>
inline const char * name<multi_drone_msgs::srv::AssignMission>()
{
  return "multi_drone_msgs/srv/AssignMission";
}

template<>
struct has_fixed_size<multi_drone_msgs::srv::AssignMission>
  : std::integral_constant<
    bool,
    has_fixed_size<multi_drone_msgs::srv::AssignMission_Request>::value &&
    has_fixed_size<multi_drone_msgs::srv::AssignMission_Response>::value
  >
{
};

template<>
struct has_bounded_size<multi_drone_msgs::srv::AssignMission>
  : std::integral_constant<
    bool,
    has_bounded_size<multi_drone_msgs::srv::AssignMission_Request>::value &&
    has_bounded_size<multi_drone_msgs::srv::AssignMission_Response>::value
  >
{
};

template<>
struct is_service<multi_drone_msgs::srv::AssignMission>
  : std::true_type
{
};

template<>
struct is_service_request<multi_drone_msgs::srv::AssignMission_Request>
  : std::true_type
{
};

template<>
struct is_service_response<multi_drone_msgs::srv::AssignMission_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MULTI_DRONE_MSGS__SRV__DETAIL__ASSIGN_MISSION__TRAITS_HPP_
