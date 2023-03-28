add_executable(example1 example1.cpp)
target_link_libraries(example1 PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(example1)
