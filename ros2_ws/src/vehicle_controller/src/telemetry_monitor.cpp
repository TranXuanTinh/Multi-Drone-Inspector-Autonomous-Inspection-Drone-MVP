/**
 * @file telemetry_monitor.cpp
 * @brief Standalone telemetry monitor for PX4 vehicle via XRCE-DDS
 */

#include "vehicle_controller/telemetry_monitor.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace multi_drone
{

TelemetryMonitor::TelemetryMonitor(const rclcpp::NodeOptions & options)
: Node("telemetry_monitor", options)
{
  // Parameters
  this->declare_parameter("vehicle_id", 0);
  this->declare_parameter("vehicle_name", "UAV-0");
  this->declare_parameter("publish_rate_hz", 10.0);
  this->declare_parameter("heartbeat_timeout_s", 5.0);

  vehicle_id_ = static_cast<uint8_t>(this->get_parameter("vehicle_id").as_int());
  vehicle_name_ = this->get_parameter("vehicle_name").as_string();
  double publish_rate = this->get_parameter("publish_rate_hz").as_double();

  last_heartbeat_ = std::chrono::steady_clock::now();

  // QoS for PX4 topics
  rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
  auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);

  // Subscribe to PX4 telemetry
  status_sub_ = this->create_subscription<px4_msgs::msg::VehicleStatus>(
    "fmu/out/vehicle_status", qos,
    [this](const px4_msgs::msg::VehicleStatus::SharedPtr msg) {
      std::lock_guard<std::mutex> lock(data_mutex_);
      armed_ = (msg->arming_state == 2);
      last_heartbeat_ = std::chrono::steady_clock::now();
      connected_ = true;
      // Map nav_state to flight mode string
      switch (msg->nav_state) {
        case 0: flight_mode_ = "MANUAL"; break;
        case 2: flight_mode_ = "POSCTL"; break;
        case 3: flight_mode_ = "AUTO_MISSION"; break;
        case 4: flight_mode_ = "AUTO_LOITER"; break;
        case 5: flight_mode_ = "AUTO_RTL"; break;
        case 14: flight_mode_ = "OFFBOARD"; break;
        default: flight_mode_ = "UNKNOWN"; break;
      }
    });

  local_pos_sub_ = this->create_subscription<px4_msgs::msg::VehicleLocalPosition>(
    "fmu/out/vehicle_local_position", qos,
    [this](const px4_msgs::msg::VehicleLocalPosition::SharedPtr msg) {
      std::lock_guard<std::mutex> lock(data_mutex_);
      local_x_ = msg->x;
      local_y_ = msg->y;
      local_z_ = msg->z;
      relative_altitude_m_ = -msg->z;
      heading_deg_ = msg->heading * 180.0f / M_PI;
      groundspeed_ms_ = std::sqrt(msg->vx * msg->vx + msg->vy * msg->vy);
    });

  global_pos_sub_ = this->create_subscription<px4_msgs::msg::VehicleGlobalPosition>(
    "fmu/out/vehicle_global_position", qos,
    [this](const px4_msgs::msg::VehicleGlobalPosition::SharedPtr msg) {
      std::lock_guard<std::mutex> lock(data_mutex_);
      latitude_deg_ = msg->lat;
      longitude_deg_ = msg->lon;
    });

  battery_sub_ = this->create_subscription<px4_msgs::msg::BatteryStatus>(
    "fmu/out/battery_status", qos,
    [this](const px4_msgs::msg::BatteryStatus::SharedPtr msg) {
      std::lock_guard<std::mutex> lock(data_mutex_);
      battery_percent_ = msg->remaining * 100.0f;
      battery_voltage_ = msg->voltage_v;
    });

  gps_sub_ = this->create_subscription<px4_msgs::msg::SensorGps>(
    "fmu/out/vehicle_gps_position", qos,
    [this](const px4_msgs::msg::SensorGps::SharedPtr msg) {
      std::lock_guard<std::mutex> lock(data_mutex_);
      gps_fix_type_ = msg->fix_type;
      gps_num_satellites_ = msg->satellites_used;
    });

  // Fleet status publisher
  auto fleet_qos = rclcpp::QoS(10).reliable();
  status_pub_ = this->create_publisher<multi_drone_msgs::msg::VehicleStatus>(
    "/fleet/vehicle_status", fleet_qos);

  // Publish timer
  auto period = std::chrono::duration<double>(1.0 / publish_rate);
  publish_timer_ = this->create_wall_timer(
    std::chrono::duration_cast<std::chrono::nanoseconds>(period),
    std::bind(&TelemetryMonitor::publish_status, this));

  // Heartbeat check timer (1 Hz)
  heartbeat_timer_ = this->create_wall_timer(
    1s, std::bind(&TelemetryMonitor::check_heartbeat, this));

  RCLCPP_INFO(get_logger(), "TelemetryMonitor started — vehicle_id=%d", vehicle_id_);
}

void TelemetryMonitor::publish_status()
{
  auto msg = multi_drone_msgs::msg::VehicleStatus();

  std::lock_guard<std::mutex> lock(data_mutex_);

  msg.vehicle_id = vehicle_id_;
  msg.namespace_ = this->get_namespace();
  msg.name = vehicle_name_;

  msg.latitude_deg = latitude_deg_;
  msg.longitude_deg = longitude_deg_;
  msg.relative_altitude_m = relative_altitude_m_;
  msg.heading_deg = heading_deg_;
  msg.groundspeed_ms = groundspeed_ms_;

  msg.battery_percent = battery_percent_;
  msg.battery_voltage = battery_voltage_;

  msg.flight_mode = flight_mode_;
  msg.armed = armed_;
  msg.connected = connected_;
  msg.gps_fix_type = gps_fix_type_;
  msg.gps_num_satellites = gps_num_satellites_;
  msg.is_healthy = connected_ && (gps_fix_type_ >= 3);

  msg.local_x = local_x_;
  msg.local_y = local_y_;
  msg.local_z = local_z_;

  msg.stamp = this->now();

  status_pub_->publish(msg);
}

void TelemetryMonitor::check_heartbeat()
{
  auto now = std::chrono::steady_clock::now();
  double timeout = this->get_parameter("heartbeat_timeout_s").as_double();
  auto elapsed = std::chrono::duration<double>(now - last_heartbeat_).count();

  if (elapsed > timeout) {
    if (connected_) {
      RCLCPP_WARN(get_logger(),
        "[Vehicle %d] Heartbeat lost (%.1fs since last)", vehicle_id_, elapsed);
      std::lock_guard<std::mutex> lock(data_mutex_);
      connected_ = false;
    }
  }
}

}  // namespace multi_drone

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<multi_drone::TelemetryMonitor>());
  rclcpp::shutdown();
  return 0;
}
