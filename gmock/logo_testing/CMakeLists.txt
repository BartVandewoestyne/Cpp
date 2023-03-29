add_executable(painter-test painter-test.cpp)
target_link_libraries(painter-test
    PUBLIC logo
    PUBLIC GTest::gtest_main
    PUBLIC GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(painter-test)
