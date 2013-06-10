/**
 * TODO:
 *   - Move the printing to a separate function.
 */

#include <iostream>
#include <iterator>

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };

    // Print the array.
    int *pbeg = std::begin(arr);
    int *pend = std::end(arr);
    while (pbeg != pend)
    {
        std::cout << *pbeg << " ";
        ++pbeg;
    }
    std::cout << std::endl;

    // Set the array to all zeros.
    pbeg = std::begin(arr);
    pend = std::end(arr);
    while (pbeg != pend)
    {
        *pbeg = 0;
        ++pbeg;
    }

    // Print the array.
    pbeg = std::begin(arr);
    pend = std::end(arr);
    while (pbeg != pend)
    {
        std::cout << *pbeg << " ";
        ++pbeg;
    }
    std::cout << std::endl;
}
