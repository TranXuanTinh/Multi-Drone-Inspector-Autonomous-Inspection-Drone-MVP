/**
 * @file safety_guard.cpp
 * @brief Per-vehicle safety monitor with configurable rules
 *
 * Implements Chain of Responsibility pattern for safety checks:
 *   - Battery level (warn → RTL → emergency land)
 *   - Geofence (horizontal distance from home)
 *   - Altitude limit
 *   - Inter-vehicle separation (collision avoidance)
 */

#include "vehicle_controller/safety_guard.hpp"

#include <cmath>
#include <algorithm>

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace multi_drone
{

// Earth radius for haversine calculation
static constexpr double EARTH_RADIUS_M = 6371000.0;

SafetyGuard::SafetyGuard(const rclcpp::NodeOptions & options)
: Node("safety_guard", options)
{
  // Declare safety parameters
  this->declare_parameter("vehicle_id", 0);
  this->declare_parameter("geofence_radius_m", 500.0);
  this->declare_parameter("max_altitude_m", 120.0);
  this->declare_parameter("min_battery_pct", 20.0);
  this->declare_parameter("critical_battery_pct", 10.0);
  this->declare_parameter("min_separation_m", 5.0);
  this->declare_parameter("home_lat", 47.397742);
  this->declare_parameter("home_lon", 8.545594);
  this->declare_parameter("safety_check_rate_hz", 5.0);

  vehicle_id_ = static_cast<uint8_t>(this->get_parameter("vehicle_id").as_int());
  geofence_radius_m_ = this->get_parameter("geofence_radius_m").as_double();
  max_altitude_m_ = this->get_parameter("max_altitude_m").as_double();
  min_battery_pct_ = this->get_parameter("min_battery_pct").as_double();
  critical_battery_pct_ = this->get_parameter("critical_battery_pct").as_double();
  min_separation_m_ = this->get_parameter("min_separation_m").as_double();
  home_lat_ = this->get_parameter("home_lat").as_double();
  home_lon_ = this->get_parameter("home_lon").as_double();
  double safety_rate = this->get_parameter("safety_check_rate_hz").as_double();

  // Subscribe to own vehicle status (from offboard_controller or telemetry_monitor)
  auto fleet_qos = rclcpp::QoS(10).reliable();

  fleet_status_sub_ = this->create_subscription<multi_drone_msgs::msg::VehicleStatus>(
    "/fleet/vehicle_status", fleet_qos,
    [this](const multi_drone_msgs::msg::VehicleStatus::SharedPtr msg) {
      std::lock_guard<std::mutex> lock(state_mutex_);

      if (msg->vehicle_id == vehicle_id_) {
        // Update own state
        own_state_.latitude_deg = msg->latitude_deg;
        own_state_.longitude_deg = msg->longitude_deg;
        own_state_.relative_altitude_m = msg->relative_altitude_m;
        own_state_.battery_percent = msg->battery_percent;
        own_state_.armed = msg->armed;
        own_state_.connected = msg->connected;
        own_state_.local_x = msg->local_x;
        own_state_.local_y = msg->local_y;
        own_state_.local_z = msg->local_z;
      } else {
        // Track other vehicles for separation check
        // Find or create entry for this vehicle
        bool found = false;
        for (auto & v : other_vehicles_) {
          if (std::abs(v.local_x - msg->local_x) < 0.01 &&
            std::abs(v.local_y - msg->local_y) < 0.01)
          {
            v.local_x = msg->local_x;
            v.local_y = msg->local_y;
            v.local_z = msg->local_z;
            v.latitude_deg = msg->latitude_deg;
            v.longitude_deg = msg->longitude_deg;
            found = true;
            break;
          }
        }
        if (!found) {
          VehicleState vs;
          vs.local_x = msg->local_x;
          vs.local_y = msg->local_y;
          vs.local_z = msg->local_z;
          vs.latitude_deg = msg->latitude_deg;
          vs.longitude_deg = msg->longitude_deg;
          other_vehicles_.push_back(vs);
        }
      }
    });

  // PX4 command publisher for emergency actions
  rmw_qos_profile_t px4_qos_profile = rmw_qos_profile_sensor_data;
  auto px4_qos = rclcpp::QoS(
    rclcpp::QoSInitialization(px4_qos_profile.history, 5), px4_qos_profile);
  vehicle_command_pub_ = this->create_publisher<px4_msgs::msg::VehicleCommand>(
    "fmu/in/vehicle_command", px4_qos);

  // Safety check timer
  auto period = std::chrono::duration<double>(1.0 / safety_rate);
  safety_timer_ = this->create_wall_timer(
    std::chrono::duration_cast<std::chrono::nanoseconds>(period),
    std::bind(&SafetyGuard::safety_check_loop, this));

  RCLCPP_INFO(get_logger(),
    "SafetyGuard started — vehicle_id=%d, geofence=%.0fm, max_alt=%.0fm, "
    "min_battery=%.0f%%, min_sep=%.0fm",
    vehicle_id_, geofence_radius_m_, max_altitude_m_,
    min_battery_pct_, min_separation_m_);
}

void SafetyGuard::safety_check_loop()
{
  std::lock_guard<std::mutex> lock(state_mutex_);

  // Only check when vehicle is armed
  if (!own_state_.armed) {
    return;
  }

  // Run all safety rules, take the most urgent action
  SafetyAction action = SafetyAction::NONE;
  action = std::max(action, check_battery());
  action = std::max(action, check_geofence());
  action = std::max(action, check_altitude());
  action = std::max(action, check_separation());

  // Execute action if it's more urgent than last action
  if (action > last_action_ && action > SafetyAction::NONE) {
    execute_safety_action(action);
    last_action_ = action;
  }

  // Reset last action if vehicle is safe again
  if (action == SafetyAction::NONE) {
    last_action_ = SafetyAction::NONE;
  }
}

SafetyAction SafetyGuard::check_battery() const
{
  float pct = own_state_.battery_percent;
  if (pct <= 0.0f) {
    return SafetyAction::NONE;  // Data not available
  }

  if (pct < critical_battery_pct_) {
    RCLCPP_WARN(get_logger(),
      "[Vehicle %d] CRITICAL battery: %.1f%%", vehicle_id_, pct);
    return SafetyAction::EMERGENCY_LAND;
  }

  if (pct < min_battery_pct_) {
    RCLCPP_WARN(get_logger(),
      "[Vehicle %d] Low battery: %.1f%%", vehicle_id_, pct);
    return SafetyAction::RTL_NOW;
  }

  return SafetyAction::NONE;
}

SafetyAction SafetyGuard::check_geofence() const
{
  double dist = haversine_distance(
    home_lat_, home_lon_,
    own_state_.latitude_deg, own_state_.longitude_deg);

  if (dist > geofence_radius_m_) {
    RCLCPP_WARN(get_logger(),
      "[Vehicle %d] GEOFENCE breach: %.0fm from home (limit: %.0fm)",
      vehicle_id_, dist, geofence_radius_m_);
    return SafetyAction::RTL_NOW;
  }

  if (dist > geofence_radius_m_ * 0.9) {
    RCLCPP_INFO(get_logger(),
      "[Vehicle %d] Approaching geofence: %.0fm from home",
      vehicle_id_, dist);
    return SafetyAction::WARN;
  }

  return SafetyAction::NONE;
}

SafetyAction SafetyGuard::check_altitude() const
{
  float alt = own_state_.relative_altitude_m;

  if (alt > max_altitude_m_) {
    RCLCPP_WARN(get_logger(),
      "[Vehicle %d] Altitude limit exceeded: %.1fm (max: %.1fm)",
      vehicle_id_, alt, max_altitude_m_);
    return SafetyAction::RTL_NOW;
  }

  if (alt > max_altitude_m_ * 0.9) {
    return SafetyAction::WARN;
  }

  return SafetyAction::NONE;
}

SafetyAction SafetyGuard::check_separation() const
{
  for (const auto & other : other_vehicles_) {
    double dx = own_state_.local_x - other.local_x;
    double dy = own_state_.local_y - other.local_y;
    double dz = own_state_.local_z - other.local_z;
    double dist = std::sqrt(dx * dx + dy * dy + dz * dz);

    if (dist < min_separation_m_) {
      RCLCPP_WARN(get_logger(),
        "[Vehicle %d] SEPARATION WARNING: %.1fm from another vehicle (min: %.1fm)",
        vehicle_id_, dist, min_separation_m_);
      return SafetyAction::WARN;
    }

    if (dist < min_separation_m_ * 0.5) {
      RCLCPP_ERROR(get_logger(),
        "[Vehicle %d] COLLISION RISK: %.1fm — triggering emergency hold",
        vehicle_id_, dist);
      return SafetyAction::RTL_NOW;
    }
  }

  return SafetyAction::NONE;
}

void SafetyGuard::execute_safety_action(SafetyAction action)
{
  auto cmd = px4_msgs::msg::VehicleCommand();
  cmd.timestamp = std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::steady_clock::now().time_since_epoch()).count();
  cmd.target_system = vehicle_id_ + 1;
  cmd.target_component = 1;
  cmd.source_system = 1;
  cmd.source_component = 1;
  cmd.from_external = true;

  switch (action) {
    case SafetyAction::RTL_NOW:
      RCLCPP_WARN(get_logger(),
        "[Vehicle %d] SAFETY ACTION: Return to Launch", vehicle_id_);
      cmd.command = 20;  // NAV_RETURN_TO_LAUNCH
      vehicle_command_pub_->publish(cmd);
      break;

    case SafetyAction::EMERGENCY_LAND:
      RCLCPP_ERROR(get_logger(),
        "[Vehicle %d] SAFETY ACTION: Emergency Land", vehicle_id_);
      cmd.command = 21;  // NAV_LAND
      vehicle_command_pub_->publish(cmd);
      break;

    case SafetyAction::WARN:
      // Log-only warning, no PX4 command
      break;

    default:
      break;
  }
}

double SafetyGuard::haversine_distance(
  double lat1_deg, double lon1_deg,
  double lat2_deg, double lon2_deg)
{
  double lat1 = lat1_deg * M_PI / 180.0;
  double lat2 = lat2_deg * M_PI / 180.0;
  double dlat = (lat2_deg - lat1_deg) * M_PI / 180.0;
  double dlon = (lon2_deg - lon1_deg) * M_PI / 180.0;

  double a = std::sin(dlat / 2.0) * std::sin(dlat / 2.0) +
    std::cos(lat1) * std::cos(lat2) *
    std::sin(dlon / 2.0) * std::sin(dlon / 2.0);
  double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));

  return EARTH_RADIUS_M * c;
}

}  // namespace multi_drone

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<multi_drone::SafetyGuard>());
  rclcpp::shutdown();
  return 0;
}
