add_executable(
  hello_test
  hello_test.cpp
)

target_link_libraries(
  hello_test
  GTest::gtest_main
)

# Enable CMake’s test runner to discover the tests included in the binary,
# using the GoogleTest CMake module.
include(GoogleTest)
gtest_discover_tests(hello_test)
