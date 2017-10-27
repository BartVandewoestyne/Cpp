/*
 * References:
 *
 *   [boccara2017] Function Aliases in C++
 *     https://www.fluentcpp.com/2017/10/27/function-aliases-cpp/
 */

#include <iostream>

// Original function.
int g(int parameter)
{
    std::cout << "parameter is " << parameter << std::endl;
    return 1;
}

// C++98 one-liner wrapper function.
//
// Disadvantages:
//
//   * could make extra copies if ever the function is not inlined,
//   * can take an annoying amount of code if there are several parameters
//     to be passed down to the low-level function,
//   * when debugging, it's an extra step you need to step through
int f1(int parameter)
{
    return g(parameter);
}

// C++11 alternative: function alias.
//
// Advantages:
//
//   * makes no extra copy, since calling f2 is calling g
//   * you don't need to have the full definition of f available at the
//     point of the function alias declaration.  Only the declaration of g
//     needs to be visible.  The actual resolution is made by the linker, like
//     with any other function.
//
// Disadvantages:
//   * removes one extra step in debugging.  When you step in f2, you directly
//     fall into g and you don't even see f2 in the call stack, which can be disturbing.
//   * since f2 is a function reference, it will not be inlined.
auto f2 = g;

int main()
{
    f1(42);

    f2(43);
}
