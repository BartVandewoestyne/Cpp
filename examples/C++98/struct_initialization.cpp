/*
 * References:
 *
 *   [grzenio2014] Initializing member variables of a struct in c++
 *     https://stackoverflow.com/questions/17106389/initializing-member-variables-of-a-struct-in-c
 *
 *   [sasha2009] Are members of a C++ struct initialized to 0 by default?
 *     https://stackoverflow.com/questions/1069621/are-members-of-a-c-struct-initialized-to-0-by-default
 */

#include <iostream>

struct Foo {
  double x;
  int i;
};

Foo f0;  // initialization (what type exactly?)

int main()
{
    Foo f1;       // no initialization
    Foo f2 = {};  // value initialization

    std::cout << f0.x << std::endl;
    std::cout << f0.i << std::endl;

    std::cout << f1.x << std::endl;
    std::cout << f1.i << std::endl;

    std::cout << f2.x << std::endl;
    std::cout << f2.i << std::endl;
}
