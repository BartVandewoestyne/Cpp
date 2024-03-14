add_executable(hello_test hello_test.cpp)
target_link_libraries(hello_test GTest::gtest_main)

add_executable(simple_tests simple_tests.cpp)
target_link_libraries(simple_tests math GTest::gtest_main)

add_executable(test_fixtures test_fixtures.cpp)
target_link_libraries(test_fixtures GTest::gtest_main)

add_executable(test_fixtures_vector test_fixtures_vector.cpp)
target_link_libraries(test_fixtures_vector GTest::gtest_main)

add_executable(nesting_gtest nesting.cpp)
target_link_libraries(nesting_gtest GTest::gtest_main)

# Enable CMake’s test runner to discover the tests included in the binary,
# using the GoogleTest CMake module.
include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(simple_tests)
gtest_discover_tests(test_fixtures)
gtest_discover_tests(test_fixtures_vector)
gtest_discover_tests(nesting_gtest)

