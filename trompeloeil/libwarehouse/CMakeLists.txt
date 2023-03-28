add_library(warehouse INTERFACE)
target_include_directories(warehouse INTERFACE .)

add_subdirectory(testing)
