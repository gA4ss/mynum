cmake_minimum_required (VERSION 3.5)
project(mynum_test VERSION 1.0)

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
add_executable(test_log ${SRC_DIRECTORY}/test_log.cc)
target_link_libraries(test_log mynum gtest pthread)
add_executable(test_pow ${SRC_DIRECTORY}/test_pow.cc)
target_link_libraries(test_pow mynum gtest pthread)
add_executable(test_factorial ${SRC_DIRECTORY}/test_factorial.cc)
target_link_libraries(test_factorial mynum gtest pthread)
add_executable(test_exp ${SRC_DIRECTORY}/test_exp.cc)
target_link_libraries(test_exp mynum gtest pthread)
add_executable(test_sqrt ${SRC_DIRECTORY}/test_sqrt.cc)
target_link_libraries(test_sqrt mynum gtest pthread)
add_executable(test_trigfunc ${SRC_DIRECTORY}/test_trigfunc.cc)
target_link_libraries(test_trigfunc mynum gtest pthread)
add_executable(test_hyperfunc ${SRC_DIRECTORY}/test_hyperfunc.cc)
target_link_libraries(test_hyperfunc mynum gtest pthread)
add_executable(test_extended_euclidean ${SRC_DIRECTORY}/test_extended_euclidean.cc)
target_link_libraries(test_extended_euclidean mynum gtest pthread)
add_executable(test_error ${SRC_DIRECTORY}/test_error.cc)
target_link_libraries(test_error mynum gtest pthread)
add_executable(test_integer ${SRC_DIRECTORY}/test_integer.cc)
target_link_libraries(test_integer mynum gtest pthread)
add_executable(test_fraction ${SRC_DIRECTORY}/test_fraction.cc)
target_link_libraries(test_fraction mynum gtest pthread)
add_executable(test_number ${SRC_DIRECTORY}/test_number.cc)
target_link_libraries(test_number mynum gtest pthread)
add_executable(test_gcd ${SRC_DIRECTORY}/test_gcd.cc)
target_link_libraries(test_gcd mynum gtest pthread)
# add_executable(test_float ${SRC_DIRECTORY}/test_float.cc)
# target_link_libraries(test_float mynum gtest pthread)
add_executable(test_cmath ${SRC_DIRECTORY}/misc/test_cmath.cc)
