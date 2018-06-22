/*
 * References:
 *
 *   [1] "Deep C++", Maudal, June 14, 2013.  A 60 minute session at Norwegian
 *       Developers Conference 2013, slide 31.
 */

#include <iostream>

int main()
{
    int v[] = {0,2,4,6,8};
    int i = 1;
    int n = i + v[++i] + v[++i];
    std::cout << n << std::endl;
}
