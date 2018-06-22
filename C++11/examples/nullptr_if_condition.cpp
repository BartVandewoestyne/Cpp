/*
 * My own test program to check if nullptr can be used in an if-condition.
 */

#include <iostream>

void check(int* p)
{
    if (p)
    {
        std::cout << "p -> true" << std::endl;
    } else
    {
        std::cout << "p -> false" << std::endl;
    }
}

int main()
{
    int x = 0;

    int* px = &x;
    check(px);

    px = nullptr;
    check(px);
}
