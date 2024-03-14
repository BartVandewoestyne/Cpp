#include <catch2/catch_test_macros.hpp>

TEST_CASE( "vectors can be sized and resized", "[vector]" ) {

    std::vector<int> v{1, 2, 3, 4, 5};

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 5);

    SECTION( "A) reserving bigger changes capacity but not size" )
    {
        v.reserve(10);
    
        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 10);

        SECTION( "A.1) reserving down unused capacity does not change capacity" )
        {
            v.reserve(7);
            REQUIRE(v.size() == 5);
            REQUIRE(v.capacity() >= 10);
        }

        v[0] = 42;

        SECTION( "A.2) shrink_to_fit is a non binding request to reduce capacity() to size()")
        {
            v.shrink_to_fit();
            REQUIRE(v.capacity() >= v.size());
        }
    }
}