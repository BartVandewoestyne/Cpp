/*
 * Question:
 *   "How can one check if a constexpr function is indeed evaluated at compile time?"
 *
 * Answer:
 *   "Try using the function in a constexpr expression and see if you get errors at compile time."
 *
 * References:
 *
 *   [bloomfield20151018] How to check that a function is constexpr
 *     http://avidinsight.uk/2015/10/how-to-check-that-a-function-is-constexpr/
 *
 *   [stackoverflow20150311] How to test if constexpr is evaluated correctly
 *     http://stackoverflow.com/questions/28988426/how-to-test-if-constexpr-is-evaluated-correctly
 *
 *   [stackoverflow20130109] When does a constexpr function get evaluated at compile time?
 *     http://stackoverflow.com/questions/14248235/when-does-a-constexpr-function-get-evaluated-at-compile-time
 */

constexpr
int f(int x)
{
    return 2*x;
}

template <int N>
struct ForceCompileTimeEvaluation {};

int main()
{
    const int a = 1;
    int b = 2;

    // Method 1: use static_assert.
    // => since static_assert performs compile-time assertion checking, it
    //    will give you no overhead during runtime and no unnecessary generated code.
    static_assert(f(1), "");    // ok
    static_assert(f(a), "");    // ok
    //static_assert(f(b), "");  // error

    // Method 2: try to use your function in a constexpr expression.
    constexpr auto result_1 = f(1);    // ok
    constexpr auto result_a = f(a);    // ok
    //constexpr auto result_b = f(b);  // error

    // Method 3: use it in std::integral_constant.
    // => disadvantage: not generally applicable
    std::integral_constant<int, f(1)>::value;
    std::integral_constant<int, f(a)>::value;
    //std::integral_constant<int, f(b)>::value;  // error

    // Method 4: use it in a template instantiation.
    ForceCompileTimeEvaluation<f(1)> dummy_1;    // ok
    ForceCompileTimeEvaluation<f(a)> dummy_a;    // ok
    //ForceCompileTimeEvaluation<f(b)> dummy_b;  // error
}
