/************************************************
 * A program to sum the numbers from 1 to 100   *
 * using a brute force algorithm.               *
 ************************************************/
#include <iostream>

int main()
{
    int sum = 0;  // The running sum
    int count;    // The current number

    for (count = 1; count <= 100; ++count)
        sum += count;

    std::cout <<
        "The sum of the numbers " <<
        "between 1 and 100 is " <<
        sum << '\n';
    return (0);
}
