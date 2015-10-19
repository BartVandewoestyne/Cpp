/**
 * Test program to show what happens if we assign a float to a double.
 */

#include <iomanip>
#include <iostream>

int main()
{
    std::cout.setf(std::ios::fixed, std::ios::floatfield);

    // Case 1: the value 1.1 cannot be exactly represented,
    //         notice the junk digits at the end.
    float f1 = 1.1;
    double d1 = f1;
    std::cout << std::setprecision(16) << f1 << std::endl;
    std::cout << std::setprecision(16) << d1 << std::endl;

    // Case 2: the value 2.5 can be exactly represented,
    //         notice there are no junk digits.
    float f2 = 2.5;
    double d2 = f2;
    std::cout << std::setprecision(16) << f2 << std::endl;
    std::cout << std::setprecision(16) << d2 << std::endl;

    // Case 3: immediately assigning 1.1 to a double gives
    //         more precision.
    double d3 = 1.1;
    std::cout << std::setprecision(16) << d3 << std::endl;
}
