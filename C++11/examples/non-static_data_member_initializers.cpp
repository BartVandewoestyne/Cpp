/*
 * Illustrates default member initializers.
 * 
 * References:
 *   [1] http://en.cppreference.com/w/cpp/language/data_members#Member_initialization
 */

#include <iostream>

struct S
{
    int n = 7;  // non-static data member initializers only
                // available since C++11
};

int main()
{
    S s;
    std::cout << s.n << std::endl;
}
