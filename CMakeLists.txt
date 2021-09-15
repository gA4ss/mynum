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
set(CORE_DIRECTORY ./src/core)
set(NUMBER_DIRECTORY ./src/number)

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
set(MYNUM_CORE_HEADERS
  ${CORE_DIRECTORY}/common.h
  ${CORE_DIRECTORY}/exception.h
  ${CORE_DIRECTORY}/numeric.h
)

set(MYNUM_NUMBER_HEADERS
  ${NUMBER_DIRECTORY}/convert.h
  ${NUMBER_DIRECTORY}/number.h
  ${NUMBER_DIRECTORY}/complex.h
  ${NUMBER_DIRECTORY}/real.h
  ${NUMBER_DIRECTORY}/integer.h
)



#
# Test Build
#
set(BUILD_TEST TRUE)
if(BUILD_TEST)
add_executable(test_numeric ${CORE_DIRECTORY}/test/test_numeric.cc)
target_link_libraries(test_numeric mynum gtest pthread)
add_executable(test_number ${NUMBER_DIRECTORY}/test/test_number.cc)
target_link_libraries(test_number mynum my uuid gtest pthread)
add_executable(test_convert ${NUMBER_DIRECTORY}/test/test_convert.cc)
target_link_libraries(test_convert mynum my uuid gtest pthread)
endif(BUILD_TEST)

#
# Library Build
#
add_library(${PROJECT_NAME} STATIC
  ${CORE_DIRECTORY}/common.cc
  ${CORE_DIRECTORY}/numeric.cc
  ${NUMBER_DIRECTORY}/number.cc
  ${NUMBER_DIRECTORY}/complex.cc
  ${NUMBER_DIRECTORY}/real.cc
  ${NUMBER_DIRECTORY}/integer.cc
  # ${NUMBER_DIRECTORY}/fraction.cc
  ${NUMBER_DIRECTORY}/convert.cc
)
target_link_libraries(${PROJECT_NAME} my)

#
# Enable Test
#
enable_testing()
add_test(NAME test_numeric COMMAND test_numeric)
set_tests_properties(test_numeric PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_number COMMAND test_number)
set_tests_properties(test_number PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")
add_test(NAME test_convert COMMAND test_convert)
set_tests_properties(test_convert PROPERTIES FAIL_REGULAR_EXPRESSION "FAILED")

#
# Install Set
#
INSTALL(TARGETS mynum ARCHIVE DESTINATION lib)
INSTALL(FILES ${MYNUM_CORE_HEADERS} DESTINATION include/mynum/core)
INSTALL(FILES ${MYNUM_NUMBER_HEADERS} DESTINATION include/mynum/number)