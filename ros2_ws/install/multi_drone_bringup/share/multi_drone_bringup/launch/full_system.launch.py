"""
full_system.launch.py — Launch the complete multi-UAV system.

Starts N vehicle controllers, fleet coordinator, and safety guards.
PX4 SITL instances and Micro XRCE-DDS Agent must be running separately.

Usage:
    ros2 launch multi_drone_bringup full_system.launch.py num_vehicles:=3
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_vehicle_nodes(context, *args, **kwargs):
    """Dynamically generate vehicle controller nodes based on num_vehicles."""
    num_vehicles = int(LaunchConfiguration('num_vehicles').perform(context))
    nodes = []

    vehicle_names = ['UAV-Alpha', 'UAV-Bravo', 'UAV-Charlie', 'UAV-Delta',
                     'UAV-Echo', 'UAV-Foxtrot', 'UAV-Golf', 'UAV-Hotel']

    for i in range(num_vehicles):
        namespace = f'/px4_{i}'
        vehicle_name = vehicle_names[i] if i < len(vehicle_names) else f'UAV-{i}'

        # Offboard Controller (one per vehicle)
        nodes.append(Node(
            package='vehicle_controller',
            executable='offboard_controller',
            namespace=namespace,
            name='offboard_controller',
            parameters=[{
                'vehicle_id': i,
                'vehicle_name': vehicle_name,
                'offboard_rate_hz': 50.0,
                'status_publish_rate_hz': 10.0,
            }],
            output='screen',
        ))

        # Safety Guard (one per vehicle)
        nodes.append(Node(
            package='vehicle_controller',
            executable='safety_guard',
            namespace=namespace,
            name='safety_guard',
            parameters=[{
                'vehicle_id': i,
                'geofence_radius_m': 500.0,
                'max_altitude_m': 120.0,
                'min_battery_pct': 20.0,
                'critical_battery_pct': 10.0,
                'min_separation_m': 5.0,
                'home_lat': 47.397742,
                'home_lon': 8.545594,
                'safety_check_rate_hz': 5.0,
            }],
            output='screen',
        ))

    return nodes


def generate_launch_description():
    return LaunchDescription([
        # Arguments
        DeclareLaunchArgument(
            'num_vehicles',
            default_value='3',
            description='Number of UAV vehicles to control',
        ),

        # Fleet Coordinator (single instance)
        Node(
            package='fleet_manager',
            executable='fleet_coordinator',
            name='fleet_coordinator',
            parameters=[{
                'expected_num_vehicles': 3,
                'vehicle_timeout_s': 5.0,
                'status_publish_rate_hz': 5.0,
                'formation_update_rate_hz': 10.0,
                'default_formation': 'line',
                'default_spacing_m': 10.0,
            }],
            output='screen',
        ),

        # Dynamic vehicle node generation
        OpaqueFunction(function=generate_vehicle_nodes),
    ])
