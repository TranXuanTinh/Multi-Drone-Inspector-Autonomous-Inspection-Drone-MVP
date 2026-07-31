cmake_minimum_required(VERSION 3.8)
project(vehicle_controller)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# C++17 required for structured bindings, optional, etc.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Dependencies ──────────────────────────────────────────
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(px4_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(multi_drone_msgs REQUIRED)
find_package(Eigen3 REQUIRED)

# ── Include directories ──────────────────────────────────
include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
)

# ── Offboard Controller Node ─────────────────────────────
add_executable(offboard_controller
  src/offboard_controller.cpp
)
ament_target_dependencies(offboard_controller
  rclcpp
  px4_msgs
  geometry_msgs
  multi_drone_msgs
)

# ── Telemetry Monitor Node ───────────────────────────────
add_executable(telemetry_monitor
  src/telemetry_monitor.cpp
)
ament_target_dependencies(telemetry_monitor
  rclcpp
  px4_msgs
  multi_drone_msgs
)

# ── Safety Guard Node ────────────────────────────────────
add_executable(safety_guard
  src/safety_guard.cpp
)
ament_target_dependencies(safety_guard
  rclcpp
  px4_msgs
  multi_drone_msgs
)

# ── Install ──────────────────────────────────────────────
install(TARGETS
  offboard_controller
  telemetry_monitor
  safety_guard
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  include/
  DESTINATION include
)

install(DIRECTORY
  launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(DIRECTORY
  config/
  DESTINATION share/${PROJECT_NAME}/config
)

# ── Testing ──────────────────────────────────────────────
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  find_package(ament_cmake_gtest REQUIRED)
  # ament_add_gtest(test_offboard_controller test/test_offboard_controller.cpp)
  # ament_target_dependencies(test_offboard_controller rclcpp px4_msgs)
endif()

ament_package()
