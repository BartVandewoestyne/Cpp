#include <gtest/gtest.h>

#include <type_traits>

template<typename T>
class FooTest : public testing::Test
{
};

using MyTypes = ::testing::Types<int, long, char, bool>;
TYPED_TEST_SUITE(FooTest, MyTypes);

TYPED_TEST(FooTest, IsIntegral)
{
    EXPECT_TRUE(std::is_integral_v<TypeParam>);
}

TYPED_TEST(FooTest, IsArithmetic)
{
    EXPECT_TRUE(std::is_arithmetic_v<TypeParam>);
}