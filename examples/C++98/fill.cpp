/*
 * Example on how to fill an array with a certain value.
 *
 * References:
 *
 *   [1] https://christoph-conrads.name/implicit-type-conversions-gone-wrong-cpp-edition/
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    int n = 100;
    int* array = new int[n];
    
    //fill(array, array + n, x);
    fill_n(array, n, x);

    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}
