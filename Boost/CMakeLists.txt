# TODO:
#   * Create a nice CMake build system.

cmake_minimum_required(VERSION 3.0)

project(boost_examples)

find_package(Boost COMPONENTS system filesystem REQUIRED)
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")
message(status "** Boost Libraries: ${Boost_FILESYSTEM_LIBRARY}")
message(status "** Boost Libraries: ${Boost_SYSTEM_LIBRARY}")
message(status "** Boost Libraries: ${Boost_REGEX_LIBRARY}")

include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(filesystem)
add_subdirectory(stacktrace)
