#include <iostream>

int main()
{
    int i;
    double d;

    // (a)
    d = i = 3.5;
    std::cout << "i = " << i << ", d = " << d << std::endl;

    // (b)
    i = d = 3.5;
    std::cout << "i = " << i << ", d = " << d << std::endl;
}
