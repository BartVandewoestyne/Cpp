/*
 * Key issues:
 *   - All returned values must be of the same type.
 *
 * References:
 *
 *   [oopscene20180304] C++: "auto" return type deduction
 *     https://oopscenities.net/2018/03/04/auto-return-type-deduction/
 *
 *   [guzman2017] Don't use C++ auto? Restricting auto is not the best decision for your company, and it is unfair to your developers. Instead, train them on how to use it.
 *     http://swdevmastery.com/dont-use-c-auto-restricting-auto-is-not-the-best-decision-for-your-company-and-it-is-unfair-to-your-developers-instead-train-them-on-how-to-use-it/
 */

#include <vector>

auto f()
{
    int result = 0;

    return result;  // f's return type is int
}

auto h(std::vector<int>& v, int i)
{
    return v[i];  // h's return type is int
}

// For recursive functions, a return value must be returned before the
// recursive call in order to let the compiler know what will be the type of
// the value to return.
auto accumulator(int n)
{
    if (n == 0)
        return 0;
    return n + accumulator(n - 1);
}

// error: can't deduce type;
// Initializer List rule doesn't apply
//auto g()
//{
//    return {0, 1, 2, 3};
//}

// error: not all returned values are of the same type!
//auto f(int n)
//{
//    if (n == 1)
//        return 1;
//    return 2.0;
//}
