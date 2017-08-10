/*
 * An attempty to use std::accumulate with 2D std::arrays.
 *
 * References:
 *   [1] https://stackoverflow.com/questions/44807347/using-stdaccumulate-on-a-two-dimensional-stdarray
 */

#include <array>
#include <iostream>
#include <numeric>

int main()
{
    std::array<std::array<int, 2>, 3> m = {{ {1, 2}, {3, 4}, {5, 6} }};
    auto sum = std::accumulate(m.cbegin(), m.cend(), 0, [](auto lhs, const auto& rhs) {
        return std::accumulate(rhs.cbegin(), rhs.cend(), lhs);
    });
 
    //std::array<int, 3> m = {1, 2, 3};
    //const auto sum = std::accumulate(m.begin(), m.end(), 0);

    std::cout << "sum = " << sum << std::endl;
}
