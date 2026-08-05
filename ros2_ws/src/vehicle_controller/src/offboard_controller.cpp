// Copyright 2026 MultiDrone Developer
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


/**
 * @file offboard_controller.cpp
 * @brief Per-vehicle offboard controller — PX4 ROS 2 interface via XRCE-DDS
 *
 * This node handles all communication with a single PX4 vehicle instance:
 *   - Subscribes to PX4 telemetry via px4_msgs
 *   - Publishes offboard control setpoints at 50Hz
 *   - Responds to fleet commands from the fleet_coordinator
 *   - Publishes aggregated VehicleStatus for the fleet
 *
 * Topic naming convention with Micro XRCE-DDS:
 *   PX4 instance i publishes to: /fmu/out/{topic_name}
 *   PX4 instance i subscribes to: /fmu/in/{topic_name}
 *   When using namespaces: /{namespace}/fmu/out/{topic_name}
 */

#include "vehicle_controller/offboard_controller.hpp"

#include <cmath>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace multi_drone
{

// ── PX4 vehicle command constants ───────────────────────
static constexpr uint16_t VEHICLE_CMD_COMPONENT_ARM_DISARM = 400;
static constexpr uint16_t VEHICLE_CMD_DO_SET_MODE = 176;
static constexpr uint16_t VEHICLE_CMD_NAV_TAKEOFF = 22;
static constexpr uint16_t VEHICLE_CMD_NAV_LAND = 21;
static constexpr uint16_t VEHICLE_CMD_NAV_RETURN_TO_LAUNCH = 20;

// PX4 nav states
static constexpr uint8_t NAVIGATION_STATE_MANUAL = 0;
static constexpr uint8_t NAVIGATION_STATE_ALTCTL = 1;
static constexpr uint8_t NAVIGATION_STATE_POSCTL = 2;
static constexpr uint8_t NAVIGATION_STATE_AUTO_MISSION = 3;
static constexpr uint8_t NAVIGATION_STATE_AUTO_LOITER = 4;
static constexpr uint8_t NAVIGATION_STATE_AUTO_RTL = 5;
static constexpr uint8_t NAVIGATION_STATE_OFFBOARD = 14;

// PX4 arming states
static constexpr uint8_t ARMING_STATE_DISARMED = 1;
static constexpr uint8_t ARMING_STATE_ARMED = 2;


OffboardController::OffboardController(const rclcpp::NodeOptions & options)
: Node("offboard_controller", options)
{
  setup_parameters();
  setup_subscribers();
  setup_publishers();
  setup_timers();

  RCLCPP_INFO(
    get_logger(),
    "OffboardController initialized — vehicle_id=%d, name='%s', offboard_rate=%.1f Hz",
    vehicle_id_, vehicle_name_.c_str(), offboard_rate_hz_);
}

// ═══════════════════════════════════════════════════════════
// Setup
// ═══════════════════════════════════════════════════════════

void OffboardController::setup_parameters()
{
  // Declare ROS 2 parameters with defaults
  this->declare_parameter("vehicle_id", 0);
  this->declare_parameter("vehicle_name", "UAV-0");
  this->declare_parameter("offboard_rate_hz", 50.0);
  this->declare_parameter("status_publish_rate_hz", 10.0);

  vehicle_id_ = static_cast<uint8_t>(this->get_parameter("vehicle_id").as_int());
  vehicle_name_ = this->get_parameter("vehicle_name").as_string();
  offboard_rate_hz_ = this->get_parameter("offboard_rate_hz").as_double();
  status_publish_rate_hz_ = this->get_parameter("status_publish_rate_hz").as_double();
}

void OffboardController::setup_subscribers()
{
  // QoS profile for PX4-ROS 2 bridge (best effort, volatile)
  rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
  auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

  // PX4 telemetry subscriptions
  vehicle_status_sub_ = this->create_subscription<px4_msgs::msg::VehicleStatus>(
    "fmu/out/vehicle_status", qos,
    std::bind(&OffboardController::on_vehicle_status, this, _1));

  local_position_sub_ = this->create_subscription<px4_msgs::msg::VehicleLocalPosition>(
    "fmu/out/vehicle_local_position", qos,
    std::bind(&OffboardController::on_local_position, this, _1));

  global_position_sub_ = this->create_subscription<px4_msgs::msg::VehicleGlobalPosition>(
    "fmu/out/vehicle_global_position", qos,
    std::bind(&OffboardController::on_global_position, this, _1));

  battery_sub_ = this->create_subscription<px4_msgs::msg::BatteryStatus>(
    "fmu/out/battery_status", qos,
    std::bind(&OffboardController::on_battery_status, this, _1));

  gps_sub_ = this->create_subscription<px4_msgs::msg::SensorGps>(
    "fmu/out/vehicle_gps_position", qos,
    std::bind(&OffboardController::on_gps_info, this, _1));

  attitude_sub_ = this->create_subscription<px4_msgs::msg::VehicleAttitude>(
    "fmu/out/vehicle_attitude", qos,
    std::bind(&OffboardController::on_attitude, this, _1));

  land_detected_sub_ = this->create_subscription<px4_msgs::msg::VehicleLandDetected>(
    "fmu/out/vehicle_land_detected", qos,
    std::bind(&OffboardController::on_land_detected, this, _1));

  timesync_sub_ = this->create_subscription<px4_msgs::msg::TimesyncStatus>(
    "fmu/out/timesync_status", qos,
    std::bind(&OffboardController::on_timesync, this, _1));

  // Fleet command subscription (from fleet_coordinator)
  auto fleet_qos = rclcpp::QoS(10).reliable();
  mission_command_sub_ = this->create_subscription<multi_drone_msgs::msg::MissionCommand>(
    "/fleet/mission_command", fleet_qos,
    std::bind(&OffboardController::on_mission_command, this, _1));
}

void OffboardController::setup_publishers()
{
  // QoS for PX4 commands (best effort for real-time)
  rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
  auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

  // PX4 command publishers
  offboard_control_mode_pub_ = this->create_publisher<px4_msgs::msg::OffboardControlMode>(
    "fmu/in/offboard_control_mode", qos);

  trajectory_setpoint_pub_ = this->create_publisher<px4_msgs::msg::TrajectorySetpoint>(
    "fmu/in/trajectory_setpoint", qos);

  vehicle_command_pub_ = this->create_publisher<px4_msgs::msg::VehicleCommand>(
    "fmu/in/vehicle_command", qos);

  // Fleet status publisher
  auto fleet_qos = rclcpp::QoS(10).reliable();
  fleet_status_pub_ = this->create_publisher<multi_drone_msgs::msg::VehicleStatus>(
    "/fleet/vehicle_status", fleet_qos);
}

void OffboardController::setup_timers()
{
  // Offboard control loop — must publish at ≥2Hz to maintain offboard mode
  auto offboard_period = std::chrono::duration<double>(1.0 / offboard_rate_hz_);
  offboard_timer_ = this->create_wall_timer(
    std::chrono::duration_cast<std::chrono::nanoseconds>(offboard_period),
    std::bind(&OffboardController::offboard_control_loop, this));

  // Fleet status publish loop
  auto status_period = std::chrono::duration<double>(1.0 / status_publish_rate_hz_);
  status_timer_ = this->create_wall_timer(
    std::chrono::duration_cast<std::chrono::nanoseconds>(status_period),
    std::bind(&OffboardController::publish_fleet_status, this));
}

// ═══════════════════════════════════════════════════════════
// Public Command Interface
// ═══════════════════════════════════════════════════════════

void OffboardController::arm()
{
  RCLCPP_INFO(get_logger(), "[Vehicle %d] Arming...", vehicle_id_);
  publish_vehicle_command(VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0f);
}

void OffboardController::disarm()
{
  RCLCPP_INFO(get_logger(), "[Vehicle %d] Disarming...", vehicle_id_);
  publish_vehicle_command(VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0f);
}

void OffboardController::takeoff(float altitude_m)
{
  RCLCPP_INFO(get_logger(), "[Vehicle %d] Taking off to %.1fm...", vehicle_id_, altitude_m);

  // Set position setpoint above current position
  std::lock_guard<std::mutex> lock(state_mutex_);
  set_position_setpoint(
    state_.local_x,
    state_.local_y,
    -altitude_m,  // NED: negative Z = up
    state_.yaw);
}

void OffboardController::land()
{
  RCLCPP_INFO(get_logger(), "[Vehicle %d] Landing...", vehicle_id_);
  publish_vehicle_command(VEHICLE_CMD_NAV_LAND);
  offboard_active_ = false;
}

void OffboardController::return_to_launch()
{
  RCLCPP_INFO(get_logger(), "[Vehicle %d] Returning to launch...", vehicle_id_);
  publish_vehicle_command(VEHICLE_CMD_NAV_RETURN_TO_LAUNCH);
  offboard_active_ = false;
}

void OffboardController::hold()
{
  RCLCPP_INFO(get_logger(), "[Vehicle %d] Holding position...", vehicle_id_);
  std::lock_guard<std::mutex> lock(state_mutex_);
  set_position_setpoint(
    state_.local_x,
    state_.local_y,
    state_.local_z,
    state_.yaw);
}

void OffboardController::start_offboard()
{
  if (offboard_active_) {
    RCLCPP_WARN(get_logger(), "[Vehicle %d] Offboard already active", vehicle_id_);
    return;
  }

  RCLCPP_INFO(get_logger(), "[Vehicle %d] Starting offboard mode...", vehicle_id_);

  // Must publish setpoints before entering offboard mode
  // PX4 requires ≥2Hz stream for several cycles before accepting offboard
  offboard_setpoint_counter_ = 0;

  // Set initial setpoint to current position (hold in place)
  {
    std::lock_guard<std::mutex> lock(state_mutex_);
    current_setpoint_.type = OffboardSetpoint::Type::POSITION;
    current_setpoint_.x = state_.local_x;
    current_setpoint_.y = state_.local_y;
    current_setpoint_.z = state_.local_z;
    current_setpoint_.yaw = state_.yaw;
  }

  offboard_active_ = true;
}

void OffboardController::stop_offboard()
{
  if (!offboard_active_) {
    return;
  }
  RCLCPP_INFO(get_logger(), "[Vehicle %d] Stopping offboard mode...", vehicle_id_);
  offboard_active_ = false;
  current_setpoint_.type = OffboardSetpoint::Type::IDLE;
}

void OffboardController::set_position_setpoint(float x, float y, float z, float yaw)
{
  current_setpoint_.type = OffboardSetpoint::Type::POSITION;
  current_setpoint_.x = x;
  current_setpoint_.y = y;
  current_setpoint_.z = z;
  current_setpoint_.yaw = yaw;
}

void OffboardController::set_velocity_setpoint(float vx, float vy, float vz, float yaw_rate)
{
  current_setpoint_.type = OffboardSetpoint::Type::VELOCITY;
  current_setpoint_.vx = vx;
  current_setpoint_.vy = vy;
  current_setpoint_.vz = vz;
  current_setpoint_.yaw_rate = yaw_rate;
}

// ═══════════════════════════════════════════════════════════
// Telemetry Callbacks
// ═══════════════════════════════════════════════════════════

void OffboardController::on_vehicle_status(
  const px4_msgs::msg::VehicleStatus::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(state_mutex_);
  state_.nav_state = msg->nav_state;
  state_.arming_state = msg->arming_state;
  state_.armed = (msg->arming_state == ARMING_STATE_ARMED);
  state_.flight_mode = nav_state_to_string(msg->nav_state);
  state_.timestamp_us = msg->timestamp;
}

void OffboardController::on_local_position(
  const px4_msgs::msg::VehicleLocalPosition::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(state_mutex_);
  if (msg->xy_valid) {
    state_.local_x = msg->x;
    state_.local_y = msg->y;
  }
  if (msg->z_valid) {
    state_.local_z = msg->z;
    state_.relative_altitude_m = -msg->z;  // NED: -z = altitude AGL
  }
  if (msg->v_xy_valid) {
    state_.vx = msg->vx;
    state_.vy = msg->vy;
    state_.groundspeed_ms = std::sqrt(msg->vx * msg->vx + msg->vy * msg->vy);
  }
  if (msg->v_z_valid) {
    state_.vz = msg->vz;
  }
  state_.heading_deg = msg->heading * 180.0f / M_PI;
}

void OffboardController::on_global_position(
  const px4_msgs::msg::VehicleGlobalPosition::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(state_mutex_);
  state_.latitude_deg = msg->lat;
  state_.longitude_deg = msg->lon;
  state_.absolute_altitude_m = msg->alt;
  // NOTE: relative_altitude_m is set by on_local_position() (-z in NED)
  // which is the correct altitude AGL. Do NOT overwrite it here.
}

void OffboardController::on_battery_status(
  const px4_msgs::msg::BatteryStatus::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(state_mutex_);
  state_.battery_percent = msg->remaining * 100.0f;
  state_.battery_voltage = msg->voltage_v;
}

void OffboardController::on_gps_info(
  const px4_msgs::msg::SensorGps::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(state_mutex_);
  state_.gps_fix_type = msg->fix_type;
  state_.gps_num_satellites = msg->satellites_used;
}

void OffboardController::on_attitude(
  const px4_msgs::msg::VehicleAttitude::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(state_mutex_);
  // Convert quaternion to Euler angles
  quaternion_to_euler(
    msg->q[0], msg->q[1], msg->q[2], msg->q[3],
    state_.roll, state_.pitch, state_.yaw);
}

void OffboardController::on_land_detected(
  const px4_msgs::msg::VehicleLandDetected::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(state_mutex_);
  state_.landed = msg->landed;
}

void OffboardController::on_timesync(
  const px4_msgs::msg::TimesyncStatus::SharedPtr msg)
{
  // Store timestamp offset for synchronizing with PX4
  timestamp_offset_.store(msg->estimated_offset);
}

void OffboardController::on_mission_command(
  const multi_drone_msgs::msg::MissionCommand::SharedPtr msg)
{
  // Check if this command targets us or is a broadcast (255)
  if (msg->target_vehicle_id != 255 && msg->target_vehicle_id != vehicle_id_) {
    return;
  }

  RCLCPP_INFO(get_logger(), "[Vehicle %d] Received mission command: %d",
    vehicle_id_, msg->command);

  switch (msg->command) {
    case multi_drone_msgs::msg::MissionCommand::CMD_TAKEOFF_ALL:
      start_offboard();
      arm();
      takeoff(msg->param1 > 0 ? msg->param1 : 15.0f);
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_LAND_ALL:
      land();
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_RTL_ALL:
      return_to_launch();
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_ARM_ALL:
      arm();
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_DISARM_ALL:
      disarm();
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_OFFBOARD_START:
      start_offboard();
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_OFFBOARD_STOP:
      stop_offboard();
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_GOTO:
      // For GOTO, param1/2/3 are local NED x/y/z or we use GPS
      set_position_setpoint(
        msg->param1, msg->param2, msg->param3, msg->param4);
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_HOLD_ALL:
      hold();
      break;

    case multi_drone_msgs::msg::MissionCommand::CMD_ABORT_ALL:
      return_to_launch();
      break;

    default:
      RCLCPP_WARN(get_logger(), "[Vehicle %d] Unknown command: %d",
        vehicle_id_, msg->command);
      break;
  }
}

// ═══════════════════════════════════════════════════════════
// Control Loop
// ═══════════════════════════════════════════════════════════

void OffboardController::offboard_control_loop()
{
  if (!offboard_active_) {
    return;
  }

  offboard_setpoint_counter_++;

  // Publish offboard control mode and trajectory setpoint every cycle
  publish_offboard_control_mode();
  publish_trajectory_setpoint();

  // After 10 setpoint publications, switch PX4 to offboard mode
  if (offboard_setpoint_counter_ == 10) {
    RCLCPP_INFO(get_logger(), "[Vehicle %d] Engaging offboard mode", vehicle_id_);
    publish_vehicle_command(VEHICLE_CMD_DO_SET_MODE, 1.0f, 6.0f);  // 6 = offboard

    // Arm if not already armed
    if (!state_.armed) {
      arm();
    }
  }
}

void OffboardController::publish_fleet_status()
{
  auto msg = multi_drone_msgs::msg::VehicleStatus();

  std::lock_guard<std::mutex> lock(state_mutex_);

  msg.vehicle_id = vehicle_id_;
  msg.vehicle_namespace = this->get_namespace();
  msg.name = vehicle_name_;

  msg.latitude_deg = state_.latitude_deg;
  msg.longitude_deg = state_.longitude_deg;
  msg.absolute_altitude_m = state_.absolute_altitude_m;
  msg.relative_altitude_m = state_.relative_altitude_m;
  msg.heading_deg = state_.heading_deg;
  msg.roll_deg = state_.roll * 180.0f / M_PI;
  msg.pitch_deg = state_.pitch * 180.0f / M_PI;
  msg.yaw_deg = state_.yaw * 180.0f / M_PI;

  msg.groundspeed_ms = state_.groundspeed_ms;
  msg.velocity_north_ms = state_.vx;
  msg.velocity_east_ms = state_.vy;
  msg.velocity_down_ms = state_.vz;

  msg.battery_percent = state_.battery_percent;
  msg.battery_voltage = state_.battery_voltage;

  msg.flight_mode = state_.flight_mode;
  msg.armed = state_.armed;
  msg.offboard_active = offboard_active_;
  msg.mission_state = "ACTIVE";  // TODO(developer): integrate with mission state machine

  msg.connected = true;  // If we're running, we're connected
  msg.gps_fix_type = state_.gps_fix_type;
  msg.gps_num_satellites = state_.gps_num_satellites;
  msg.is_healthy = (state_.gps_fix_type >= 3);

  msg.local_x = state_.local_x;
  msg.local_y = state_.local_y;
  msg.local_z = state_.local_z;

  msg.stamp = this->now();

  fleet_status_pub_->publish(msg);
}

// ═══════════════════════════════════════════════════════════
// PX4 Command Helpers
// ═══════════════════════════════════════════════════════════

void OffboardController::publish_offboard_control_mode()
{
  auto msg = px4_msgs::msg::OffboardControlMode();
  msg.timestamp = get_timestamp_us();

  switch (current_setpoint_.type) {
    case OffboardSetpoint::Type::POSITION:
      msg.position = true;
      msg.velocity = false;
      msg.acceleration = false;
      msg.attitude = false;
      msg.body_rate = false;
      break;

    case OffboardSetpoint::Type::VELOCITY:
      msg.position = false;
      msg.velocity = true;
      msg.acceleration = false;
      msg.attitude = false;
      msg.body_rate = false;
      break;

    default:
      msg.position = true;
      msg.velocity = false;
      msg.acceleration = false;
      msg.attitude = false;
      msg.body_rate = false;
      break;
  }

  offboard_control_mode_pub_->publish(msg);
}

void OffboardController::publish_trajectory_setpoint()
{
  auto msg = px4_msgs::msg::TrajectorySetpoint();
  msg.timestamp = get_timestamp_us();

  switch (current_setpoint_.type) {
    case OffboardSetpoint::Type::POSITION:
      msg.position = {current_setpoint_.x, current_setpoint_.y, current_setpoint_.z};
      msg.velocity = {NAN, NAN, NAN};
      msg.yaw = current_setpoint_.yaw;
      msg.yawspeed = NAN;
      break;

    case OffboardSetpoint::Type::VELOCITY:
      msg.position = {NAN, NAN, NAN};
      msg.velocity = {current_setpoint_.vx, current_setpoint_.vy, current_setpoint_.vz};
      msg.yaw = NAN;
      msg.yawspeed = current_setpoint_.yaw_rate;
      break;

    default:
      // Hold at current position
      {
        std::lock_guard<std::mutex> lock(state_mutex_);
        msg.position = {
          static_cast<float>(state_.local_x),
          static_cast<float>(state_.local_y),
          static_cast<float>(state_.local_z)};
        msg.velocity = {NAN, NAN, NAN};
        msg.yaw = state_.yaw;
        msg.yawspeed = NAN;
      }
      break;
  }

  trajectory_setpoint_pub_->publish(msg);
}

void OffboardController::publish_vehicle_command(
  uint16_t command,
  float param1, float param2, float param3, float param4,
  float param5, float param6, float param7)
{
  auto msg = px4_msgs::msg::VehicleCommand();
  msg.timestamp = get_timestamp_us();
  msg.param1 = param1;
  msg.param2 = param2;
  msg.param3 = param3;
  msg.param4 = param4;
  msg.param5 = static_cast<double>(param5);
  msg.param6 = static_cast<double>(param6);
  msg.param7 = param7;
  msg.command = command;
  msg.target_system = vehicle_id_ + 1;  // PX4 system IDs are 1-indexed
  msg.target_component = 1;
  msg.source_system = 1;
  msg.source_component = 1;
  msg.from_external = true;

  vehicle_command_pub_->publish(msg);

  RCLCPP_DEBUG(get_logger(), "[Vehicle %d] Published command %d", vehicle_id_, command);
}

// ═══════════════════════════════════════════════════════════
// Utilities
// ═══════════════════════════════════════════════════════════

uint64_t OffboardController::get_timestamp_us() const
{
  return std::chrono::duration_cast<std::chrono::microseconds>(
    std::chrono::steady_clock::now().time_since_epoch()).count();
}

std::string OffboardController::nav_state_to_string(uint8_t nav_state)
{
  switch (nav_state) {
    case NAVIGATION_STATE_MANUAL:     return "MANUAL";
    case NAVIGATION_STATE_ALTCTL:     return "ALTCTL";
    case NAVIGATION_STATE_POSCTL:     return "POSCTL";
    case NAVIGATION_STATE_AUTO_MISSION: return "AUTO_MISSION";
    case NAVIGATION_STATE_AUTO_LOITER:  return "AUTO_LOITER";
    case NAVIGATION_STATE_AUTO_RTL:   return "AUTO_RTL";
    case NAVIGATION_STATE_OFFBOARD:   return "OFFBOARD";
    default: return "UNKNOWN(" + std::to_string(nav_state) + ")";
  }
}

void OffboardController::quaternion_to_euler(
  float q0, float q1, float q2, float q3,
  float & roll, float & pitch, float & yaw)
{
  // Roll (x-axis rotation)
  float sinr_cosp = 2.0f * (q0 * q1 + q2 * q3);
  float cosr_cosp = 1.0f - 2.0f * (q1 * q1 + q2 * q2);
  roll = std::atan2(sinr_cosp, cosr_cosp);

  // Pitch (y-axis rotation)
  float sinp = 2.0f * (q0 * q2 - q3 * q1);
  if (std::abs(sinp) >= 1.0f) {
    pitch = std::copysign(M_PI / 2.0f, sinp);
  } else {
    pitch = std::asin(sinp);
  }

  // Yaw (z-axis rotation)
  float siny_cosp = 2.0f * (q0 * q3 + q1 * q2);
  float cosy_cosp = 1.0f - 2.0f * (q2 * q2 + q3 * q3);
  yaw = std::atan2(siny_cosp, cosy_cosp);
}

}  // namespace multi_drone

// ═══════════════════════════════════════════════════════════
// Main entry point
// ═══════════════════════════════════════════════════════════

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<multi_drone::OffboardController>());
  rclcpp::shutdown();
  return 0;
}
