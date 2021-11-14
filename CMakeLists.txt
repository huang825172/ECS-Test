cmake_minimum_required(VERSION 3.0)
project(s1mpleEngine)

set(CMAKE_CXX_STANDARD 17)

# Fetch dependencies
include(FetchDependencies.cmake)

# Engine library
add_library(s1mpleEngine src/s1mpleEngine.cpp)
target_include_directories(s1mpleEngine PUBLIC include)

# Build unit tests
add_subdirectory(test)
