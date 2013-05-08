/**
 * References:
 *   [1] http://ignoringthevoices.blogspot.be/2011/11/c11-initializer-lists-and-range-for.html
 */
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a = {1, 2, 3};

    for (const auto& e : a)
    {
        std::cout << e << std::endl;
    }
}
