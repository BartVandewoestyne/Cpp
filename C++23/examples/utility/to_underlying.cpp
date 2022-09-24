/*
 * Key ideas:
 *
 *   - Returns the integer value of the underlying type of Enum, converted from e,
 *     equivalent to static_cast<std::underlying_type_t<Enum>>(e).
 *
 *   - std::to_underlying can be used to avoid converting an enumeration to an
 *     integer type other than its underlying type.
 *
 * References:
 *
 *   [cppreference] std::to_underlying
 *     https://en.cppreference.com/w/cpp/utility/to_underlying
 */

#include <cstdint>
#include <iostream>
#include <utility>

int main()
{
    enum class Id: std::uint16_t
    {
        First,
        Middle,
        Last
    };

    std::cout << std::to_underlying(Id::First) << std::endl;
    std::cout << std::to_underlying(Id::Middle) << std::endl;
    std::cout << std::to_underlying(Id::Last) << std::endl;
}
