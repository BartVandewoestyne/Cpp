#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

TEST_CASE("AreParametersEven")
{
    auto i = GENERATE(2, 4, 6, 8, 10);
    REQUIRE(i % 2 == 0);
}