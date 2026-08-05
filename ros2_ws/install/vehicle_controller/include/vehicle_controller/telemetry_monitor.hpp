/**
 * @file telemetry_monitor.hpp
 * @brief Per-vehicle telemetry aggregation and health monitoring
 */

#pragma once

#include <chrono>
#include <memory>
#include <mutex>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <px4_msgs/msg/vehicle_status.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>
#include <px4_msgs/msg/vehicle_global_position.hpp>
#include <px4_msgs/msg/battery_status.hpp>
#include <px4_msgs/msg/sensor_gps.hpp>
#include <multi_drone_msgs/msg/vehicle_status.hpp>

namespace multi_drone
{

/**
 * @class TelemetryMonitor
 * @brief Lightweight telemetry aggregator that publishes VehicleStatus
 *
 * This node can run standalone (without OffboardController) for
 * pure monitoring scenarios. In full deployments, the OffboardController
 * handles its own telemetry and this node is optional.
 */
class TelemetryMonitor : public rclcpp::Node
{
public:
  explicit TelemetryMonitor(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
  ~TelemetryMonitor() override = default;

private:
  uint8_t vehicle_id_;
  std::string vehicle_name_;

  // Latest telemetry values
  double latitude_deg_{0.0};
  double longitude_deg_{0.0};
  float relative_altitude_m_{0.0f};
  float heading_deg_{0.0f};
  float groundspeed_ms_{0.0f};
  float battery_percent_{100.0f};
  float battery_voltage_{0.0f};
  uint8_t gps_fix_type_{0};
  uint8_t gps_num_satellites_{0};
  bool armed_{false};
  std::string flight_mode_{"UNKNOWN"};
  float local_x_{0.0f};
  float local_y_{0.0f};
  float local_z_{0.0f};

  std::mutex data_mutex_;

  // Heartbeat tracking
  std::chrono::steady_clock::time_point last_heartbeat_;
  bool connected_{false};

  // Subscribers
  rclcpp::Subscription<px4_msgs::msg::VehicleStatus>::SharedPtr status_sub_;
  rclcpp::Subscription<px4_msgs::msg::VehicleLocalPosition>::SharedPtr local_pos_sub_;
  rclcpp::Subscription<px4_msgs::msg::VehicleGlobalPosition>::SharedPtr global_pos_sub_;
  rclcpp::Subscription<px4_msgs::msg::BatteryStatus>::SharedPtr battery_sub_;
  rclcpp::Subscription<px4_msgs::msg::SensorGps>::SharedPtr gps_sub_;

  // Publisher
  rclcpp::Publisher<multi_drone_msgs::msg::VehicleStatus>::SharedPtr status_pub_;
  rclcpp::TimerBase::SharedPtr publish_timer_;
  rclcpp::TimerBase::SharedPtr heartbeat_timer_;

  void publish_status();
  void check_heartbeat();
};

}  // namespace multi_drone
