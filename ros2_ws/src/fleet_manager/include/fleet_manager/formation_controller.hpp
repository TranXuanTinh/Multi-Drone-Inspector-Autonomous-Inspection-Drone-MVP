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
 * @file formation_controller.hpp
 * @brief Formation geometry computation for multi-vehicle fleet
 */

#pragma once

#include <Eigen/Dense>
#include <cmath>
#include <string>
#include <vector>

namespace multi_drone
{

/**
 * @brief Target position for a single vehicle in formation
 */
struct FormationTarget
{
  uint8_t vehicle_id;
  float x;  // NED local position (meters)
  float y;
  float z;
  float yaw;  // radians
};

/**
 * @class FormationController
 * @brief Computes per-vehicle positions for various formation patterns
 *
 * Given a leader position and formation geometry, computes target
 * positions for all follower vehicles.
 */
class FormationController
{
public:
  FormationController() = default;

  /**
   * @brief Compute formation targets for all vehicles
   * @param leader_pos Leader position [x, y, z] in NED
   * @param leader_yaw Leader heading in radians
   * @param pattern Formation pattern name
   * @param num_vehicles Total number of vehicles (including leader)
   * @param spacing_m Inter-vehicle distance
   * @param altitude_offset_m Per-vehicle altitude stagger
   * @return Vector of target positions for each vehicle
   */
  std::vector<FormationTarget> compute_targets(
    const Eigen::Vector3f & leader_pos,
    float leader_yaw,
    const std::string & pattern,
    int num_vehicles,
    float spacing_m,
    float altitude_offset_m = 0.0f) const;

  // Individual pattern generators
  std::vector<FormationTarget> line_formation(
    const Eigen::Vector3f & leader_pos,
    float leader_yaw,
    int num_vehicles,
    float spacing_m) const;

  std::vector<FormationTarget> v_formation(
    const Eigen::Vector3f & leader_pos,
    float leader_yaw,
    int num_vehicles,
    float spacing_m,
    float angle_deg = 30.0f) const;

  std::vector<FormationTarget> circle_formation(
    const Eigen::Vector3f & center_pos,
    float center_yaw,
    int num_vehicles,
    float radius_m) const;

  std::vector<FormationTarget> diamond_formation(
    const Eigen::Vector3f & leader_pos,
    float leader_yaw,
    int num_vehicles,
    float spacing_m) const;

  /** @brief List available formation pattern names */
  static std::vector<std::string> available_patterns();
};

}  // namespace multi_drone
