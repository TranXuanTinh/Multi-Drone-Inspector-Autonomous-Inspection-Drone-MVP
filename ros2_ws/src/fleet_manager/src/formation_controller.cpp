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
 * @file formation_controller.cpp
 * @brief Formation geometry computation for multi-vehicle fleet
 */

#include "fleet_manager/formation_controller.hpp"

#include <algorithm>

namespace multi_drone
{

std::vector<FormationTarget> FormationController::compute_targets(
  const Eigen::Vector3f & leader_pos,
  float leader_yaw,
  const std::string & pattern,
  int num_vehicles,
  float spacing_m,
  float altitude_offset_m) const
{
  std::vector<FormationTarget> targets;

  if (pattern == "line") {
    targets = line_formation(leader_pos, leader_yaw, num_vehicles, spacing_m);
  } else if (pattern == "v_formation") {
    targets = v_formation(leader_pos, leader_yaw, num_vehicles, spacing_m);
  } else if (pattern == "circle") {
    targets = circle_formation(leader_pos, leader_yaw, num_vehicles, spacing_m);
  } else if (pattern == "diamond") {
    targets = diamond_formation(leader_pos, leader_yaw, num_vehicles, spacing_m);
  } else {
    // Default to line
    targets = line_formation(leader_pos, leader_yaw, num_vehicles, spacing_m);
  }

  // Apply altitude offset if specified
  if (std::abs(altitude_offset_m) > 0.01f) {
    for (size_t i = 0; i < targets.size(); ++i) {
      targets[i].z -= static_cast<float>(i) * altitude_offset_m;  // NED: more negative = higher
    }
  }

  return targets;
}

std::vector<FormationTarget> FormationController::line_formation(
  const Eigen::Vector3f & leader_pos,
  float leader_yaw,
  int num_vehicles,
  float spacing_m) const
{
  std::vector<FormationTarget> targets;

  // Line perpendicular to heading direction
  // Leader at center, followers evenly spaced
  float cos_yaw = std::cos(leader_yaw);
  float sin_yaw = std::sin(leader_yaw);

  // Perpendicular direction (right of heading in NED)
  float perp_x = sin_yaw;
  float perp_y = cos_yaw;

  for (int i = 0; i < num_vehicles; ++i) {
    FormationTarget target;
    target.vehicle_id = static_cast<uint8_t>(i);
    target.yaw = leader_yaw;

    // Offset from center: i=0 is leader (center), others spread out
    float offset = 0.0f;
    if (i > 0) {
      // Alternate left and right: 1→right, 2→left, 3→right, ...
      int side = (i % 2 == 1) ? 1 : -1;
      int rank = (i + 1) / 2;
      offset = side * rank * spacing_m;
    }

    target.x = leader_pos.x() + offset * perp_x;
    target.y = leader_pos.y() + offset * perp_y;
    target.z = leader_pos.z();

    targets.push_back(target);
  }

  return targets;
}

std::vector<FormationTarget> FormationController::v_formation(
  const Eigen::Vector3f & leader_pos,
  float leader_yaw,
  int num_vehicles,
  float spacing_m,
  float angle_deg) const
{
  std::vector<FormationTarget> targets;

  float angle_rad = angle_deg * M_PI / 180.0f;
  float cos_yaw = std::cos(leader_yaw);
  float sin_yaw = std::sin(leader_yaw);

  // Leader at the apex
  FormationTarget leader;
  leader.vehicle_id = 0;
  leader.x = leader_pos.x();
  leader.y = leader_pos.y();
  leader.z = leader_pos.z();
  leader.yaw = leader_yaw;
  targets.push_back(leader);

  for (int i = 1; i < num_vehicles; ++i) {
    FormationTarget target;
    target.vehicle_id = static_cast<uint8_t>(i);
    target.yaw = leader_yaw;

    int side = (i % 2 == 1) ? 1 : -1;
    int rank = (i + 1) / 2;

    // Offset behind and to the side
    float back_offset = rank * spacing_m * std::cos(angle_rad);
    float side_offset = side * rank * spacing_m * std::sin(angle_rad);

    // Rotate offsets by heading
    // "Behind" in heading direction = negative forward
    float forward_x = cos_yaw;
    float forward_y = sin_yaw;
    float right_x = sin_yaw;
    float right_y = -cos_yaw;

    target.x = leader_pos.x() - back_offset * forward_x + side_offset * right_x;
    target.y = leader_pos.y() - back_offset * forward_y + side_offset * right_y;
    target.z = leader_pos.z();

    targets.push_back(target);
  }

  return targets;
}

std::vector<FormationTarget> FormationController::circle_formation(
  const Eigen::Vector3f & center_pos,
  float center_yaw,
  int num_vehicles,
  float radius_m) const
{
  (void)center_yaw;  // Circle doesn't depend on heading
  std::vector<FormationTarget> targets;

  for (int i = 0; i < num_vehicles; ++i) {
    FormationTarget target;
    target.vehicle_id = static_cast<uint8_t>(i);

    float angle = 2.0f * M_PI * i / num_vehicles;
    target.x = center_pos.x() + radius_m * std::cos(angle);
    target.y = center_pos.y() + radius_m * std::sin(angle);
    target.z = center_pos.z();

    // Each vehicle faces the center
    target.yaw = angle + M_PI;  // Face inward
    if (target.yaw > M_PI) {
      target.yaw -= 2.0f * M_PI;
    }

    targets.push_back(target);
  }

  return targets;
}

std::vector<FormationTarget> FormationController::diamond_formation(
  const Eigen::Vector3f & leader_pos,
  float leader_yaw,
  int num_vehicles,
  float spacing_m) const
{
  std::vector<FormationTarget> targets;

  float cos_yaw = std::cos(leader_yaw);
  float sin_yaw = std::sin(leader_yaw);

  // Diamond: leader front, one left, one right, one back
  // For more than 4, add inner ring

  struct Offset { float forward; float right; };

  // Standard diamond offsets (relative to leader)
  std::vector<Offset> offsets = {
    {0.0f, 0.0f},                        // Leader: front
    {-spacing_m, -spacing_m * 0.7f},     // Left wing
    {-spacing_m, spacing_m * 0.7f},      // Right wing
    {-spacing_m * 2.0f, 0.0f},           // Tail
  };

  // Extend for additional vehicles
  for (int i = 4; i < num_vehicles; ++i) {
    float rank = static_cast<float>((i - 3 + 1) / 2 + 1);
    int side = (i % 2 == 0) ? -1 : 1;
    offsets.push_back({-rank * spacing_m, side * rank * spacing_m * 0.5f});
  }

  for (int i = 0; i < std::min(num_vehicles, static_cast < int > (offsets.size())); ++i) {
    FormationTarget target;
    target.vehicle_id = static_cast<uint8_t>(i);
    target.yaw = leader_yaw;

    float fwd = offsets[i].forward;
    float rgt = offsets[i].right;

    target.x = leader_pos.x() + fwd * cos_yaw + rgt * sin_yaw;
    target.y = leader_pos.y() + fwd * sin_yaw - rgt * cos_yaw;
    target.z = leader_pos.z();

    targets.push_back(target);
  }

  return targets;
}

std::vector<std::string> FormationController::available_patterns()
{
  return {"line", "v_formation", "circle", "diamond"};
}

}  // namespace multi_drone
