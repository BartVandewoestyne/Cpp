add_executable(example1 example1.cpp)
target_link_libraries(example1 PRIVATE Catch2::Catch2WithMain)

add_executable(sections sections.cpp)
target_link_libraries(sections PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(example1)
catch_discover_tests(sections)
