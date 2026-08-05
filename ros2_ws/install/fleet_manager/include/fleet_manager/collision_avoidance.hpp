/**
 * @file collision_avoidance.hpp
 * @brief Inter-vehicle collision avoidance using velocity obstacles
 */

#pragma once

#include <map>
#include <cmath>

#include <Eigen/Dense>

namespace multi_drone
{

/**
 * @brief Simple vehicle state for collision avoidance computation
 */
struct CAVehicleState
{
  uint8_t vehicle_id;
  Eigen::Vector3f position;   // NED local (meters)
  Eigen::Vector3f velocity;   // NED (m/s)
};

/**
 * @class CollisionAvoidance
 * @brief Reactive collision avoidance for multi-vehicle operations
 *
 * Uses a simplified velocity obstacle approach:
 *   - Computes repulsive velocity for each nearby vehicle
 *   - Priority based on vehicle ID (lower ID has priority)
 *   - Fallback: stop in place if no safe velocity exists
 */
class CollisionAvoidance
{
public:
  /**
   * @param min_separation_m Minimum allowed distance between vehicles
   * @param avoidance_radius_m Distance at which avoidance activates
   */
  explicit CollisionAvoidance(
    float min_separation_m = 5.0f,
    float avoidance_radius_m = 15.0f);

  /**
   * @brief Compute adjusted velocity to avoid collisions
   * @param own_id This vehicle's ID
   * @param own_state This vehicle's state
   * @param all_states Map of all vehicle states
   * @param desired_velocity Desired velocity from trajectory planner
   * @return Adjusted velocity that avoids collisions
   */
  Eigen::Vector3f compute_safe_velocity(
    uint8_t own_id,
    const CAVehicleState & own_state,
    const std::map<uint8_t, CAVehicleState> & all_states,
    const Eigen::Vector3f & desired_velocity) const;

  /**
   * @brief Check if any vehicle is within minimum separation
   * @return true if a separation violation exists
   */
  bool check_separation_violation(
    const CAVehicleState & own_state,
    const std::map<uint8_t, CAVehicleState> & all_states) const;

  /**
   * @brief Get closest inter-vehicle distance
   */
  float closest_distance(
    const CAVehicleState & own_state,
    const std::map<uint8_t, CAVehicleState> & all_states) const;

private:
  float min_separation_m_;
  float avoidance_radius_m_;

  Eigen::Vector3f compute_repulsive_velocity(
    const Eigen::Vector3f & own_pos,
    const Eigen::Vector3f & other_pos,
    float distance) const;
};

}  // namespace multi_drone
