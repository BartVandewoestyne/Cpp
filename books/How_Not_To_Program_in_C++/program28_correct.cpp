/************************************************
 * zero_array -- Demonstrate how to use memset  *
 *      to zero an array.                       *
 ************************************************/
#include <iostream>
#include <cstring>

int main()
{
    // An array to zero
    int array[5] = {1, 3, 5, 7, 9};

    // Index into the array
    int i;

    // Zero the array
    memset(array, '\0', sizeof(array));

    // Print the array
    for (i = 0; i < 5; ++i)
    {
        std::cout << "array[" << i << "]= " <<
            array[i] << std::endl;
    }
    return (0);
}
