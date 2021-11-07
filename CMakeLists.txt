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
  ${SRC_DIRECTORY}}/numeric.h
)

#
# Test Build
#
set(BUILD_TEST TRUE)
if(BUILD_TEST)
add_executable(test_bignum ${SRC_DIRECTORY}/test/test_bignum.cc)
target_link_libraries(test_bignum mynum gtest pthread)

add_executable(test_integer ${SRC_DIRECTORY}/test/test_integer.cc)
target_link_libraries(test_integer mynum gtest pthread)

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
  ${SRC_DIRECTORY}/bignum/shrink_zero.cc
  ${SRC_DIRECTORY}/bignum/string_to_bignum.cc
  ${SRC_DIRECTORY}/bignum/bignum_to_string.cc
  ${SRC_DIRECTORY}/bignum/nan.cc
  ${SRC_DIRECTORY}/bignum/zero.cc
  ${SRC_DIRECTORY}/bignum/is_nan.cc
  ${SRC_DIRECTORY}/bignum/is_zero.cc
  ${SRC_DIRECTORY}/bignum/cmp.cc
  ${SRC_DIRECTORY}/bignum/add.cc
  ${SRC_DIRECTORY}/bignum/add2.cc
  ${SRC_DIRECTORY}/bignum/sub.cc
  ${SRC_DIRECTORY}/bignum/sub2.cc
  ${SRC_DIRECTORY}/bignum/mul.cc
  ${SRC_DIRECTORY}/bignum/div.cc
  ${SRC_DIRECTORY}/bignum/div2.cc
  ${SRC_DIRECTORY}/integer/integer.cc
  ${SRC_DIRECTORY}/integer/__xxx_infinite.cc
  ${SRC_DIRECTORY}/integer/equ.cc
  ${SRC_DIRECTORY}/integer/gt.cc
  ${SRC_DIRECTORY}/integer/lt.cc
  ${SRC_DIRECTORY}/integer/ge.cc
  ${SRC_DIRECTORY}/integer/le.cc
  ${SRC_DIRECTORY}/integer/is_zero.cc
  ${SRC_DIRECTORY}/integer/is_one.cc
  ${SRC_DIRECTORY}/integer/is_nan.cc
  ${SRC_DIRECTORY}/integer/is_infinite.cc
  ${SRC_DIRECTORY}/integer/is_none.cc
  ${SRC_DIRECTORY}/integer/is_odd.cc
  ${SRC_DIRECTORY}/integer/is_even.cc
  ${SRC_DIRECTORY}/integer/add.cc
  ${SRC_DIRECTORY}/integer/sub.cc
  ${SRC_DIRECTORY}/integer/mul.cc
  ${SRC_DIRECTORY}/integer/div.cc
  ${SRC_DIRECTORY}/integer/quo.cc
  ${SRC_DIRECTORY}/integer/mod.cc
  ${SRC_DIRECTORY}/integer/abs.cc
  ${SRC_DIRECTORY}/integer/pow.cc
  ${SRC_DIRECTORY}/integer/factorial.cc
  ${SRC_DIRECTORY}/integer/extended_euclidean.cc
  ${SRC_DIRECTORY}/integer/gcd.cc
  ${SRC_DIRECTORY}/integer/lcm.cc
  ${SRC_DIRECTORY}/integer/sgn.cc
  ${SRC_DIRECTORY}/integer/or_bits.cc
  ${SRC_DIRECTORY}/integer/and_bits.cc
  ${SRC_DIRECTORY}/integer/xor_bits.cc
  ${SRC_DIRECTORY}/integer/not_bits.cc
  ${SRC_DIRECTORY}/integer/lshift_bits.cc
  ${SRC_DIRECTORY}/integer/rshift_bits.cc
  ${SRC_DIRECTORY}/integer/copy.cc
  ${SRC_DIRECTORY}/integer/same_digits.cc
  ${SRC_DIRECTORY}/integer/bernoulli_numbers.cc
  ${SRC_DIRECTORY}/integer/euler_numbers.cc
  ${SRC_DIRECTORY}/integer/operator.cc
)
target_link_libraries(${PROJECT_NAME} my)

#
# Enable Test
#
enable_testing()
add_test(NAME test_bignum COMMAND test_bignum)
set_tests_properties(test_bignum PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_integer COMMAND test_integer)
set_tests_properties(test_integer PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")

#
# Install Set
#
INSTALL(TARGETS mynum ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYNUM_HEADERS} DESTINATION include/mynum)