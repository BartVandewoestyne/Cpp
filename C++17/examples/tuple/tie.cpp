/*
 * Key ideas:
 *
 *   - Structured bindings can be used for creating *new* variables to hold the result.
 *     If you want to assign the result to *existing* variables, then you can use the old standby std::tie.
 *
 * References:
 *
 *   [chen20200925] Structured binding may be the new hotness, but we’ll always have std::tie
 *     https://devblogs.microsoft.com/oldnewthing/20200925-00/?p=104297
 */

#include <tuple>
#include <utility>

int main()
{
    // C++17 introduced structured binding, which lets you assign an
    // expression to multiple variables.
    auto [a,b] = std::pair(1, "hello");  // int a = 1
                                         // char const* b = "hello"

    // If you want to assign the result to existing variables, then you can
    // use the old standby std::tie.
    int c;
    char const* d;
    std::tie(c, d) = std::pair(1, "hello");
}
