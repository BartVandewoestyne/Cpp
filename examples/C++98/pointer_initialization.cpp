/*
 * Example that shows how uninitialized pointers cause undefined behavior.
 *
 * Test with different compilers and optimization levels to see that there
 * is undefined behavior.
 *
 * References:
 *
 *   [1] ISO/IEC 14882
 */

#include <iostream>

struct Widget {
public:
    int* p;  // uninitialized pointer (see 12.6.2/4 in [1])
};

int main()
{
    int* pi;  // uninitialized pointer
    std::cout << pi << std::endl;   // undefined behavior

    Widget w;
    if (w.p != 0)  // undefined behavior
    {
        std::cout << "w.p is not NULL: " << w.p << std::endl;
    }
    else
    {
        std::cout << "w.p is NULL: " << w.p << std::endl;
    }
}
