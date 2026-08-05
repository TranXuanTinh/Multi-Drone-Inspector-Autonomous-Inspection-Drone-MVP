/**
 * @file offboard_controller.hpp
 * @brief Per-vehicle offboard controller for PX4 via ROS 2 / Micro XRCE-DDS
 *
 * Each vehicle gets its own OffboardController node instance, namespaced
 * to /px4_{i}/. Communicates directly with PX4 via px4_msgs topics
 * bridged by the Micro XRCE-DDS Agent.
 *
 * Coordinate frames:
 *   - PX4 uses NED (North-East-Down) for local position/velocity
 *   - GPS uses WGS84 (lat/lon/alt) for global position
 *   - Yaw: 0 = North, positive clockwise (NED convention)
 */

#pragma once

#include <chrono>
#include <cmath>
#include <functional>
#include <memory>
#include <mutex>
#include <optional>
#include <string>

#include <rclcpp/rclcpp.hpp>

// PX4-ROS 2 message types (via Micro XRCE-DDS)
#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <px4_msgs/msg/vehicle_control_mode.hpp>
#include <px4_msgs/msg/vehicle_global_position.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>
#include <px4_msgs/msg/vehicle_status.hpp>
#include <px4_msgs/msg/battery_status.hpp>
#include <px4_msgs/msg/sensor_gps.hpp>
#include <px4_msgs/msg/vehicle_attitude.hpp>
#include <px4_msgs/msg/vehicle_land_detected.hpp>
#include <px4_msgs/msg/timesync_status.hpp>

// Fleet communication
#include <multi_drone_msgs/msg/vehicle_status.hpp>
#include <multi_drone_msgs/msg/mission_command.hpp>

namespace multi_drone
{

/**
 * @brief Current state of the vehicle from PX4 telemetry
 */
struct VehicleState
{
  // Position (NED local frame, meters)
  double local_x{0.0};
  double local_y{0.0};
  double local_z{0.0};

  // Position (GPS global frame)
  double latitude_deg{0.0};
  double longitude_deg{0.0};
  float absolute_altitude_m{0.0f};
  float relative_altitude_m{0.0f};

  // Velocity (NED, m/s)
  float vx{0.0f};
  float vy{0.0f};
  float vz{0.0f};
  float groundspeed_ms{0.0f};

  // Attitude (radians)
  float roll{0.0f};
  float pitch{0.0f};
  float yaw{0.0f};
  float heading_deg{0.0f};

  // Battery
  float battery_percent{100.0f};
  float battery_voltage{0.0f};

  // GPS
  uint8_t gps_fix_type{0};
  uint8_t gps_num_satellites{0};

  // Flight state
  uint8_t nav_state{0};
  uint8_t arming_state{0};
  bool armed{false};
  bool landed{true};
  std::string flight_mode{"UNKNOWN"};

  // Timestamps
  uint64_t timestamp_us{0};
};

/**
 * @brief Setpoint target for offboard control
 */
struct OffboardSetpoint
{
  enum class Type
  {
    POSITION,
    VELOCITY,
    IDLE
  };

  Type type{Type::IDLE};

  // Position setpoint (NED, meters)
  float x{0.0f};
  float y{0.0f};
  float z{0.0f};   // Negative = up in NED
  float yaw{0.0f};  // Radians

  // Velocity setpoint (NED, m/s)
  float vx{0.0f};
  float vy{0.0f};
  float vz{0.0f};
  float yaw_rate{0.0f};
};

/**
 * @class OffboardController
 * @brief ROS 2 node for per-vehicle PX4 offboard control
 *
 * Responsibilities:
 *   1. Subscribe to PX4 telemetry topics (position, status, battery, GPS)
 *   2. Publish offboard control mode + trajectory setpoints at ≥2Hz
 *   3. Handle vehicle commands (arm, disarm, takeoff, land, RTL)
 *   4. Publish VehicleStatus to fleet manager
 *   5. Accept MissionCommand from fleet for coordinated operations
 */
class OffboardController : public rclcpp::Node
{
public:
  explicit OffboardController(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
  ~OffboardController() override = default;

  // ── Public command interface ──────────────────────────────
  void arm();
  void disarm();
  void takeoff(float altitude_m);
  void land();
  void return_to_launch();
  void hold();

  void start_offboard();
  void stop_offboard();

  void set_position_setpoint(float x, float y, float z, float yaw);
  void set_velocity_setpoint(float vx, float vy, float vz, float yaw_rate);

  // ── Getters ───────────────────────────────────────────────
  const VehicleState & get_state() const { return state_; }
  bool is_offboard_active() const { return offboard_active_; }
  bool is_armed() const { return state_.armed; }
  uint8_t vehicle_id() const { return vehicle_id_; }

private:
  // ── Parameters ────────────────────────────────────────────
  uint8_t vehicle_id_;
  std::string vehicle_name_;
  double offboard_rate_hz_;
  double status_publish_rate_hz_;

  // ── State ─────────────────────────────────────────────────
  VehicleState state_;
  OffboardSetpoint current_setpoint_;
  bool offboard_active_{false};
  uint64_t offboard_setpoint_counter_{0};
  std::mutex state_mutex_;

  // Timesync for PX4 timestamp alignment
  std::atomic<int64_t> timestamp_offset_{0};

  // ── PX4 Subscribers (px4_msgs) ────────────────────────────
  rclcpp::Subscription<px4_msgs::msg::VehicleStatus>::SharedPtr vehicle_status_sub_;
  rclcpp::Subscription<px4_msgs::msg::VehicleLocalPosition>::SharedPtr local_position_sub_;
  rclcpp::Subscription<px4_msgs::msg::VehicleGlobalPosition>::SharedPtr global_position_sub_;
  rclcpp::Subscription<px4_msgs::msg::BatteryStatus>::SharedPtr battery_sub_;
  rclcpp::Subscription<px4_msgs::msg::SensorGps>::SharedPtr gps_sub_;
  rclcpp::Subscription<px4_msgs::msg::VehicleAttitude>::SharedPtr attitude_sub_;
  rclcpp::Subscription<px4_msgs::msg::VehicleLandDetected>::SharedPtr land_detected_sub_;
  rclcpp::Subscription<px4_msgs::msg::TimesyncStatus>::SharedPtr timesync_sub_;

  // ── PX4 Publishers (px4_msgs) ─────────────────────────────
  rclcpp::Publisher<px4_msgs::msg::OffboardControlMode>::SharedPtr offboard_control_mode_pub_;
  rclcpp::Publisher<px4_msgs::msg::TrajectorySetpoint>::SharedPtr trajectory_setpoint_pub_;
  rclcpp::Publisher<px4_msgs::msg::VehicleCommand>::SharedPtr vehicle_command_pub_;

  // ── Fleet Interface ───────────────────────────────────────
  rclcpp::Publisher<multi_drone_msgs::msg::VehicleStatus>::SharedPtr fleet_status_pub_;
  rclcpp::Subscription<multi_drone_msgs::msg::MissionCommand>::SharedPtr mission_command_sub_;

  // ── Timers ────────────────────────────────────────────────
  rclcpp::TimerBase::SharedPtr offboard_timer_;   // Offboard setpoint loop
  rclcpp::TimerBase::SharedPtr status_timer_;      // Fleet status publish loop

  // ── Private methods ───────────────────────────────────────
  void setup_parameters();
  void setup_subscribers();
  void setup_publishers();
  void setup_timers();

  // Callback handlers
  void on_vehicle_status(const px4_msgs::msg::VehicleStatus::SharedPtr msg);
  void on_local_position(const px4_msgs::msg::VehicleLocalPosition::SharedPtr msg);
  void on_global_position(const px4_msgs::msg::VehicleGlobalPosition::SharedPtr msg);
  void on_battery_status(const px4_msgs::msg::BatteryStatus::SharedPtr msg);
  void on_gps_info(const px4_msgs::msg::SensorGps::SharedPtr msg);
  void on_attitude(const px4_msgs::msg::VehicleAttitude::SharedPtr msg);
  void on_land_detected(const px4_msgs::msg::VehicleLandDetected::SharedPtr msg);
  void on_timesync(const px4_msgs::msg::TimesyncStatus::SharedPtr msg);
  void on_mission_command(const multi_drone_msgs::msg::MissionCommand::SharedPtr msg);

  // Control loop
  void offboard_control_loop();
  void publish_fleet_status();

  // PX4 command helpers
  void publish_offboard_control_mode();
  void publish_trajectory_setpoint();
  void publish_vehicle_command(
    uint16_t command,
    float param1 = 0.0f,
    float param2 = 0.0f,
    float param3 = 0.0f,
    float param4 = 0.0f,
    float param5 = 0.0f,
    float param6 = 0.0f,
    float param7 = 0.0f);

  // Utility
  uint64_t get_timestamp_us() const;
  static std::string nav_state_to_string(uint8_t nav_state);
  static void quaternion_to_euler(
    float q0, float q1, float q2, float q3,
    float & roll, float & pitch, float & yaw);
};

}  // namespace multi_drone
