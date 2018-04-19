/*
 * Pass enum classes by value or reference?
 *
 * My current conclusion:
 *   * Pass by value, unless you want to change their value, then pass by reference.
 *
 * References:
 *
 *   [abumusamq20130703] Enum class C++11 by reference or value
 *     https://stackoverflow.com/questions/17439672/enum-class-c11-by-reference-or-value?rq=1
 */

#include <iostream>

enum class Color
{
    Red,
    Green,
    Blue
};

bool byReference(const Color& color)
{
    return color == Color::Red;
}

bool byValue(const Color color)
{
    return color == Color::Red;
}

int main()
{
    const auto color = Color::Red;
    const auto byRef = byReference(color);
    const auto byVal = byValue(color);
}
