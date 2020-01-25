#include "constants.h"

#include <iostream>

void printFromFile1()
{
    std::cout << "In translation unit 1:" << std::endl;
    std::cout << "  &ci = " << &ci << std::endl;
    std::cout << "  &sci = " << &sci << std::endl;
}
