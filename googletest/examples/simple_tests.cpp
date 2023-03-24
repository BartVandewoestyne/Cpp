#include <gtest/gtest.h>

#include <algorithm>

TEST(SimpleTests, BasicTests)
{
  EXPECT_EQ(std::max(1, 2), 2);
  EXPECT_STRNE("hello", "world");
}
