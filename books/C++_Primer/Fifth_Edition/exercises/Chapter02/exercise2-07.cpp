#include <iostream>

int main()
{
    // OK!
    // \012 => octal notation for Line Feed
    // \145 => octal notation for character e
    std::cout << "Who goes with F\145rgus?\012" << std::endl;

    // OK!  Value = 31.4
    std::cout << 3.14e1L << std::endl;

    // error: invalid suffix "f" on integer constant
    //std::cout << 1024f << std::endl;

    // OK!  Value = 3.14
    std::cout << 3.14L << std::endl;
}
