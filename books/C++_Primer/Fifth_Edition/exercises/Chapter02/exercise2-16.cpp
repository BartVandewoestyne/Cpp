// TODO: explain what the assignments do.

#include <iostream>

int main()
{
    int i = 0, &r1 = i;  double d = 0, &r2 = d;

    // OK
    r2 = 3.14159;

    // OK
    r2 = r1;

    // OK
    i = r2;

    // OK
    r1 = d;

    std::cout << "i = " << i << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
}
