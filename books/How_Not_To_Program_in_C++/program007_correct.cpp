/************************************************
 * squares -- Print the squares of the numbers  *
 *      from 1 to 5.                            *
 ************************************************/
#include <iostream>

int main()
{
    // An array for the squares
    int array[5];

    int i;              // Index into the array

    for (i = 1; i <= 5; ++i) {
        array[i-1] = i*i;
    }

    for (i = 1; i <= 5; ++i) {
        std::cout << i << " squared is " <<
            array[i-1] << '\n';
    }
    return (0);
}
