/*!
 * References:
 *
 *   [varun2017] C++11: std::array Tutorial and examples
 *     http://thispointer.com/c11-stdarray-tutorial-and-examples/
 *
 *   [1] http://www.modernescpp.com/index.php/std-array-dynamic-memory-no-thanks
 *   [2] https://www.embeddedrelated.com/showarticle/1031.php
 *   [3] https://a4z.bitbucket.io/blog/2017/01/19/A-convenient-constructor-for-std::array.html
 */

#include <algorithm>
#include <array>
#include <iostream>

int main()
{
    // Initialize the C++11 std::array.
    std::array<int, 8> array{1, 2, 3, 4, 5, 6, 7, 8};

    // Print the array.
    std::for_each(array.begin(), array.end(), [](int v){ std::cout << v << " "; });
    std::cout << std::endl;

    // Calculate the sum of the array using a global variable.
    int sum = 0;
    std::for_each(array.begin(), array.end(), [&sum](int v){ sum += v; });
    std::cout << "sum = " << sum << std::endl;

    // Change each array element to its second power.
    std::for_each(array.begin(), array.end(), [](int& v){ v = v*v; });
    std::for_each(array.begin(), array.end(), [](int v){ std::cout << v << " "; });
    std::cout << std::endl;

    // Set each element of the array to 999.
    array.fill(999);
    std::for_each(array.begin(), array.end(), [](int v){ std::cout << v << " "; });
    std::cout << std::endl;


    // My own little tests for range-based for loops in combination with std::array.
    {
        std::array<int, 8> array{1, 2, 3, 4, 5, 6, 7, 8};
        
        // TODO: auto?  const auto???
        for (auto it = array.cbegin(); it != array.cend(); ++it)
        {
            // TODO: Check if we are the last element?
            if (std::next(it) == array.cend())
            {
                std::cout << *it << std::endl;
            }
        }
    }
}
