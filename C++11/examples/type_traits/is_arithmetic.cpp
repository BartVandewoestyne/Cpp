/*
 * References:
 *
 *   [tutorialspoint] is_arithmetic Template in C++
 *     https://www.tutorialspoint.com/is-arithmetic-template-in-cplusplus
 */
#include <ios>
#include <iostream>
#include <type_traits>

class Foo {};

int main()
{
   std::cout << std::boolalpha;
   std::cout << "Foo class : "<< std::is_arithmetic<Foo>::value << std::endl;
   std::cout << "bool: "<< std::is_arithmetic<bool>::value << std::endl;
   std::cout << "long: "<< std::is_arithmetic<long>::value << std::endl;
   std::cout << "short: "<< std::is_arithmetic<short>::value << std::endl;
}
