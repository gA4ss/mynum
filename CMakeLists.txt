cmake_minimum_required (VERSION 3.5)
project(mynum VERSION 1.0)

if(DEBUG)
message(STATUS "compile debug version.")
add_definitions(-DDEBUG)
set(CXX_FLAGS "-std=c++14 -g -O0 -Wall -Wunused-variable")
else()
message(STATUS "compile release version.")
set(CXX_FLAGS "-std=c++14 -O3 -Wall -Wunused-variable")
endif(DEBUG)

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
  ${SRC_DIRECTORY}/mp.h
  ${SRC_DIRECTORY}/real.h
  ${SRC_DIRECTORY}/complex.h
  ${SRC_DIRECTORY}/number.h
  ${SRC_DIRECTORY}/mynum.h
  ${SRC_DIRECTORY}/wrapper.h
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
# Real source
#
set(REAL_SRC
  ${SRC_DIRECTORY}/real/real.cc
  ${SRC_DIRECTORY}/real/is_zero.cc
  ${SRC_DIRECTORY}/real/is_one.cc
  ${SRC_DIRECTORY}/real/add.cc
  ${SRC_DIRECTORY}/real/sub.cc
  ${SRC_DIRECTORY}/real/mul.cc
  ${SRC_DIRECTORY}/real/div.cc
  ${SRC_DIRECTORY}/real/mod.cc
  ${SRC_DIRECTORY}/real/cmp.cc
  ${SRC_DIRECTORY}/real/abs.cc
  ${SRC_DIRECTORY}/real/ceil.cc
  ${SRC_DIRECTORY}/real/floor.cc
  ${SRC_DIRECTORY}/real/round.cc
  ${SRC_DIRECTORY}/real/exp.cc
  ${SRC_DIRECTORY}/real/pow.cc
  ${SRC_DIRECTORY}/real/ln.cc
  ${SRC_DIRECTORY}/real/log.cc
  ${SRC_DIRECTORY}/real/log2.cc
  ${SRC_DIRECTORY}/real/log10.cc
  ${SRC_DIRECTORY}/real/sqrt.cc
  ${SRC_DIRECTORY}/real/sin.cc
  ${SRC_DIRECTORY}/real/cos.cc
  ${SRC_DIRECTORY}/real/tan.cc
  ${SRC_DIRECTORY}/real/cot.cc
  ${SRC_DIRECTORY}/real/sec.cc
  ${SRC_DIRECTORY}/real/csc.cc
  ${SRC_DIRECTORY}/real/arcsin.cc
  ${SRC_DIRECTORY}/real/arccos.cc
  ${SRC_DIRECTORY}/real/arctan.cc
  ${SRC_DIRECTORY}/real/arccot.cc
  ${SRC_DIRECTORY}/real/arcsec.cc
  ${SRC_DIRECTORY}/real/arccsc.cc
  ${SRC_DIRECTORY}/real/sinh.cc
  ${SRC_DIRECTORY}/real/cosh.cc
  ${SRC_DIRECTORY}/real/tanh.cc
  ${SRC_DIRECTORY}/real/coth.cc
  ${SRC_DIRECTORY}/real/sech.cc
  ${SRC_DIRECTORY}/real/csch.cc
  ${SRC_DIRECTORY}/real/arcsinh.cc
  ${SRC_DIRECTORY}/real/arccosh.cc
  ${SRC_DIRECTORY}/real/arctanh.cc
  ${SRC_DIRECTORY}/real/arccoth.cc
  ${SRC_DIRECTORY}/real/arcsech.cc
  ${SRC_DIRECTORY}/real/arccsch.cc
  ${SRC_DIRECTORY}/real/erf.cc
  ${SRC_DIRECTORY}/real/erfc.cc
  ${SRC_DIRECTORY}/real/sgn.cc
  ${SRC_DIRECTORY}/real/fraction.cc
  ${SRC_DIRECTORY}/real/reduction.cc
  ${SRC_DIRECTORY}/real/gamma.cc
  ${SRC_DIRECTORY}/real/gcd.cc
  ${SRC_DIRECTORY}/real/lcm.cc
  ${SRC_DIRECTORY}/real/extended_euclidean.cc
  ${SRC_DIRECTORY}/real/relatively_prime.cc
)

#
# Complex source
#
set(COMPLEX_SRC
  ${SRC_DIRECTORY}/complex/complex.cc
  ${SRC_DIRECTORY}/complex/abs.cc
  ${SRC_DIRECTORY}/complex/add.cc
  ${SRC_DIRECTORY}/complex/sub.cc
  ${SRC_DIRECTORY}/complex/mul.cc
  ${SRC_DIRECTORY}/complex/div.cc
  ${SRC_DIRECTORY}/complex/mod.cc
  ${SRC_DIRECTORY}/complex/cmp.cc
  ${SRC_DIRECTORY}/complex/exp.cc
  ${SRC_DIRECTORY}/complex/pow.cc
  ${SRC_DIRECTORY}/complex/ln.cc
  ${SRC_DIRECTORY}/complex/log.cc
  ${SRC_DIRECTORY}/complex/log2.cc
  ${SRC_DIRECTORY}/complex/log10.cc
  ${SRC_DIRECTORY}/complex/sqrt.cc
  ${SRC_DIRECTORY}/complex/triangle.cc
)

#
# Complex source
#
set(NUMBER_SRC
  ${SRC_DIRECTORY}/number/number.cc
  ${SRC_DIRECTORY}/number/is_zero.cc
  ${SRC_DIRECTORY}/number/is_one.cc
  ${SRC_DIRECTORY}/number/add.cc
  ${SRC_DIRECTORY}/number/sub.cc
  ${SRC_DIRECTORY}/number/mul.cc
  ${SRC_DIRECTORY}/number/div.cc
  ${SRC_DIRECTORY}/number/mod.cc
  ${SRC_DIRECTORY}/number/cmp.cc
  ${SRC_DIRECTORY}/number/abs.cc
  ${SRC_DIRECTORY}/number/ceil.cc
  ${SRC_DIRECTORY}/number/floor.cc
  ${SRC_DIRECTORY}/number/round.cc
  ${SRC_DIRECTORY}/number/exp.cc
  ${SRC_DIRECTORY}/number/pow.cc
  ${SRC_DIRECTORY}/number/ln.cc
  ${SRC_DIRECTORY}/number/log.cc
  ${SRC_DIRECTORY}/number/log2.cc
  ${SRC_DIRECTORY}/number/log10.cc
  ${SRC_DIRECTORY}/number/sqrt.cc
  ${SRC_DIRECTORY}/number/sin.cc
  ${SRC_DIRECTORY}/number/cos.cc
  ${SRC_DIRECTORY}/number/tan.cc
  ${SRC_DIRECTORY}/number/cot.cc
  ${SRC_DIRECTORY}/number/sec.cc
  ${SRC_DIRECTORY}/number/csc.cc
  ${SRC_DIRECTORY}/number/arcsin.cc
  ${SRC_DIRECTORY}/number/arccos.cc
  ${SRC_DIRECTORY}/number/arctan.cc
  ${SRC_DIRECTORY}/number/arccot.cc
  ${SRC_DIRECTORY}/number/arcsec.cc
  ${SRC_DIRECTORY}/number/arccsc.cc
  ${SRC_DIRECTORY}/number/sinh.cc
  ${SRC_DIRECTORY}/number/cosh.cc
  ${SRC_DIRECTORY}/number/tanh.cc
  ${SRC_DIRECTORY}/number/coth.cc
  ${SRC_DIRECTORY}/number/sech.cc
  ${SRC_DIRECTORY}/number/csch.cc
  ${SRC_DIRECTORY}/number/arcsinh.cc
  ${SRC_DIRECTORY}/number/arccosh.cc
  ${SRC_DIRECTORY}/number/arctanh.cc
  ${SRC_DIRECTORY}/number/arccoth.cc
  ${SRC_DIRECTORY}/number/arcsech.cc
  ${SRC_DIRECTORY}/number/arccsch.cc
  ${SRC_DIRECTORY}/number/erf.cc
  ${SRC_DIRECTORY}/number/erfc.cc
  ${SRC_DIRECTORY}/number/sgn.cc
  ${SRC_DIRECTORY}/number/fraction.cc
  ${SRC_DIRECTORY}/number/reduction.cc
  ${SRC_DIRECTORY}/number/gamma.cc
  ${SRC_DIRECTORY}/number/gcd.cc
  ${SRC_DIRECTORY}/number/lcm.cc
  ${SRC_DIRECTORY}/number/extended_euclidean.cc
  ${SRC_DIRECTORY}/number/relatively_prime.cc
)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${SRC_DIRECTORY}/mynum.cc
  ${SRC_DIRECTORY}/wrapper.cc
  ${INTEGER_SRC}
  ${FLOAT_SRC}
  ${REAL_SRC}
  ${COMPLEX_SRC}
  ${NUMBER_SRC}
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
add_test(NAME test_hyperfunc COMMAND test_hyperfunc)
set_tests_properties(test_hyperfunc PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_error COMMAND test_error)
set_tests_properties(test_error PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_fraction COMMAND test_fraction)
set_tests_properties(test_fraction PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
# add_test(NAME test_float COMMAND test_float)
# set_tests_properties(test_float PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_integer COMMAND test_integer)
set_tests_properties(test_integer PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_number COMMAND test_number)
set_tests_properties(test_number PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_gcd COMMAND test_gcd)
set_tests_properties(test_gcd PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
#
# Install Set
#
INSTALL(TARGETS mynum ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYNUM_HEADERS} DESTINATION include/mynum)