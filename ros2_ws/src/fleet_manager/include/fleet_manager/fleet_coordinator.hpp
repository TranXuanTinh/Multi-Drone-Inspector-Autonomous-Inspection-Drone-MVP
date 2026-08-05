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
 * @file fleet_coordinator.hpp
 * @brief Centralized fleet state machine and command dispatcher
 */

#pragma once

#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <multi_drone_msgs/msg/vehicle_status.hpp>
#include <multi_drone_msgs/msg/fleet_status.hpp>
#include <multi_drone_msgs/msg/formation_command.hpp>
#include <multi_drone_msgs/msg/mission_command.hpp>
#include <multi_drone_msgs/srv/register_vehicle.hpp>

namespace multi_drone
{

// Forward declarations
class FormationController;
class CollisionAvoidance;

/**
 * @brief Fleet-wide state machine states
 */
enum class FleetState : uint8_t
{
  IDLE = 0,
  FORMING,
  IN_FORMATION,
  EXECUTING,
  SCATTERING,
  RTL_ALL
};

/**
 * @brief Per-vehicle info stored by the fleet coordinator
 */
struct FleetVehicleInfo
{
  uint8_t vehicle_id;
  std::string namespace_str;
  std::string name;
  std::string role;  // "leader" or "follower"
  multi_drone_msgs::msg::VehicleStatus latest_status;
  bool registered{false};
  bool connected{false};
  std::chrono::steady_clock::time_point last_seen;
};

/**
 * @class FleetCoordinator
 * @brief Central fleet manager node
 *
 * Responsibilities:
 *   1. Track all registered vehicles and their status
 *   2. Manage fleet state machine (IDLE → FORMING → IN_FORMATION → ...)
 *   3. Dispatch formation commands to individual vehicles
 *   4. Monitor inter-vehicle distances for collision avoidance
 *   5. Publish aggregated FleetStatus for dashboard
 */
class FleetCoordinator : public rclcpp::Node
{
public:
  explicit FleetCoordinator(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
  ~FleetCoordinator() override = default;

private:
  // Fleet state
  FleetState fleet_state_{FleetState::IDLE};
  std::map<uint8_t, FleetVehicleInfo> vehicles_;
  std::mutex fleet_mutex_;

  // Formation
  std::unique_ptr<FormationController> formation_controller_;
  std::unique_ptr<CollisionAvoidance> collision_avoidance_;
  std::string current_formation_{"none"};
  float formation_spacing_m_{10.0f};
  float formation_heading_deg_{0.0f};

  // Parameters
  int expected_num_vehicles_;
  double vehicle_timeout_s_;

  // Subscribers
  rclcpp::Subscription<multi_drone_msgs::msg::VehicleStatus>::SharedPtr vehicle_status_sub_;
  rclcpp::Subscription<multi_drone_msgs::msg::FormationCommand>::SharedPtr formation_cmd_sub_;

  // Publishers
  rclcpp::Publisher<multi_drone_msgs::msg::FleetStatus>::SharedPtr fleet_status_pub_;
  rclcpp::Publisher<multi_drone_msgs::msg::MissionCommand>::SharedPtr mission_command_pub_;

  // Services
  rclcpp::Service<multi_drone_msgs::srv::RegisterVehicle>::SharedPtr register_vehicle_srv_;

  // Timers
  rclcpp::TimerBase::SharedPtr status_timer_;
  rclcpp::TimerBase::SharedPtr formation_timer_;

  // Setup
  void setup_parameters();
  void setup_communication();

  // Callbacks
  void on_vehicle_status(const multi_drone_msgs::msg::VehicleStatus::SharedPtr msg);
  void on_formation_command(const multi_drone_msgs::msg::FormationCommand::SharedPtr msg);
  void handle_register_vehicle(
    const std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle::Request> request,
    std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle::Response> response);

  // Fleet operations
  void publish_fleet_status();
  void formation_update_loop();
  void send_command_to_all(uint8_t command, float param1 = 0.0f);
  void send_command_to_vehicle(uint8_t vehicle_id, uint8_t command, float param1 = 0.0f);
  void update_fleet_state();
  float compute_min_separation() const;

  // State helpers
  static std::string fleet_state_to_string(FleetState state);
};

}  // namespace multi_drone
