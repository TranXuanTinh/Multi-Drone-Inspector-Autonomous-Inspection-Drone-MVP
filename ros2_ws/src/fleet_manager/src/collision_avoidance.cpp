/**
 * @file collision_avoidance.cpp
 * @brief Reactive collision avoidance using potential fields
 */

#include "fleet_manager/collision_avoidance.hpp"

#include <algorithm>
#include <cmath>

namespace multi_drone
{

CollisionAvoidance::CollisionAvoidance(
  float min_separation_m,
  float avoidance_radius_m)
: min_separation_m_(min_separation_m),
  avoidance_radius_m_(avoidance_radius_m)
{
}

Eigen::Vector3f CollisionAvoidance::compute_safe_velocity(
  uint8_t own_id,
  const CAVehicleState & own_state,
  const std::map<uint8_t, CAVehicleState> & all_states,
  const Eigen::Vector3f & desired_velocity) const
{
  Eigen::Vector3f adjusted_velocity = desired_velocity;
  bool needs_avoidance = false;

  for (const auto & [vid, other_state] : all_states) {
    if (vid == own_id) {
      continue;
    }

    float distance = (own_state.position - other_state.position).norm();

    // Only consider vehicles within avoidance radius
    if (distance < avoidance_radius_m_ && distance > 0.01f) {
      // Compute repulsive velocity
      Eigen::Vector3f repulsive = compute_repulsive_velocity(
        own_state.position, other_state.position, distance);

      // Scale repulsion: stronger when closer
      float scale = 1.0f - (distance / avoidance_radius_m_);
      scale = std::max(0.0f, std::min(1.0f, scale));

      // Priority: lower vehicle_id has right of way
      // If we have lower ID, reduce our avoidance (other vehicle should move)
      if (own_id < vid) {
        scale *= 0.3f;  // We have priority, slight adjustment
      }

      adjusted_velocity += repulsive * scale;
      needs_avoidance = true;
    }

    // Emergency stop if too close
    if (distance < min_separation_m_ * 0.5f && distance > 0.01f) {
      // Full stop — return zero velocity
      return Eigen::Vector3f::Zero();
    }
  }

  if (needs_avoidance) {
    // Limit the adjusted velocity magnitude to not exceed desired
    float desired_speed = desired_velocity.norm();
    float adjusted_speed = adjusted_velocity.norm();
    if (adjusted_speed > desired_speed * 1.5f && desired_speed > 0.01f) {
      adjusted_velocity = adjusted_velocity.normalized() * desired_speed;
    }
  }

  return adjusted_velocity;
}

bool CollisionAvoidance::check_separation_violation(
  const CAVehicleState & own_state,
  const std::map<uint8_t, CAVehicleState> & all_states) const
{
  for (const auto & [vid, other_state] : all_states) {
    if (vid == own_state.vehicle_id) {
      continue;
    }

    float distance = (own_state.position - other_state.position).norm();
    if (distance < min_separation_m_) {
      return true;
    }
  }
  return false;
}

float CollisionAvoidance::closest_distance(
  const CAVehicleState & own_state,
  const std::map<uint8_t, CAVehicleState> & all_states) const
{
  float min_dist = std::numeric_limits<float>::max();

  for (const auto & [vid, other_state] : all_states) {
    if (vid == own_state.vehicle_id) {
      continue;
    }

    float distance = (own_state.position - other_state.position).norm();
    min_dist = std::min(min_dist, distance);
  }

  return min_dist;
}

Eigen::Vector3f CollisionAvoidance::compute_repulsive_velocity(
  const Eigen::Vector3f & own_pos,
  const Eigen::Vector3f & other_pos,
  float distance) const
{
  // Direction away from the other vehicle
  Eigen::Vector3f direction = (own_pos - other_pos).normalized();

  // Repulsive force magnitude: inverse square law
  // Capped to avoid singularities
  float safe_dist = std::max(distance, 0.5f);
  float magnitude = (min_separation_m_ * min_separation_m_) / (safe_dist * safe_dist);
  magnitude = std::min(magnitude, 5.0f);  // Cap max repulsion velocity

  return direction * magnitude;
}

}  // namespace multi_drone
