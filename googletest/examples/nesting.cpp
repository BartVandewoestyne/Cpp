// This example tries to mimick the SECTION concept of Catch2.

#include <gtest/gtest.h>

#include <vector>

class VectorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        EXPECT_EQ(v.size(), 5);
        EXPECT_EQ(v.capacity(), 5);
    }

    std::vector<int> v{1, 2, 3, 4, 5};
};

TEST_F(VectorTest, SectionA1)
{
    // reserving bigger changes capacity but not size
    v.reserve(10);
    EXPECT_EQ(v.size(), 5);
    EXPECT_GE(v.capacity(), 10);

    // reserving down unused capacity does not change capacity
    v.reserve(7);
    EXPECT_EQ(v.size(), 5);
    EXPECT_GE(v.capacity(), 10);

    v[0] = 42;
}

TEST_F(VectorTest, SectionA2)
{
    // reserving bigger changes capacity but not size
    v.reserve(10);
    EXPECT_EQ(v.size(), 5);
    EXPECT_GE(v.capacity(), 10);

    v[0] = 42;

    // shrink_to_fit is a non binding request to reduce capacity() to size()
    v.shrink_to_fit();
    EXPECT_GE(v.capacity(), v.size());
}
