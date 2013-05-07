/**
 * References:
 *
 *   [1] http://stackoverflow.com/questions/6963894/c11-how-to-use-range-based-for-loop-with-stdmap
 *   [2] http://mbevin.blogspot.be/2012/11/range-based-for.html
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };

    //for (auto  number : numbers)        // by value
    for (auto& number : numbers)        // by reference
    //for (const auto& number : numbers)  // by const reference
    {
        number += 1;
    }

    for (const auto& number : numbers )
    {
        std::cout << number << std::endl;
    }
}
