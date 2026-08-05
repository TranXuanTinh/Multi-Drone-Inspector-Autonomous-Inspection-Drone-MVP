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
 * @file safety_guard.hpp
 * @brief Per-vehicle safety monitoring with configurable rules
 */

#pragma once

#include <cmath>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>
#include <multi_drone_msgs/msg/vehicle_status.hpp>

namespace multi_drone
{

/**
 * @brief Safety action priorities (higher = more urgent)
 */
enum class SafetyAction : uint8_t
{
  NONE = 0,
  WARN = 1,
  RTL_NOW = 2,
  EMERGENCY_LAND = 3
};

/**
 * @class SafetyGuard
 * @brief Per-vehicle safety monitor implementing Chain of Responsibility
 *
 * Monitors battery, geofence, altitude, and inter-vehicle separation.
 * Triggers RTL or emergency land when safety limits are breached.
 */
class SafetyGuard : public rclcpp::Node
{
public:
  explicit SafetyGuard(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
  ~SafetyGuard() override = default;

private:
  uint8_t vehicle_id_;

  // Safety parameters (configurable via ROS 2 params)
  double geofence_radius_m_;
  double max_altitude_m_;
  double min_battery_pct_;
  double critical_battery_pct_;
  double min_separation_m_;
  double home_lat_;
  double home_lon_;

  // Current state
  struct VehicleState
  {
    double latitude_deg{0.0};
    double longitude_deg{0.0};
    float relative_altitude_m{0.0f};
    float battery_percent{100.0f};
    bool armed{false};
    bool connected{false};
    float local_x{0.0f};
    float local_y{0.0f};
    float local_z{0.0f};
  };

  VehicleState own_state_;
  std::vector<VehicleState> other_vehicles_;
  std::mutex state_mutex_;

  // Last triggered action (avoid spamming)
  SafetyAction last_action_{SafetyAction::NONE};

  // Subscribers
  rclcpp::Subscription<multi_drone_msgs::msg::VehicleStatus>::SharedPtr own_status_sub_;
  rclcpp::Subscription<multi_drone_msgs::msg::VehicleStatus>::SharedPtr fleet_status_sub_;

  // Publisher for emergency commands
  rclcpp::Publisher<px4_msgs::msg::VehicleCommand>::SharedPtr vehicle_command_pub_;

  // Timer
  rclcpp::TimerBase::SharedPtr safety_timer_;

  // Safety check methods
  void safety_check_loop();
  SafetyAction check_battery() const;
  SafetyAction check_geofence() const;
  SafetyAction check_altitude() const;
  SafetyAction check_separation() const;
  void execute_safety_action(SafetyAction action);

  // Utility
  static double haversine_distance(
    double lat1_deg, double lon1_deg,
    double lat2_deg, double lon2_deg);
};

}  // namespace multi_drone
