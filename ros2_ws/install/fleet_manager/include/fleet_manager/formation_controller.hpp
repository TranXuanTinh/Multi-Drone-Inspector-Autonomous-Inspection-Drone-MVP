/**
 * @file formation_controller.hpp
 * @brief Formation geometry computation for multi-vehicle fleet
 */

#pragma once

#include <cmath>
#include <string>
#include <vector>

#include <Eigen/Dense>

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
