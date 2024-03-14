/*
 * References:
 *
 *   [catchorg] Writing tests
 *     https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#writing-tests
 */

#include "factorial.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <cstdint>

TEST_CASE( "Factorial handles zero input", "[factorial]")
{
    REQUIRE( Factorial(0) == 1 ); 
} 

TEST_CASE( "Factorials are computed", "[factorial]" )
{
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(8) == 40320 );
}

TEST_CASE( "Foo test", "[nothrow]" )
{
    REQUIRE_NOTHROW([&](){
        auto x = 1 + 2;
    }());
}

TEST_CASE( "Comparing numbers", "[numbersTest]" )
{
    double x = 1.0;
	REQUIRE_THAT(x, Catch::Matchers::WithinULP(1.0, 4));

    float y = 2.0f;
	REQUIRE_THAT(y, Catch::Matchers::WithinULP(2.0f, 4));

    REQUIRE_THAT(1.0/3, Catch::Matchers::WithinAbs(1 - 2.0/3, 1e-6));
}

TEST_CASE( "Simple Test", "[Addition]")
{
    CHECK(1+1 == 2);
    CHECK(2+2 == 4);
    CHECK(3+3 == 6);
}
