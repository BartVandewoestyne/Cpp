/*
 * References:
 *
 *   [catchorg] Writing tests
 *     https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#writing-tests
 */

#include <catch2/catch_test_macros.hpp>

#include <cstdint>

unsigned int Factorial(unsigned int number) {
    return number > 1 ? Factorial(number-1)*number : 1;
}

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
}