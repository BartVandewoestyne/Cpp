/*
 * References:
 *
 *   [stackoverflow20130130] Cannot use .begin() or .end() on an array
 *     https://stackoverflow.com/questions/14595285/cannot-use-begin-or-end-on-an-array
 */

#include <array>
#include <vector>

#include <iterator>

int main()
{
    int c_array[5] = {};
    std::array<int, 5> cpp_array = {};
    std::vector<int> cpp_dynarray(5);

    auto c_array_begin = std::begin(c_array); // = c_array + 0
    auto c_array_end = std::end(c_array);     // = c_array + 5

    auto cpp_array_begin = std::begin(cpp_array); // = cpp_array.begin()
    auto cpp_array_end = std::end(cpp_array);     // = cpp_array.end()

    auto cpp_dynarray_begin = std::begin(cpp_dynarray); // = cpp_dynarray.begin()
    auto cpp_dynarray_end = std::end(cpp_dynarray);     // = cpp_dynarray.end()
}
