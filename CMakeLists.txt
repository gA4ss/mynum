cmake_minimum_required (VERSION 3.5)
project(mynum VERSION 1.0)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++11 -g -O0)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#
# Sub modules directories
#
set(SRC_DIRECTORY ./src/)

#
# Mynum include path
#
include_directories(
  ./
)

#
# System include path and link path
#
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

#
# Mynum public header file
#
set(MYNUM_HEADERS
  ${SRC_DIRECTORY}/common.h
  ${SRC_DIRECTORY}}/exception.h
  ${SRC_DIRECTORY}}/bignum.h
)

#
# Test Build
#
set(BUILD_TEST TRUE)
if(BUILD_TEST)
add_executable(test_bignum ${SRC_DIRECTORY}/test/test_bignum.cc)
target_link_libraries(test_bignum mynum gtest pthread)

# add_executable(test_numeric ${SRC_DIRECTORY}/test/test_numeric.cc)
# target_link_libraries(test_numeric mynum gtest pthread)

# add_executable(test_bernoulli_numbers ${SRC_DIRECTORY}/test/test_bernoulli_numbers.cc)
# target_link_libraries(test_bernoulli_numbers mynum my uuid gtest pthread)

# add_executable(test_euler_numbers ${SRC_DIRECTORY}/test/test_euler_numbers.cc)
# target_link_libraries(test_euler_numbers mynum my uuid gtest pthread)
endif(BUILD_TEST)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${SRC_DIRECTORY}/common.cc
  ${SRC_DIRECTORY}/bignum.cc
  ${SRC_DIRECTORY}/bignum_add.cc
  ${SRC_DIRECTORY}/bignum_sub.cc
  ${SRC_DIRECTORY}/bignum_mul.cc
  ${SRC_DIRECTORY}/bignum_div.cc
)
target_link_libraries(${PROJECT_NAME} my)

#
# Enable Test
#
enable_testing()
add_test(NAME test_bignum COMMAND test_bignum)
set_tests_properties(test_bignum PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
# add_test(NAME test_numeric COMMAND test_numeric)
# set_tests_properties(test_numeric PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")

#
# Install Set
#
INSTALL(TARGETS mynum ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYNUM_HEADERS} DESTINATION include/mynum)