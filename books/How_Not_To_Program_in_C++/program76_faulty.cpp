/************************************************
 * Double -- Print double table.                *
 *                                              *
 * Print the numbers 1 through 5 and their       *
 *      doubles.                                *
 ************************************************/
#include <iostream>

/************************************************
 * DOUBLE -- Given a number return its double. *
 ************************************************/
#define DOUBLE(x) (x * 2)

int main()
{
    int i;       // Number to print and to double

    for (i = 0; i < 5; ++i) {
        std::cout << "The double of " << i+1 <<
            " is " << DOUBLE(i+1) << std::endl;
    }

    return (0);
}
