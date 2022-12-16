/*
 * Key idea:
 * 
 *   - Variadic functions are functions (e.g. std::printf) which take a
 *     variable number of arguments.
 * 
 *   - The core guidelines advise against the use of (C-style) variadic
 *     functions.
 *
 *   - Variadic functions are not type-)safe and in general error prone and
 *     can be unsafe to use.
 *
 * References:
 *
 *   [cppreference] Variadic functions
 *     https://en.cppreference.com/w/cpp/utility/variadic
 *
 *   [cppreferenc]
 *     https://en.cppreference.com/w/cpp/language/variadic_arguments
 *
 *   [cppcoreguidelineis] ES.34: Don’t define a (C-style) variadic function
 *     https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#-es34-dont-define-a-c-style-variadic-function
 *
 *   [stackoverflow] Variable number of arguments in C++?
 *     https://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c
 */

#include <cstdarg>
#include <iostream>

void f(int n ...)
{
    va_list ap;  // a magic type for holding arguments
    va_start(ap, n);  // arg startup: "severity" is the first argument of error()

    for (int i =0; i < n; ++i)
    {
        // treat the next var as an int; no checking: a cast in disguise
        int  c = va_arg(ap, int);
        std::cout << c << std::endl;
    }

    va_end(ap);  // arg cleanup (don't forget this)
}

int main()
{
    f(5, 'a', 'b', 'c', 'd', 'e');
}
