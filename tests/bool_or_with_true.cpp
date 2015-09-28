#include <iostream>

int main()
{
    bool x = false;
    std::cout << (x |= true) << std::endl;

    x = true;
    std::cout << (x |= true) << std::endl;
}
