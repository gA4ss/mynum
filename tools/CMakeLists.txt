cmake_minimum_required (VERSION 3.5)
project(mynum_tool VERSION 1.0)

# -g allows for gdb debugging
# turn on -03 for best performance
# add_definitions(-std=c++11 -g -O0 -Wunused-variable)
add_definitions(-std=c++11 -g -O0 -DDEBUG -Wunused-variable)
# add_definitions(-std=c++11 -O3 -Wunused-variable)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#
# Sub modules directories
#
set(SRC_DIRECTORY .)

#
# Mympz include path
#
include_directories(
  ../src
)

#
# System include path and link path
#
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

#
# Main Test
#
add_executable(generate_bernoulli_numbers ${SRC_DIRECTORY}/generate_bernoulli_numbers.cc)
target_link_libraries(generate_bernoulli_numbers mynum gtest pthread)
add_executable(generate_euler_numbers ${SRC_DIRECTORY}/generate_euler_numbers.cc)
target_link_libraries(generate_euler_numbers mynum gtest pthread)

