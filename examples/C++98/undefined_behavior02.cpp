/*
 * References:
 *
 *   [1] "Deep C++", Maudal, June 14, 2013.  A 60 minute session at Norwegian
 *       Developers Conference 2013, slide 84.
 */

#include <iostream>

void foo()
{
    int a;
    ++a;
    std::cout << a << std::endl;
}

int main()
{
    foo();
    foo();
    foo();
}
