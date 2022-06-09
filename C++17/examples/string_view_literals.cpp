/*
 * Key idea:
 *
 *   - string_view literals were added in C++17.
 *
 * Reference:
 *
 *   [cppreference] std::literals::string_view_literals::operator""sv
 *     https://en.cppreference.com/w/cpp/string/basic_string_view/operator%22%22sv
 *
 *   [boccara20211008] A Recap on User Defined Literals
 *     https://www.fluentcpp.com/2021/10/08/a-recap-on-user-defined-literals/
 */

#include <string_view>

int main()
{    
    using namespace std::literals::string_view_literals;

    // myStringView is of type std::string_view
    auto myStringView = "hello"sv;
}
