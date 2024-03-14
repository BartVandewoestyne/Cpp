#include "factorial.h"

#include <gtest/gtest.h>

#include <algorithm>

TEST(SimpleTests, BasicTests)
{
  EXPECT_EQ(std::max(1, 2), 2);
  EXPECT_STRNE("hello", "world");
}

TEST(FactorialTest, HandlesZeroInput)
{
    EXPECT_EQ(Factorial(0), 1);
}

TEST(FactorialTest, HandlesPositiveInput)
{
    EXPECT_EQ(Factorial(1), 1);
    EXPECT_EQ(Factorial(2), 2);
    EXPECT_EQ(Factorial(3), 6);
    EXPECT_EQ(Factorial(8), 40320);
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

TEST(SimpleTest, Addition)
{
    EXPECT_EQ(1+1, 3);
    EXPECT_EQ(2+2, 5);
    EXPECT_EQ(3+3, 6);
}
