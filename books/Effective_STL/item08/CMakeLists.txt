include_directories(../utils)

add_executable(copying_auto_ptr copying_auto_ptr.cpp)
target_link_libraries(copying_auto_ptr estl)

add_executable(sort_example sort_example.cpp)
target_link_libraries(sort_example estl)
