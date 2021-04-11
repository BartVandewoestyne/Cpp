/*
 * Key ideas:
 *   - Apply binary operators to all elements of a parameter pack.
 *   - Supported syntax:
 *       (... OP pack)            => 'left binding'
 *       (init OP ... OP pack)
 *       (pack OP ...)            => 'right binding'
 *       (pack OP ... OP init)
 *
 * References:
 *
 *   [cukic20191030] Efficient QString concatenation with C++17 fold expressions
 *     https://www.qt.io/blog/efficient-qstring-concatenation-with-c17-fold-expressions
 *
 *   [grimm20190408] C++ Insights: Variadic Templates
 *     https://www.heise.de/developer/artikel/C-Insights-Variadic-Templates-4365343.html
 *
 *   [20170514] Fun with C++ constexpr, variadic templates, and fold expressions
 *     https://ryanmichaelcollins.github.io/blog/2017/05/14/fun-with-constexpr-and-variadic-templates
 *
 *   [grimm20170204] Fold Expressions
 *     http://www.modernescpp.com/index.php/fold-expressions
 *
 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U
 */

#include <iostream>

template <typename... T>
auto foldSum(T... s)
{
    return (... + s);  // s1 + s2 + s3 + ...
}

template <typename... Args>
void printAllArgs(Args&&... args)
{
    // std::cout << args1 << args2 << args 3 << ... << '\n'
    // (Note: no whitespace between args here!  You have to do some tricks
    // with functors or so to make that work according to Josuttis!)
    (std::cout << ... << args) << '\n';
}

int main()
{
    const auto x = foldSum(1, 2, 3);
    std::cout << "x = " << x << std::endl;

    printAllArgs("hello", 5, 2.0, false);
}
