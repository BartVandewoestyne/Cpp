add_executable(PainterTest PainterTest.cpp)
target_link_libraries(PainterTest
    PUBLIC
        logo
        GTest::gtest_main
        GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(PainterTest)
