#include "constants.h"

#include <iostream>

void printFromFile2()
{
    std::cout << "In translation unit 2:" << std::endl;
    std::cout << "  &ci = " << &ci << std::endl;
    std::cout << "  &sci = " << &sci << std::endl;
    std::cout << "  &x = " << &x << std::endl;
}
