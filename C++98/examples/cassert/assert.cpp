/*
 * assert operates at runtime (static_assert at compile time).
 *
 * References:
 *
 *   [alex20170902] 7.12a - Assert and static_assert
 *     http://www.learncpp.com/cpp-tutorial/7-12a-assert-and-static_assert/
 *
 *   [cppcoreguidelines20150928] I.27: Use assert for self-checking and documentation
 *     https://github.com/isocpp/CppCoreGuidelines/issues/183
 *
 *   [lakos1996XXXX] Large-Scale C++ Software Design (section 1.3 page 32).
 */

#include <cassert>

int main()
{
    assert(false && "Some text");
}
