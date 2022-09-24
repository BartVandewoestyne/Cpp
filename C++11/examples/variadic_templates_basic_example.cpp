/**
 *
 * Basic example illustrating the use of Variadic Templates.
 *
 * References:
 *
 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U 
 */

#include <iostream>

void print()
{}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    print(args...);
}

int main()
{
    print(42, "hello", 2.3, 'a');
}
