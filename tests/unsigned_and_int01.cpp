#include <iostream>

int main()
{
    unsigned u = 10;
    int i = -42;
    std::cout << i + i << std::endl;  // prints -84
    std::cout << u + i << std::endl;  // if 32-bit ints, prints 4294967264

    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << std::endl; // ok: result is 32
    std::cout << u2 - u1 << std::endl; // ok: but the result will wrap around
}
