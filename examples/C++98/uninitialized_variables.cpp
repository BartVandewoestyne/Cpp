/*
 * Example illustrating what values uninitialized variables can get.
 *
 * Test with different compilers and optimization levels to see the undefined
 * behavior.
 *
 * References:
 *   [1] https://mortoray.com/2014/04/16/the-uninitialized-variable-anathema-non-deterministic-c/
 */

#include <iostream>

struct Widget {
    bool b;
    int i;
    float f;
    double d;
};

int main()
{
    bool b;
    std::cout << "b = " << b << std::endl;

    int i;
    std::cout << "i = " << i << std::endl;

    float f;
    std::cout << "f = " << f << std::endl;

    double d;
    std::cout << "d = " << d << std::endl;

    Widget w;
    std::cout << "w.b = " << w.b << std::endl;
    std::cout << "w.i = " << w.i << std::endl;
    std::cout << "w.f = " << w.f << std::endl;
    std::cout << "w.d = " << w.d << std::endl;
}
