/*
 * Should one pass an enum by value or by reference?
 *
 *   Pass by value:
 *     Pro's:
 *     Con's:
 *
 *   Pass by reference:
 *     Pro's:
 *       - If you are later going to replace them with a class, then keeping the API
 *         the same and enforcing the const-ness might make sense.
 *     Con's:
 *
 * It's interesting to compare the generated assembler output at https://godbolt.org/.
 *
 * References:
 *
 *   [pilpel20160122] Pass an enum to a function - by value or by reference? [duplicate]
 *     https://stackoverflow.com/questions/34943170/pass-an-enum-to-a-function-by-value-or-by-reference
 *
 *   [patton20110726] C++: Is it better to pass an enum as a value or as a const reference?
 *     https://stackoverflow.com/questions/6834581/c-is-it-better-to-pass-an-enum-as-a-value-or-as-a-const-reference
 *
 *   [pomeranz20070723] 7.2 -- Passing arguments by value
 *     http://www.learncpp.com/cpp-tutorial/72-passing-arguments-by-value/
 */

#include <iostream>

enum Color
{
    Red,
    Green,
    Blue
};

bool byReference(const Color& color)
{
    return color == Red;
}

bool byValue(const Color color)
{
    return color == Red;
}

int main()
{
    Color color;
    byReference(color);
    byValue(color);
}
