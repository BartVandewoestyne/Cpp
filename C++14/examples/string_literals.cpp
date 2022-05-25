/*
 * References:
 *
 *   [cppreference] std::literals::string_literals::operator""s
 *     https://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s
 *
 *   [boccara20211008] A Recap on User Defined Literals
 *     https://www.fluentcpp.com/2021/10/08/a-recap-on-user-defined-literals/
 */

#include <string>

int main()
{
    using namespace std::literals::string_literals;

    // Here, myString1 is of type std::string.
    auto myString1 = "hello"s;

    // Here, myString2 is of type const char*.
    auto myString2 = "hello";
}
