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
 *   [iglberger20211025] Back to Basics: Designing Classes (part 2 of 2)
 *     https://youtu.be/O65lEiYkkbc?si=jGNK8b4wqPKbrWhW&t=804
 *
 *   [filipek20200302] In-class Member Initialisation: From C++11 to C++20
 *     https://www.bfilipek.com/2015/02/non-static-data-members-initialization.html
 *
 *   [stackoverflow20130513] Why can in-class initializers only use = or {}?
 *     https://stackoverflow.com/questions/16329962/why-can-in-class-initializers-only-use-or
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
