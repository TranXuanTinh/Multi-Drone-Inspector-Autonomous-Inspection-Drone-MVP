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
 * @file fleet_coordinator.cpp
 * @brief Central fleet coordination node
 */

#include "fleet_manager/fleet_coordinator.hpp"
#include "fleet_manager/formation_controller.hpp"
#include "fleet_manager/collision_avoidance.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;

namespace multi_drone
{

FleetCoordinator::FleetCoordinator(const rclcpp::NodeOptions & options)
: Node("fleet_coordinator", options)
{
  formation_controller_ = std::make_unique<FormationController>();
  collision_avoidance_ = std::make_unique<CollisionAvoidance>(5.0f, 15.0f);

  setup_parameters();
  setup_communication();

  RCLCPP_INFO(get_logger(),
    "FleetCoordinator started — expecting %d vehicles", expected_num_vehicles_);
}

void FleetCoordinator::setup_parameters()
{
  this->declare_parameter("expected_num_vehicles", 3);
  this->declare_parameter("vehicle_timeout_s", 5.0);
  this->declare_parameter("status_publish_rate_hz", 5.0);
  this->declare_parameter("formation_update_rate_hz", 10.0);
  this->declare_parameter("default_formation", "line");
  this->declare_parameter("default_spacing_m", 10.0);

  expected_num_vehicles_ = this->get_parameter("expected_num_vehicles").as_int();
  vehicle_timeout_s_ = this->get_parameter("vehicle_timeout_s").as_double();
  formation_spacing_m_ = this->get_parameter("default_spacing_m").as_double();
  current_formation_ = this->get_parameter("default_formation").as_string();
}

void FleetCoordinator::setup_communication()
{
  auto fleet_qos = rclcpp::QoS(10).reliable();

  // Subscribe to vehicle status updates
  vehicle_status_sub_ = this->create_subscription<multi_drone_msgs::msg::VehicleStatus>(
    "/fleet/vehicle_status", fleet_qos,
    std::bind(&FleetCoordinator::on_vehicle_status, this, _1));

  // Subscribe to formation commands
  formation_cmd_sub_ = this->create_subscription<multi_drone_msgs::msg::FormationCommand>(
    "/fleet/formation_command", fleet_qos,
    std::bind(&FleetCoordinator::on_formation_command, this, _1));

  // Publish fleet status
  fleet_status_pub_ = this->create_publisher<multi_drone_msgs::msg::FleetStatus>(
    "/fleet/fleet_status", fleet_qos);

  // Publish mission commands to vehicles
  mission_command_pub_ = this->create_publisher<multi_drone_msgs::msg::MissionCommand>(
    "/fleet/mission_command", fleet_qos);

  // Vehicle registration service
  register_vehicle_srv_ = this->create_service<multi_drone_msgs::srv::RegisterVehicle>(
    "/fleet/register_vehicle",
    std::bind(&FleetCoordinator::handle_register_vehicle, this, _1, _2));

  // Status publish timer
  double status_rate = this->get_parameter("status_publish_rate_hz").as_double();
  auto status_period = std::chrono::duration<double>(1.0 / status_rate);
  status_timer_ = this->create_wall_timer(
    std::chrono::duration_cast<std::chrono::nanoseconds>(status_period),
    std::bind(&FleetCoordinator::publish_fleet_status, this));

  // Formation update timer
  double formation_rate = this->get_parameter("formation_update_rate_hz").as_double();
  auto formation_period = std::chrono::duration<double>(1.0 / formation_rate);
  formation_timer_ = this->create_wall_timer(
    std::chrono::duration_cast<std::chrono::nanoseconds>(formation_period),
    std::bind(&FleetCoordinator::formation_update_loop, this));
}

void FleetCoordinator::on_vehicle_status(
  const multi_drone_msgs::msg::VehicleStatus::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(fleet_mutex_);

  uint8_t vid = msg->vehicle_id;

  // Auto-register if not known
  if (vehicles_.find(vid) == vehicles_.end()) {
    FleetVehicleInfo info;
    info.vehicle_id = vid;
    info.namespace_str = msg->vehicle_namespace;
    info.name = msg->name;
    info.role = (vid == 0) ? "leader" : "follower";
    info.registered = true;
    vehicles_[vid] = info;
    RCLCPP_INFO(get_logger(), "Auto-registered vehicle %d (%s)", vid, msg->name.c_str());
  }

  vehicles_[vid].latest_status = *msg;
  vehicles_[vid].connected = msg->connected;
  vehicles_[vid].last_seen = std::chrono::steady_clock::now();
}

void FleetCoordinator::on_formation_command(
  const multi_drone_msgs::msg::FormationCommand::SharedPtr msg)
{
  RCLCPP_INFO(get_logger(),
    "Formation command: pattern='%s', spacing=%.1fm, heading=%.1f°",
    msg->pattern.c_str(), msg->spacing_m, msg->heading_deg);

  std::lock_guard<std::mutex> lock(fleet_mutex_);
  current_formation_ = msg->pattern;
  formation_spacing_m_ = msg->spacing_m;
  formation_heading_deg_ = msg->heading_deg;

  if (fleet_state_ == FleetState::IDLE || fleet_state_ == FleetState::IN_FORMATION) {
    fleet_state_ = FleetState::FORMING;
    RCLCPP_INFO(get_logger(), "Fleet state → FORMING");
  }
}

void FleetCoordinator::handle_register_vehicle(
  const std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle::Request> request,
  std::shared_ptr<multi_drone_msgs::srv::RegisterVehicle::Response> response)
{
  std::lock_guard<std::mutex> lock(fleet_mutex_);

  FleetVehicleInfo info;
  info.vehicle_id = request->vehicle_id;
  info.namespace_str = request->vehicle_namespace;
  info.name = request->name;
  info.role = request->role;
  info.registered = true;
  info.last_seen = std::chrono::steady_clock::now();

  vehicles_[request->vehicle_id] = info;

  response->success = true;
  response->message = "Vehicle " + request->name + " registered with ID " +
    std::to_string(request->vehicle_id);

  RCLCPP_INFO(get_logger(), "Registered vehicle: %s (ID=%d, role=%s)",
    request->name.c_str(), request->vehicle_id, request->role.c_str());
}

void FleetCoordinator::publish_fleet_status()
{
  auto msg = multi_drone_msgs::msg::FleetStatus();

  std::lock_guard<std::mutex> lock(fleet_mutex_);

  msg.fleet_state = fleet_state_to_string(fleet_state_);
  msg.current_formation = current_formation_;
  msg.formation_spacing_m = formation_spacing_m_;
  msg.formation_heading_deg = formation_heading_deg_;

  msg.num_vehicles_registered = 0;
  msg.num_vehicles_connected = 0;
  msg.num_vehicles_armed = 0;
  msg.num_vehicles_airborne = 0;

  for (const auto & [vid, info] : vehicles_) {
    msg.vehicles.push_back(info.latest_status);
    msg.num_vehicles_registered++;
    if (info.connected) {
      msg.num_vehicles_connected++;
    }
    if (info.latest_status.armed) {
      msg.num_vehicles_armed++;
    }
    if (info.latest_status.relative_altitude_m > 1.0f) {
      msg.num_vehicles_airborne++;
    }
  }

  msg.min_inter_vehicle_distance_m = compute_min_separation();
  msg.collision_warning =
    (msg.min_inter_vehicle_distance_m<5.0f && msg.min_inter_vehicle_distance_m>0.0f);
  msg.stamp = this->now();

  fleet_status_pub_->publish(msg);
}

void FleetCoordinator::formation_update_loop()
{
  std::lock_guard<std::mutex> lock(fleet_mutex_);

  if (fleet_state_ != FleetState::FORMING && fleet_state_ != FleetState::IN_FORMATION) {
    return;
  }

  if (vehicles_.empty()) {
    return;
  }

  // Find leader vehicle
  Eigen::Vector3f leader_pos(0.0f, 0.0f, 0.0f);
  float leader_yaw = 0.0f;

  for (const auto & [vid, info] : vehicles_) {
    if (info.role == "leader") {
      leader_pos = Eigen::Vector3f(
        info.latest_status.local_x,
        info.latest_status.local_y,
        info.latest_status.local_z);
      leader_yaw = info.latest_status.yaw_deg * M_PI / 180.0f;
      break;
    }
  }

  // Compute formation targets
  auto targets = formation_controller_->compute_targets(
    leader_pos, leader_yaw,
    current_formation_,
    static_cast<int>(vehicles_.size()),
    formation_spacing_m_);

  // Send position setpoints to each vehicle
  for (const auto & target : targets) {
    auto cmd = multi_drone_msgs::msg::MissionCommand();
    cmd.command = multi_drone_msgs::msg::MissionCommand::CMD_GOTO;
    cmd.target_vehicle_id = target.vehicle_id;
    cmd.param1 = target.x;
    cmd.param2 = target.y;
    cmd.param3 = target.z;
    cmd.param4 = target.yaw;
    cmd.stamp = this->now();

    mission_command_pub_->publish(cmd);
  }

  // Check if all vehicles have reached formation positions
  // (simplified: check within 2m of target)
  bool all_in_position = true;
  for (const auto & target : targets) {
    auto it = vehicles_.find(target.vehicle_id);
    if (it != vehicles_.end()) {
      float dx = it->second.latest_status.local_x - target.x;
      float dy = it->second.latest_status.local_y - target.y;
      float dist = std::sqrt(dx * dx + dy * dy);
      if (dist > 2.0f) {
        all_in_position = false;
        break;
      }
    }
  }

  if (fleet_state_ == FleetState::FORMING && all_in_position) {
    fleet_state_ = FleetState::IN_FORMATION;
    RCLCPP_INFO(get_logger(), "Fleet state → IN_FORMATION");
  }
}

void FleetCoordinator::send_command_to_all(uint8_t command, float param1)
{
  auto msg = multi_drone_msgs::msg::MissionCommand();
  msg.command = command;
  msg.target_vehicle_id = 255;  // Broadcast
  msg.param1 = param1;
  msg.stamp = this->now();
  mission_command_pub_->publish(msg);
}

void FleetCoordinator::send_command_to_vehicle(uint8_t vehicle_id, uint8_t command, float param1)
{
  auto msg = multi_drone_msgs::msg::MissionCommand();
  msg.command = command;
  msg.target_vehicle_id = vehicle_id;
  msg.param1 = param1;
  msg.stamp = this->now();
  mission_command_pub_->publish(msg);
}

float FleetCoordinator::compute_min_separation() const
{
  float min_dist = std::numeric_limits<float>::max();
  std::vector<std::pair<float, float>> positions;

  for (const auto & [vid, info] : vehicles_) {
    positions.push_back({info.latest_status.local_x, info.latest_status.local_y});
  }

  for (size_t i = 0; i < positions.size(); ++i) {
    for (size_t j = i + 1; j < positions.size(); ++j) {
      float dx = positions[i].first - positions[j].first;
      float dy = positions[i].second - positions[j].second;
      float dist = std::sqrt(dx * dx + dy * dy);
      min_dist = std::min(min_dist, dist);
    }
  }

  return (min_dist == std::numeric_limits<float>::max()) ? 0.0f : min_dist;
}

std::string FleetCoordinator::fleet_state_to_string(FleetState state)
{
  switch (state) {
    case FleetState::IDLE:           return "IDLE";
    case FleetState::FORMING:        return "FORMING";
    case FleetState::IN_FORMATION:   return "IN_FORMATION";
    case FleetState::EXECUTING:      return "EXECUTING";
    case FleetState::SCATTERING:     return "SCATTERING";
    case FleetState::RTL_ALL:        return "RTL_ALL";
    default: return "UNKNOWN";
  }
}

}  // namespace multi_drone

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<multi_drone::FleetCoordinator>());
  rclcpp::shutdown();
  return 0;
}
