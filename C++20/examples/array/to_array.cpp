/*
 * References:
 *
 *   [odwyer20200806] The “array size constant” antipattern
 *     https://quuxplusone.github.io/blog/2020/08/06/array-size/
 */

#include <array>

int main()
{
    // In C++20, we can write the below, which makes a C array and then
    // move-constructs its elements into the std::array.
    auto myArray = std::to_array<int>({2, 7, 1, 8, 2});
    constexpr int myArraySize = myArray.size();
}
