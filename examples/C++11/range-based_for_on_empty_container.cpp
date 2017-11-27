/**
 * This is a small test from myself to check how range-based for loops behave
 * for empty containers.
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> empty;
    std::vector<int> nonempty = { 1, 2, 3 };

    for (const auto& item : empty)
    {
        std::cout << item << std::endl;
    }

    for (const auto& number : nonempty )
    {
        std::cout << number << std::endl;
    }
}
