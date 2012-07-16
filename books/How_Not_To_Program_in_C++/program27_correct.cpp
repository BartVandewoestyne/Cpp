/************************************************
 * if_test -- Simple test of the if statement.  *
 ************************************************/
#include <iostream>

int main()
{
    int i1 = 12;        // A number
    int i2 = 3;         // Another number

    if (i1 && i2)
        std::cout << "Both numbers are non-zero\n";
    else
        std::cout << "At least one number is zero\n";
    return (0);
}
