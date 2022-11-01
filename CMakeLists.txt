cmake_minimum_required (VERSION 3.5)
project(mynum VERSION 1.0)

# -g allows for gdb debugging
# turn on -03 for best performance
# add_definitions(-std=c++11 -g -O0)
add_definitions(-std=c++11 -O3)

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
  ${SRC_DIRECTORY}/exception.h
  ${SRC_DIRECTORY}/constant.h
  ${SRC_DIRECTORY}/bignum.h
  ${SRC_DIRECTORY}/integer.h
  ${SRC_DIRECTORY}/float.h
  ${SRC_DIRECTORY}/convert.h
  ${SRC_DIRECTORY}/math.h
)

#
# Mynum math header file
#
set(MYNUM_MATH_SRC
  ${SRC_DIRECTORY}/math/abs.cc
  ${SRC_DIRECTORY}/math/acos.cc
  ${SRC_DIRECTORY}/math/acosh.cc
  ${SRC_DIRECTORY}/math/asin.cc
  ${SRC_DIRECTORY}/math/asinh.cc
  ${SRC_DIRECTORY}/math/atan.cc
  ${SRC_DIRECTORY}/math/atan2.cc
  ${SRC_DIRECTORY}/math/atanh.cc
  ${SRC_DIRECTORY}/math/cbrt.cc
  ${SRC_DIRECTORY}/math/ceil.cc
  ${SRC_DIRECTORY}/math/copysign.cc
  ${SRC_DIRECTORY}/math/cos.cc
  ${SRC_DIRECTORY}/math/cosh.cc
  ${SRC_DIRECTORY}/math/erf.cc
  ${SRC_DIRECTORY}/math/erfc.cc
  ${SRC_DIRECTORY}/math/exp.cc
  ${SRC_DIRECTORY}/math/exp2.cc
  ${SRC_DIRECTORY}/math/expm1.cc
  ${SRC_DIRECTORY}/math/fabs.cc
  ${SRC_DIRECTORY}/math/fdim.cc
  ${SRC_DIRECTORY}/math/floor.cc
  ${SRC_DIRECTORY}/math/fma.cc
  ${SRC_DIRECTORY}/math/fmax.cc
  ${SRC_DIRECTORY}/math/fmin.cc
  ${SRC_DIRECTORY}/math/fmod.cc
  ${SRC_DIRECTORY}/math/fpclassify.cc
  ${SRC_DIRECTORY}/math/frexp.cc
  ${SRC_DIRECTORY}/math/hypot.cc
  ${SRC_DIRECTORY}/math/ilogb.cc
  ${SRC_DIRECTORY}/math/isfinite.cc
  ${SRC_DIRECTORY}/math/isgreater.cc
  ${SRC_DIRECTORY}/math/isgreaterequal.cc
  ${SRC_DIRECTORY}/math/isinf.cc
  ${SRC_DIRECTORY}/math/isless.cc
  ${SRC_DIRECTORY}/math/islessequal.cc
  ${SRC_DIRECTORY}/math/islessgreater.cc
  ${SRC_DIRECTORY}/math/isnan.cc
  ${SRC_DIRECTORY}/math/isnormal.cc
  ${SRC_DIRECTORY}/math/isunordered.cc
  ${SRC_DIRECTORY}/math/ldexp.cc
  ${SRC_DIRECTORY}/math/lgamma.cc
  ${SRC_DIRECTORY}/math/llrint.cc
  ${SRC_DIRECTORY}/math/llround.cc
  ${SRC_DIRECTORY}/math/log.cc
  ${SRC_DIRECTORY}/math/log10.cc
  ${SRC_DIRECTORY}/math/log1p.cc
  ${SRC_DIRECTORY}/math/log2.cc
  ${SRC_DIRECTORY}/math/logb.cc
  ${SRC_DIRECTORY}/math/lrint.cc
  ${SRC_DIRECTORY}/math/lround.cc
  ${SRC_DIRECTORY}/math/modf.cc
  ${SRC_DIRECTORY}/math/nan.cc
  ${SRC_DIRECTORY}/math/nanf.cc
  ${SRC_DIRECTORY}/math/nanl.cc
  ${SRC_DIRECTORY}/math/nearbyint.cc
  ${SRC_DIRECTORY}/math/nextafter.cc
  ${SRC_DIRECTORY}/math/nexttoward.cc
  ${SRC_DIRECTORY}/math/pow.cc
  ${SRC_DIRECTORY}/math/remainder.cc
  ${SRC_DIRECTORY}/math/remquo.cc
  ${SRC_DIRECTORY}/math/rint.cc
  ${SRC_DIRECTORY}/math/round.cc
  ${SRC_DIRECTORY}/math/scalbln.cc
  ${SRC_DIRECTORY}/math/scalbn.cc
  ${SRC_DIRECTORY}/math/signbit.cc
  ${SRC_DIRECTORY}/math/sin.cc
  ${SRC_DIRECTORY}/math/sinh.cc
  ${SRC_DIRECTORY}/math/sqrt.cc
  ${SRC_DIRECTORY}/math/tan.cc
  ${SRC_DIRECTORY}/math/tanh.cc
  ${SRC_DIRECTORY}/math/tgamma.cc
  ${SRC_DIRECTORY}/math/trunc.cc
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

add_executable(test_float ${SRC_DIRECTORY}/test/test_float.cc)
target_link_libraries(test_float mynum gtest pthread)

add_executable(test_float_pow ${SRC_DIRECTORY}/test/test_float_pow.cc)
target_link_libraries(test_float_pow mynum gtest pthread)

add_executable(test_float_log ${SRC_DIRECTORY}/test/test_float_log.cc)
target_link_libraries(test_float_log mynum gtest pthread)

add_executable(test_float_erf_gamma ${SRC_DIRECTORY}/test/test_float_erf_gamma.cc)
target_link_libraries(test_float_erf_gamma mynum gtest pthread)

add_executable(test_bernoulli_numbers ${SRC_DIRECTORY}/test/test_bernoulli_numbers.cc)
target_link_libraries(test_bernoulli_numbers mynum my gtest pthread)

add_executable(test_euler_numbers ${SRC_DIRECTORY}/test/test_euler_numbers.cc)
target_link_libraries(test_euler_numbers mynum my gtest pthread)

add_executable(test_math ${SRC_DIRECTORY}/test/test_math.cc)
target_link_libraries(test_math mynum my gtest pthread)

add_executable(test_size ${SRC_DIRECTORY}/test/test_size.cc)
# target_link_libraries(test_size mynum my gtest pthread)
endif(BUILD_TEST)

#
# Tools Build
#
set(BUILD_TOOLS TRUE)
if(BUILD_TOOLS)
add_executable(generate_bernoulli_numbers ${SRC_DIRECTORY}/tools/generate_bernoulli_numbers.cc)
target_link_libraries(generate_bernoulli_numbers mynum my uuid gtest pthread)

add_executable(generate_euler_numbers ${SRC_DIRECTORY}/tools/generate_euler_numbers.cc)
target_link_libraries(generate_euler_numbers mynum my uuid gtest pthread)
endif(BUILD_TOOLS)

#
# Research Build
#
set(BUILD_RESEARCH TRUE)
if(BUILD_RESEARCH)
endif(BUILD_RESEARCH)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${SRC_DIRECTORY}/common.cc
  ${SRC_DIRECTORY}/constant.cc
  ${SRC_DIRECTORY}/constant_bernoulli_numbers.cc
  ${SRC_DIRECTORY}/constant_euler_numbers.cc
  ${SRC_DIRECTORY}/convert.cc
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
  ${SRC_DIRECTORY}/integer/is_subnormal.cc
  ${SRC_DIRECTORY}/integer/add.cc
  ${SRC_DIRECTORY}/integer/sub.cc
  ${SRC_DIRECTORY}/integer/mul.cc
  ${SRC_DIRECTORY}/integer/div.cc
  ${SRC_DIRECTORY}/integer/quo.cc
  ${SRC_DIRECTORY}/integer/mod.cc
  ${SRC_DIRECTORY}/integer/abs.cc
  ${SRC_DIRECTORY}/integer/floor.cc
  ${SRC_DIRECTORY}/integer/ceil.cc
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
  ${SRC_DIRECTORY}/float/float.cc
  ${SRC_DIRECTORY}/float/__xxx_infinite.cc
  ${SRC_DIRECTORY}/float/__cmp.cc
  ${SRC_DIRECTORY}/float/equ.cc
  ${SRC_DIRECTORY}/float/gt.cc
  ${SRC_DIRECTORY}/float/lt.cc
  ${SRC_DIRECTORY}/float/ge.cc
  ${SRC_DIRECTORY}/float/le.cc
  ${SRC_DIRECTORY}/float/is_zero.cc
  ${SRC_DIRECTORY}/float/is_one.cc
  ${SRC_DIRECTORY}/float/is_nan.cc
  ${SRC_DIRECTORY}/float/is_infinite.cc
  ${SRC_DIRECTORY}/float/is_none.cc
  ${SRC_DIRECTORY}/float/is_integer.cc
  ${SRC_DIRECTORY}/float/is_float.cc
  ${SRC_DIRECTORY}/float/is_subnormal.cc
  ${SRC_DIRECTORY}/float/add.cc
  ${SRC_DIRECTORY}/float/sub.cc
  ${SRC_DIRECTORY}/float/mul.cc
  ${SRC_DIRECTORY}/float/div.cc
  ${SRC_DIRECTORY}/float/div2.cc
  ${SRC_DIRECTORY}/float/mod.cc
  ${SRC_DIRECTORY}/float/abs.cc
  ${SRC_DIRECTORY}/float/floor.cc
  ${SRC_DIRECTORY}/float/ceil.cc
  ${SRC_DIRECTORY}/float/round.cc
  ${SRC_DIRECTORY}/float/integer.cc
  ${SRC_DIRECTORY}/float/pow.cc
  ${SRC_DIRECTORY}/float/exp.cc
  ${SRC_DIRECTORY}/float/sqrt.cc
  ${SRC_DIRECTORY}/float/factorial.cc
  ${SRC_DIRECTORY}/float/log.cc
  ${SRC_DIRECTORY}/float/log2.cc
  ${SRC_DIRECTORY}/float/log10.cc
  ${SRC_DIRECTORY}/float/ln.cc
  ${SRC_DIRECTORY}/float/sgn.cc
  ${SRC_DIRECTORY}/float/sin.cc
  ${SRC_DIRECTORY}/float/cos.cc
  ${SRC_DIRECTORY}/float/tan.cc
  ${SRC_DIRECTORY}/float/csc.cc
  ${SRC_DIRECTORY}/float/sec.cc
  ${SRC_DIRECTORY}/float/cot.cc
  ${SRC_DIRECTORY}/float/arcsin.cc
  ${SRC_DIRECTORY}/float/arccos.cc
  ${SRC_DIRECTORY}/float/arctan.cc
  ${SRC_DIRECTORY}/float/arccsc.cc
  ${SRC_DIRECTORY}/float/arcsec.cc
  ${SRC_DIRECTORY}/float/arccot.cc
  ${SRC_DIRECTORY}/float/sinh.cc
  ${SRC_DIRECTORY}/float/cosh.cc
  ${SRC_DIRECTORY}/float/tanh.cc
  ${SRC_DIRECTORY}/float/csch.cc
  ${SRC_DIRECTORY}/float/sech.cc
  ${SRC_DIRECTORY}/float/coth.cc
  ${SRC_DIRECTORY}/float/arcsinh.cc
  ${SRC_DIRECTORY}/float/arccosh.cc
  ${SRC_DIRECTORY}/float/arctanh.cc
  ${SRC_DIRECTORY}/float/arccsch.cc
  ${SRC_DIRECTORY}/float/arcsech.cc
  ${SRC_DIRECTORY}/float/arccoth.cc
  ${SRC_DIRECTORY}/float/arcsech.cc
  ${SRC_DIRECTORY}/float/arccoth.cc
  ${SRC_DIRECTORY}/float/erf.cc
  ${SRC_DIRECTORY}/float/erfc.cc
  ${SRC_DIRECTORY}/float/gamma.cc
  ${SRC_DIRECTORY}/float/fraction.cc
  ${SRC_DIRECTORY}/float/copy.cc
  ${SRC_DIRECTORY}/float/same_digits.cc
  ${SRC_DIRECTORY}/float/operator.cc
  ${MYNUM_MATH_SRC}
)
target_link_libraries(${PROJECT_NAME} my)

#
# Enable Test
#
enable_testing()
add_test(NAME test_math COMMAND test_math)
set_tests_properties(test_math PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_bignum COMMAND test_bignum)
set_tests_properties(test_bignum PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_integer COMMAND test_integer)
set_tests_properties(test_integer PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_float COMMAND test_float)
set_tests_properties(test_float PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_float_pow COMMAND test_float_pow)
set_tests_properties(test_float_pow PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_float_log COMMAND test_float_log)
set_tests_properties(test_float_log PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_float_erf_gamma COMMAND test_float_erf_gamma)
set_tests_properties(test_float_erf_gamma PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")

#
# Install Set
#
INSTALL(TARGETS mynum ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYNUM_HEADERS} DESTINATION include/mynum)
# INSTALL(FILES ${MYNUM_MATH_HEADERS} DESTINATION include/mynum/math)