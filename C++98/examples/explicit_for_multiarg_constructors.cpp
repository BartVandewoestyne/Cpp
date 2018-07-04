/*
 * Example to illustrate how adding explicit to multiargument constructors somehow
 * makes sense as part of future proofing later changes to the code.
 *
 * Although I'm not sure if we should add the explicit keyword in this case... one might
 * as well argue that the explicit keyword must be added at the moment the default value
 * for the c parameter is introduced...
 *
 * References:
 *
 *   [peterg20160824] Explicit constructor taking multiple arguments
 *     https://stackoverflow.com/questions/39122101/explicit-constructor-taking-multiple-arguments
 */

#include <iostream>

// Initial version of the class: the constructor doesn't directly benefit from explicit.
class A1 {
    public:
        explicit A1(int b, int c) { std::cout << "A1(int, int)" << std::endl; }
};

// Some time later, you decide to add a default value for c, so the class becomes this:
class A2 {
    public:
        // Note the difference in behavior with or without explicit!
        //explicit
        A2(int b, int c = 0) { std::cout << "A2(int, int)" << std::endl; }
};

void f(const A2& a2)
{
    std::cout << "f(const A2& a2)" << std::endl;
}

int main()
{
    A1(1, 2);    // always ok

    A2 x(1, 2);  // always ok
    A2 y(1);     // always ok

    f(x);        // always ok (correct type, no conversion necessary)

    f(1);        // nok with explicit, ok without explicit (implicit conversion)
}
