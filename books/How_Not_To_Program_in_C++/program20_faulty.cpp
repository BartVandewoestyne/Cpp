/************************************************
 * Print out the square of the numbers          *
 * from 1 to 10                                 *
 ************************************************/
#include <iostream>

int main()
{
    int index; /* Index into the table */

    for (index = 1; index <= 10; ++index);
        std::cout << index << " squared " <<
            (index * index) << '\n';

    return (0);
}
