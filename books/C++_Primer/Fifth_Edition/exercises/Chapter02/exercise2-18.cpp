#include <iostream>

int main()
{
    int x = 1;
    int y = 2;
    int *p = &x;

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "p = " << p << std::endl;

    // Change the value of a pointer.
    p = &y;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "p = " << p << std::endl;

    // Change the value to which the pointer points.
    *p = 3;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "p = " << p << std::endl;
}
