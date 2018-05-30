/*
 * References:
 *
 *   [shaovoon20180516] C++11: Compile-time Conditional Types
 *     https://codingtidbit.com/2018/05/16/c11-compile-time-conditional-types/
 */

#include <iostream>
#include <type_traits>
#include <typeinfo>

int main() 
{
    typedef std::conditional<true, int, double>::type Type1;
    typedef std::conditional<false, int, double>::type Type2;
 
    std::cout << typeid(Type1).name() << '\n';
    std::cout << typeid(Type2).name() << '\n';
}
