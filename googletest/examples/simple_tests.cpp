#include <gtest/gtest.h>

#include <algorithm>

TEST(SimpleTests, BasicTests)
{
  EXPECT_EQ(std::max(1, 2), 2);
  EXPECT_STRNE("hello", "world");
}

TEST(FooTest, ItDoesNotThrow)
{
    EXPECT_NO_THROW({
        auto x = 1 + 2;
    });
}