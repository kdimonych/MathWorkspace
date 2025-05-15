cmake_minimum_required(VERSION 3.13)

project(abstract-platform CXX)

# Set the minimum required C++ standard for the entire workspace
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions

add_subdirectory(DeepLearning)
add_subdirectory(SignalProcessing)
