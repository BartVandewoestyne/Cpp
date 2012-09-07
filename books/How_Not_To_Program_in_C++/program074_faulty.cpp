/************************************************
 * gross -- Print out a table of 1 to 10 gross. *
 ************************************************/
// A Gross is a dozen - dozen
#define GROSS (12 ** 2)

#include <iostream>

int main()
{
    int i;      // Index into the table

    for (i = 1; i <= 10; ++i)
    {
        std::cout << i << " gross is " <<
            (GROSS * i) << '\n';
    }

    return (0);
}
