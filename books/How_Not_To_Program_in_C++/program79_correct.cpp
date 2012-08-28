/************************************************
 * Print out the square of the numbers          *
 *      from 1 to 10.                           *
 ************************************************/
#include <iostream>

/*********************************** ************
 * macro to square a number.                    *
 ************************************************/
#define SQR(x) ((x) * (x))

int main()
{
    int number; // The number we are squaring

    number = 1;

    while (number <= 10) {
        std::cout << number << " squared is " <<
            SQR(number) << std::endl;
        ++number;
    }

    return (0);
}
