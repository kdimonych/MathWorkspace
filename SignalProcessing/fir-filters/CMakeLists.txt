cmake_minimum_required(VERSION 3.13)

project(signal-processing.fir-filters CXX)

set(HEADER_LIST SignalProcessing/fir-filters/RationalResamplingFIR.hpp)

set(SOURCE_LIST SignalProcessing/fir-filters/RationalResamplingFIR.cpp)

# Add library cpp files
add_library(signal-processing.fir-filters ${HEADER_LIST} ${SOURCE_LIST})

target_sources(
  signal-processing.fir-filters
  PRIVATE ${SOURCE_LIST}
  INTERFACE ${HEADER_LIST})

target_link_libraries(signal-processing.fir-filters
                      externals.SignalsmithAudio.plot)

# Define project include directory
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR})

# Add include directory
target_include_directories(signal-processing.fir-filters
                           PUBLIC ${PROJECT_INCLUDE_DIR})

add_subdirectory(test)
