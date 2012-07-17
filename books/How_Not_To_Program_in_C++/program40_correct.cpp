/************************************************
 * accuracy test.                               *
 *                                              *
 * This program figures out how many bits       *
 * accuracy you have on your system.  It does   *
 * this by adding up checking the series:       *
 *                                              *
 *              1.0 == 1.1 (binary)             *
 *              1.0 == 1.01 (binary)            *
 *              1.0 == 1.001 (binary)           *
 *              ....                            *
 *                                              *
 * Until the numbers are equal.   The result is *
 * the number of bits that are stored in the    *
 * fraction part of the floating point number.   *
 ************************************************/
#include <iostream>

int main()
{
    /* two numbers to work with */
    float number1, number2;

    /* loop counter and accuracy check */
    int counter;

    number1 = 1.0;
    number2 = 1.0;
    counter = 0;

    while (1)
    {
        // Volatile keeps the optimizer from
        // putting the result in a register
        volatile float result;
    
        result = number1 + number2;
        if (result == number1)
            break;

        ++counter;
        number2 = number2 / 2.0;

    }

    std::cout << counter << " bits accuracy.\n";
    return (0);
}
