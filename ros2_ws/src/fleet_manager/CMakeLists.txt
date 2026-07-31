cmake_minimum_required(VERSION 3.8)
project(fleet_manager)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ── Dependencies ──────────────────────────────────────────
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(multi_drone_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
)

# ── Fleet Coordinator Node ───────────────────────────────
add_executable(fleet_coordinator
  src/fleet_coordinator.cpp
  src/formation_controller.cpp
  src/collision_avoidance.cpp
)
ament_target_dependencies(fleet_coordinator
  rclcpp
  multi_drone_msgs
  geometry_msgs
)
target_link_libraries(fleet_coordinator Eigen3::Eigen)

# ── Install ──────────────────────────────────────────────
install(TARGETS
  fleet_coordinator
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY launch/ DESTINATION share/${PROJECT_NAME}/launch)
install(DIRECTORY config/ DESTINATION share/${PROJECT_NAME}/config)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
