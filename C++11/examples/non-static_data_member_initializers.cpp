/*
 * Illustrates default member initializers.
 * 
 * References:
 *
 *   [cppreference] Member initialization
 *     http://en.cppreference.com/w/cpp/language/data_members#Member_initialization
 *
 *   [filipek20200302] In-class Member Initialisation: From C++11 to C++20
 *     https://www.bfilipek.com/2015/02/non-static-data-members-initialization.html
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
