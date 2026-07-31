"""
vehicle.launch.py — Launch a single vehicle controller with its safety guard.

Usage:
    ros2 launch vehicle_controller vehicle.launch.py vehicle_id:=0
    ros2 launch vehicle_controller vehicle.launch.py vehicle_id:=1 vehicle_name:=UAV-Bravo
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    vehicle_id = LaunchConfiguration('vehicle_id')
    vehicle_name = LaunchConfiguration('vehicle_name')
    namespace = LaunchConfiguration('namespace')

    return LaunchDescription([
        DeclareLaunchArgument('vehicle_id', default_value='0'),
        DeclareLaunchArgument('vehicle_name', default_value='UAV-0'),
        DeclareLaunchArgument('namespace', default_value='/px4_0'),

        # Offboard Controller
        Node(
            package='vehicle_controller',
            executable='offboard_controller',
            namespace=namespace,
            name='offboard_controller',
            parameters=[{
                'vehicle_id': vehicle_id,
                'vehicle_name': vehicle_name,
                'offboard_rate_hz': 50.0,
                'status_publish_rate_hz': 10.0,
            }],
            output='screen',
        ),

        # Safety Guard
        Node(
            package='vehicle_controller',
            executable='safety_guard',
            namespace=namespace,
            name='safety_guard',
            parameters=[{
                'vehicle_id': vehicle_id,
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
        ),

        # Telemetry Monitor (optional — for standalone monitoring)
        Node(
            package='vehicle_controller',
            executable='telemetry_monitor',
            namespace=namespace,
            name='telemetry_monitor',
            parameters=[{
                'vehicle_id': vehicle_id,
                'vehicle_name': vehicle_name,
                'publish_rate_hz': 10.0,
                'heartbeat_timeout_s': 5.0,
            }],
            output='screen',
            # Not started by default — uncomment if needed
            condition=None,
        ),
    ])
