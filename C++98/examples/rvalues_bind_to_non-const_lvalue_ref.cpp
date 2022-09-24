/*
 * References:
 *
 *   [ibm] IBM XL C/C++ for Blue Gene/Q V12.1 documentation - The IBM XL C++ language extensions - Binding an rvalue to a non-const or volatile lvalue reference
 *     https://www.ibm.com/support/knowledgecenter/en/SS2LWA_12.1.0/com.ibm.xlcpp121.bg.doc/language_ref/bindingrvalue.html
 *
 *   [sushiandwow2016XXXX] Why does C++ not adopt MSVC extension allowing temp objects to be assigned to non-const references (lvalues)?
 *     https://www.reddit.com/r/cpp/comments/3d3p85/why_does_c_not_adopt_msvc_extension_allowing_temp/
 *
 *   [stackoverflow20150418] Binding r-value to l-value reference is non-standard Microsoft C++ extension
 *     https://stackoverflow.com/questions/29717800/binding-r-value-to-l-value-reference-is-non-standard-microsoft-c-extension
 *
 *   [trismegistos20140729] Why reference can not capture temporary while const ref and rval ref can [duplicate]
 *     https://stackoverflow.com/questions/25025538/why-reference-can-not-capture-temporary-while-const-ref-and-rval-ref-can
 *
 *   [sawicki20120131] Visual C++ is so Liberal
 *     http://www.asawicki.info/news_1482_visual_c_is_so_liberal.html
 *
 *   [malistov20091014] How come a non-const reference cannot bind to a temporary object?
 *     https://stackoverflow.com/questions/1565600/how-come-a-non-const-reference-cannot-bind-to-a-temporary-object
 *
 *   [stroustrup1994] The Design and Evolution of C++
 */

#include "Foo.h"

#include <iostream>

void f(Foo& f)
{
    std::cout << "f(Foo&)" << std::endl;
}

int main()
{
    f(Foo());  // error: cannot bind non-const lvalue reference of type 'Foo&' to an rvalue of type 'Foo'
}
