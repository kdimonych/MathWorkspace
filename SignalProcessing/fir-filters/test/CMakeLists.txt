cmake_minimum_required(VERSION 3.13)

# Ensure the build is for the same architecture as the host
if(NOT ${CMAKE_SYSTEM_PROCESSOR} STREQUAL ${CMAKE_HOST_SYSTEM_PROCESSOR})
  return()
endif()

# Project definition
project(signal-processing.fir-filters_test C CXX)

# Enable testing
enable_testing()

# Find GoogleTest
find_package(GTest REQUIRED)

# Header files for the test executable. Currently we are not using any header
# files in the test but we are keeping this variable for future use and to keep
# the structure similar to the other test files
set(HEADER_LIST)
# Source files for the test executable
set(SOURCE_LIST RationalResamplingFIR_Test.cpp)

# Create the test executable
add_executable(signal-processing.fir-filters_test ${HEADER_LIST} ${SOURCE_LIST})
# Link libraries
target_link_libraries(signal-processing.fir-filters_test
                      signal-processing.fir-filters GTest::gtest_main)

# Set the C++ standard explicitly
target_compile_features(signal-processing.fir-filters_test PRIVATE cxx_std_17)

# Discover GoogleTest tests
include(GoogleTest)
gtest_discover_tests(signal-processing.fir-filters_test)
