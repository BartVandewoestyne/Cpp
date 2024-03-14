add_executable(example1 example1.cpp)
target_link_libraries(example1 PRIVATE math Catch2::Catch2WithMain)

add_executable(sections sections.cpp)
target_link_libraries(sections PRIVATE Catch2::Catch2WithMain)

add_executable(test_fixtures_catch2 test_fixtures_catch2.cpp)
target_link_libraries(test_fixtures_catch2 PRIVATE Catch2::Catch2WithMain)

add_executable(nesting_catch2 nesting.cpp)
target_link_libraries(nesting_catch2 PRIVATE Catch2::Catch2WithMain)

add_executable(data_generators data_generators.cpp)
target_link_libraries(data_generators PRIVATE Catch2::Catch2WithMain)

add_executable(death_tests_catch2 death_tests_catch2.cpp)
target_link_libraries(death_tests_catch2 PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(example1)
catch_discover_tests(sections)
catch_discover_tests(test_fixtures_catch2)
catch_discover_tests(nesting_catch2)
catch_discover_tests(data_generators)
catch_discover_tests(death_tests_catch2)

