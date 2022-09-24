/*
 * Key ideas:
 *   - std::tie can be used to define comparision operators
 *
 * Note:
 *   Consider using C++17's structured bindings instead of std::tie.
 *
 * See also:
 *   std::ignore
 *
 * References:
 *
 *   [boccara20210823] How to Define Comparison Operators by Default in C++
 *     https://www.fluentcpp.com/2021/08/23/how-to-define-comparison-operators-by-default-in-c/
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=34m15s
 */

#include <tuple>

std::tuple<int, int> f()
{
    return std::make_tuple(1, 42);
}

int main()
{
    int a;
    int b;
    std::tie(a, b) = f();
}
