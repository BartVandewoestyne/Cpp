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

TEST(NumbersTest, ComparingNumbers)
{
  double x = 1.0;
  EXPECT_DOUBLE_EQ(1.0, x);

  float y = 2.0f;
  EXPECT_FLOAT_EQ(2.0f, y);
  
  EXPECT_NEAR(1.0/3, 1 - 2.0/3, 1e-6);
}