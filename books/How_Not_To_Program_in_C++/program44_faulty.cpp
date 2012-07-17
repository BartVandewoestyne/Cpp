/************************************************
 * diff elements -- Print the differences       *
 *      between adjacent elements of any array. *
 ************************************************/
#include <iostream>

// Any array containing pairs of values.
// Ends with the sentinel -1
static int array[12] =
{
    44, 8,
    50, 33,
    50, 32,
    75, 39,
    83, 33,
    -1, -1
};

// Array to hold the differences
static int diff[6];

int main()
{
    int i;      // Index into the array

    // Index into the diff results
    int diff_index;

    i = 0;
    diff_index = 0;
    // Difference adjacent elements of an array
    while (array[i] != 0)
    {
        diff[diff_index++] =
            array[i++] - array[i++];
    }

    // Print the results
    for (i = 0; i < 6; ++i)
    {
        std::cout << "diff[" << i << "]= " <<
            diff[i] << std::endl;
    }
    return (0);
}
