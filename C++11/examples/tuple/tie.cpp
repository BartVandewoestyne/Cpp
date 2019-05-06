/*
 * Note:
 *   Consider using C++17's structured bindings instead of std::tie.
 *
 * See also:
 *   std::ignore
 *
 * References:
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
