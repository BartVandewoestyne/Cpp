/*
 * Illustrates default member initializers.
 * 
 * References:
 *
 *   [C++ Super-FAQ] In-class member initializers
 *     https://isocpp.org/wiki/faq/cpp11-language-classes#member-init
 *
 *   [cppreference] Member initialization
 *     http://en.cppreference.com/w/cpp/language/data_members#Member_initialization
 *
 *   [filipek20200302] In-class Member Initialisation: From C++11 to C++20
 *     https://www.bfilipek.com/2015/02/non-static-data-members-initialization.html
 *
 *   [kalev202120823] C++11 Tutorial: New Constructor Features that Make Object Initialization Faster and Smoother
 *     https://smartbear.com/blog/c11-tutorial-new-constructor-features-that-make-ob/
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
