include_directories(../utils)

add_executable(slicing slicing.cpp)

target_link_libraries(slicing estl)
