add_executable(OrderTest OrderTest.cpp)
target_link_libraries(OrderTest
    PUBLIC warehouse
    # Nothing to link since both of these libs are header-only,
    # but this sets up the include path correctly too
    Catch2::Catch2WithMain
    trompeloeil::trompeloeil)

# Optional: Use CTest to manage your tests
add_test(NAME OrderTest COMMAND OrderTest )
