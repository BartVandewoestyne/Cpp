/*
 * Key idea:
 *
 *   - In C++14, string literals and chrono literals were added.
 *
 * References:
 *
 *   [boccara20211008] A Recap on User Defined Literals
 *     https://www.fluentcpp.com/2021/10/08/a-recap-on-user-defined-literals/
 */

#include <string>

int main()
{
    using namespace std::literals::string_literals;

    // myString1 is of type std::string
    auto myString1 = "hello"s;

    // myString2 is of type const char*
    auto myString2 = "hello";
}
