/**
 * References:
 *
 *   [1] http://stackoverflow.com/questions/6963894/c11-how-to-use-range-based-for-loop-with-stdmap
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };
    for ( auto xyz : numbers )
    {
        std::cout << xyz << std::endl;
    }
}
