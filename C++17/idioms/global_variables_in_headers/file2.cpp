#include "constants.h"

#include <iostream>

void printFromFile2()
{
    std::cout << "In translation unit 2:" << std::endl;
    std::cout << "  &ci1 = " << &ci1 << std::endl;
    std::cout << "  &ci2 = " << &ci2 << std::endl;
    std::cout << "  &sci1 = " << &sci1 << std::endl;
    std::cout << "  &sci2 = " << &sci2 << std::endl;
    std::cout << "  &x1 = " << &x1 << std::endl;
}
