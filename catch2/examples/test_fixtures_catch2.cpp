#include <catch2/catch_test_macros.hpp>

#include <vector>

class VectorTest
{
public:
    VectorTest()
    {
        CHECK(v.size() == 5);
        CHECK(v.capacity() == 5);
    }

protected:
    std::vector<int> v{1, 2, 3, 4, 5};
};

TEST_CASE_METHOD(VectorTest, "resizing bigger changes size and capacity", "[resize]")
{
    v.resize(10);
    CHECK(v.size() == 10);
    CHECK(v.capacity() >= 10);
}

TEST_CASE_METHOD(VectorTest, "resizing smaller changes size but not capacity", "[resize]")
{
    v.resize(0);

    CHECK(v.size() == 0);
    CHECK(v.capacity() >= 5);
}

TEST_CASE_METHOD(VectorTest, "reserving bigger changes capacity but not size", "[reserve]")
{
    v.reserve(10);

    CHECK(v.size() == 5);
    CHECK(v.capacity() >= 10);
}

TEST_CASE_METHOD(VectorTest, "reserving smaller does not change size or capacity", "[reserve]")
{
    v.reserve(0);

    CHECK(v.size() == 5);
    CHECK(v.capacity() >= 5);
}