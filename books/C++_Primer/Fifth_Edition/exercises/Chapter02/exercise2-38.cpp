/**
 * The way decltype handles top-level const and references differs subtly from
 * the way auto does.  When the expression to which we apply decltype is a
 * variable, decltype returns the type of that variable, including top-level
 * const and references:
 */

// TODO: check this!

#include <iostream>

int main()
{
    int a = 0;
    const int ci = 0, &cj = ci;

    // Same type.
    auto b = a;
    decltype(a) c = a;

    // Different type.
    auto k1 = ci;          // k1 is probably 'int'
    decltype(ci) k2 = ci;  // k2 is probably 'const int'

    auto m1 = cj;          // m1 is probably 'int'
    decltype(cj) m2 = cj;  // m2 is probably 'const int&'
}
