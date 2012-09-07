/************************************************
 * double -- Print a double table for the       *
 *      numbers 1 through 10.                   *
 ************************************************/
#include <iostream>

/************************************************
 * DOUBLE -- Macro to double the value of a     *
 * number.                                      *
 ************************************************/
#define DOUBLE (value) ((value) + (value))

int main()
{
    // Counter for the double list
    int counter;

    for (counter = 1; counter <= 10; ++counter)
    {
        std::cout << "Twice " << counter << " is " <<
            DOUBLE(counter) << '\n';
    }

    return (0);
}
