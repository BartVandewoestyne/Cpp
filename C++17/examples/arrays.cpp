/*
 * References:
 *
 *   [odwyer20200806] The “array size constant” antipattern
 *     https://quuxplusone.github.io/blog/2020/08/06/array-size/
 */

#include <array>

int main()
{
    // C++17's CTAD permits us to write
    std::array myArray = {2, 7, 1, 8, 2};
}
