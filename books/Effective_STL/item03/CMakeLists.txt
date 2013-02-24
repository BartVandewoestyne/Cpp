include_directories(../utils)

add_executable(slicing slicing.cpp)
target_link_libraries(slicing estl)

add_executable(array_vs_vector array_vs_vector.cpp)
target_link_libraries(array_vs_vector estl)
