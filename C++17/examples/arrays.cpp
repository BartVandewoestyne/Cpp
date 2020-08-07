/*
 * References:
 *
 *   [odwyer20200806] The “array size constant” antipattern
 *     https://quuxplusone.github.io/blog/2020/08/06/array-size/
 */

#include <array>

int main()
{
    // For ints, C++17's CTAD permits us to write:
    // (note that this doesn't work if you want for example an array of short
    // or uint32_t).
    std::array myArray = {2, 7, 1, 8, 2};
}
