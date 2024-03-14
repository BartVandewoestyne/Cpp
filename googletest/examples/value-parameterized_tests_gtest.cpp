// Key idea:
//
//   * Run the same test for different parameters.  This can also be done with
//     a for-loop and an EXPECT_* statement, but then from the error message you
//     don't know in what iteration it failed.
//
// References:
//   https://www.sandordargo.com/blog/2019/04/24/parameterized-testing-with-gtest

#include <gtest/gtest.h>

class FooTest : public testing::TestWithParam<int>
{
};

TEST_P(FooTest, AreParametersEven)
{
    EXPECT_TRUE((GetParam() % 2) == 0);
}

INSTANTIATE_TEST_SUITE_P(
        SomeTestInstantiationName1,
        FooTest,
        testing::Values(2, 4, 6, 8, 10));

INSTANTIATE_TEST_SUITE_P(
        SomeTestInstantiationName2,
        FooTest,
        testing::Range(20, 30, 2));