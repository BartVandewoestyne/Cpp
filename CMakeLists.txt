# To build and run the tests:
#
#   cmake -S . -B build
#   cmake --build build
#   cd build && ctest

cmake_minimum_required(VERSION 3.14)

project(Cpp)

enable_testing()

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

add_subdirectory(googletest)
add_subdirectory(gmock)
