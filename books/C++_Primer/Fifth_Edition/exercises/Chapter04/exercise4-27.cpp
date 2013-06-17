#include <iostream>

using std::cout;
using std::endl;

int main()
{
    unsigned long ul1 = 3, ul2 = 7;

    // (a) 0000 0000 0000 0011 & 0000 0000 0000 0111 = 0000 0000 0000 0011 = 3
    std::cout << (ul1 & ul2) << std::endl;

    // (b) 0000 0000 0000 0011 | 0000 0000 0000 0111 = 0000 0000 0000 0111 = 7
    std::cout << (ul1 | ul2) << std::endl;

    // (c) 3 && 7 = TRUE = 1
    std::cout << (ul1 && ul2) << std::endl;

    // (d) 3 || 7 = TRUE = 1
    std::cout << (ul1 || ul2) << std::endl;
}
