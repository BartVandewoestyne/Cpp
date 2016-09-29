/*
 * Example on std::swap.
 * 
 * References:
 *
 *   [1] http://en.cppreference.com/w/cpp/algorithm/swap
 */

#include <algorithm>
#include <iostream>
 
int main()
{
    int a = 5, b = 3;
 
    // before
    std::cout << a << ' ' << b << '\n';
   
    std::swap(a,b);

    // after
    std::cout << a << ' ' << b << '\n';
}
