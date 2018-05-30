/*
 * References:
 *
 *   [trismegistos20140729] Why reference can not capture temporary while const ref and rval ref can [duplicate]
 *     https://stackoverflow.com/questions/25025538/why-reference-can-not-capture-temporary-while-const-ref-and-rval-ref-can
 *
 *   [malistov20091014] How come a non-const reference cannot bind to a temporary object?
 *     https://stackoverflow.com/questions/1565600/how-come-a-non-const-reference-cannot-bind-to-a-temporary-object
 *
 *   [stroustrup1994] The Design and Evolution of C++
 *
 * TODO: Visual C++ behaves differently in this respect?  Find doc or blogpost about this.
 */

#include "Foo.h"

#include <iostream>

// rvalue cannot bind to this non-const lvalue reference?
void f(Foo& f) { std::cout << "f(Foo&)" << std::endl; }

int main()
{
    f(Foo());
}
