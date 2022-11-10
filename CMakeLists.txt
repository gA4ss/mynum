cmake_minimum_required (VERSION 3.5)
project(mynum VERSION 1.0)

# -g allows for gdb debugging
# turn on -03 for best performance
# add_definitions(-std=c++11 -g -O0 -DDEBUG)
# add_definitions(-std=c++11 -O3)
set(DEBUG 1)
if(DEBUG)
message(STATUS "compile debug version.")
add_definitions(-std=c++11 -g -O0 -DDEBUG -Wunused-variable)
else()
message(STATUS "compile release version.")
add_definitions(-std=c++11 -O3 -Wunused-variable)
endif(DEBUG)

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
  ${SRC_DIRECTORY}/compile.h
  ${SRC_DIRECTORY}/exception.h
  ${SRC_DIRECTORY}/debug.h
  ${SRC_DIRECTORY}/mynum.h
)

#
# Float source
#
set(FLOAT_SRC
  ${SRC_DIRECTORY}/float/float.cc
  ${SRC_DIRECTORY}/float/constant.cc
  ${SRC_DIRECTORY}/float/constant_bernoulli_numbers.cc
  ${SRC_DIRECTORY}/float/constant_euler_numbers.cc
  ${SRC_DIRECTORY}/float/abs.cc
  ${SRC_DIRECTORY}/float/ceil.cc
  ${SRC_DIRECTORY}/float/floor.cc
  ${SRC_DIRECTORY}/float/round.cc
  ${SRC_DIRECTORY}/float/factorial.cc
  ${SRC_DIRECTORY}/float/pow.cc
  ${SRC_DIRECTORY}/float/sqrt.cc
  ${SRC_DIRECTORY}/float/exp.cc
  ${SRC_DIRECTORY}/float/ln.cc
  ${SRC_DIRECTORY}/float/log.cc
  ${SRC_DIRECTORY}/float/log2.cc
  ${SRC_DIRECTORY}/float/log10.cc
  ${SRC_DIRECTORY}/float/sin.cc
  ${SRC_DIRECTORY}/float/cos.cc
  ${SRC_DIRECTORY}/float/tan.cc
  ${SRC_DIRECTORY}/float/cot.cc
  ${SRC_DIRECTORY}/float/sec.cc
  ${SRC_DIRECTORY}/float/csc.cc
  ${SRC_DIRECTORY}/float/arcsin.cc
  ${SRC_DIRECTORY}/float/arccos.cc
  ${SRC_DIRECTORY}/float/arctan.cc
  ${SRC_DIRECTORY}/float/arccot.cc
  ${SRC_DIRECTORY}/float/arcsec.cc
  ${SRC_DIRECTORY}/float/arccsc.cc
  ${SRC_DIRECTORY}/float/sinh.cc
  ${SRC_DIRECTORY}/float/cosh.cc
  ${SRC_DIRECTORY}/float/tanh.cc
  ${SRC_DIRECTORY}/float/coth.cc
  ${SRC_DIRECTORY}/float/sech.cc
  ${SRC_DIRECTORY}/float/csch.cc
  ${SRC_DIRECTORY}/float/arcsinh.cc
  ${SRC_DIRECTORY}/float/arccosh.cc
  ${SRC_DIRECTORY}/float/arctanh.cc
  ${SRC_DIRECTORY}/float/arccoth.cc
  ${SRC_DIRECTORY}/float/arcsech.cc
  ${SRC_DIRECTORY}/float/arccsch.cc
  ${SRC_DIRECTORY}/float/erf.cc
  ${SRC_DIRECTORY}/float/erfc.cc
  ${SRC_DIRECTORY}/float/sgn.cc
  ${SRC_DIRECTORY}/float/gamma.cc
  ${SRC_DIRECTORY}/float/fraction.cc
)

#
# Integer source
#
set(INTEGER_SRC
  ${SRC_DIRECTORY}/integer/integer.cc
  ${SRC_DIRECTORY}/integer/abs.cc
  ${SRC_DIRECTORY}/integer/bernoulli_numbers.cc
  ${SRC_DIRECTORY}/integer/euler_numbers.cc
  ${SRC_DIRECTORY}/integer/extended_euclidean.cc
  ${SRC_DIRECTORY}/integer/lcm.cc
  ${SRC_DIRECTORY}/integer/gcd.cc
  ${SRC_DIRECTORY}/integer/and_bits.cc
  ${SRC_DIRECTORY}/integer/or_bits.cc
  ${SRC_DIRECTORY}/integer/not_bits.cc
  ${SRC_DIRECTORY}/integer/xor_bits.cc
  ${SRC_DIRECTORY}/integer/lshift_bits.cc
  ${SRC_DIRECTORY}/integer/rshift_bits.cc
  ${SRC_DIRECTORY}/integer/pow.cc
  ${SRC_DIRECTORY}/integer/factorial.cc
  ${SRC_DIRECTORY}/integer/sgn.cc
)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${SRC_DIRECTORY}/mynum.cc
  ${INTEGER_SRC}
  ${FLOAT_SRC}
)
target_link_libraries(${PROJECT_NAME} mympf mympz my)

#
# Add SubDirectory
#
add_subdirectory(test)
add_subdirectory(tools)

#
# Enable Test
#
enable_testing()
add_test(NAME test_log COMMAND test_log)
set_tests_properties(test_log PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_pow COMMAND test_pow)
set_tests_properties(test_pow PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_factorial COMMAND test_factorial)
set_tests_properties(test_factorial PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_exp COMMAND test_exp)
set_tests_properties(test_exp PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_sqrt COMMAND test_sqrt)
set_tests_properties(test_sqrt PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_trigfunc COMMAND test_trigfunc)
set_tests_properties(test_trigfunc PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_error COMMAND test_error)
set_tests_properties(test_error PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
# add_test(NAME test_float COMMAND test_float)
# set_tests_properties(test_float PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_integer COMMAND test_integer)
set_tests_properties(test_integer PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")


#
# Install Set
#
INSTALL(TARGETS mynum ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYNUM_HEADERS} DESTINATION include/mynum)