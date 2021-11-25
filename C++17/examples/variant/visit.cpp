/*
 * References:
 *
 *   [cppreference] http://en.cppreference.com/w/cpp/utility/variant/visit
 *
 *   [copperspice20200110] std::visit
 *     https://youtu.be/AFsALrqFy_Q
 *
 *   [fahller20190613] Variant visitation variations
 *     https://youtu.be/ERHYJy5KxQo
 *
 *   [filipek20180910] How To Use std::visit With Multiple Variants
 *     https://www.bfilipek.com/2018/09/visit-variants.html
 */

#include <iostream>
#include <string>
#include <variant>

void print(std::variant<bool, int, std::string> result)
{
    // First parameter to std::visit is a generic lambda expression.
    // Second parameter is the std::variant result, and will be passed
    // as 'the current alternative' to the function as the parameter 'arg'.
    // We need to declare 'arg' as auto, as there is no way to know what
    // datatype result will contain.  Note that the visitor lambda expression
    // only needs to work for the datatypes listed in the variant, which are
    // bool, int and std::string.
    std::visit([](const auto& arg){ std::cout << arg; }, result);
}

int main()
{
    std::variant<bool, int, std::string> data;

    data = std::string("Ginger");
    print(data);

    data = 108;
    print(data);
}
