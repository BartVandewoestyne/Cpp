/*
 * Answer:
 *
 *   1) The program sums all integers from -100 to 100.
 *
 *   2) The final value of sum is 0 because integers with opposite sign cancel
 *      each other.
 */

#include <iostream>

int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;

    std::cout << sum << std::endl;
}
