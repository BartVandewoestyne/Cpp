// Key idea:
//   Type-parameterized tests are like typed tests, except that they don't require you to know the list of types ahead of time. Instead, you can define the test logic first and instantiate it with different type lists later. You can even instantiate it more than once in the same program.
//
//   If you are designing an interface or concept, you can define a suite of type-parameterized tests to verify properties that any valid implementation of the interface/concept should have. Then, the author of each implementation can just instantiate the test suite with their type to verify that it conforms to the requirements, without having to write similar tests repeatedly. 

#include <gtest/gtest.h>

#include <type_traits>

template <typename T>
class FooTest : public testing::Test
{
};

TYPED_TEST_SUITE_P(FooTest);

TYPED_TEST_P(FooTest, IsIntegral)
{
    EXPECT_TRUE(std::is_integral_v<TypeParam>);
}

TYPED_TEST_P(FooTest, IsArithmetic)
{
    EXPECT_TRUE(std::is_arithmetic_v<TypeParam>);
}

REGISTER_TYPED_TEST_SUITE_P(FooTest,
                            IsIntegral, IsArithmetic);

using MyTypes = ::testing::Types<int, long, char, bool>;
INSTANTIATE_TYPED_TEST_SUITE_P(My, FooTest, MyTypes);