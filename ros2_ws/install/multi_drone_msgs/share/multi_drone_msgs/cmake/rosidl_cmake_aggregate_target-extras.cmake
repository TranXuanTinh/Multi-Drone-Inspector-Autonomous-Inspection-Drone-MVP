# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target multi_drone_msgs::multi_drone_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${multi_drone_msgs_TARGETS}.
if(multi_drone_msgs_TARGETS AND NOT TARGET multi_drone_msgs::multi_drone_msgs)
  add_library(multi_drone_msgs::multi_drone_msgs INTERFACE IMPORTED)
  set_target_properties(multi_drone_msgs::multi_drone_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${multi_drone_msgs_TARGETS}")
endif()
