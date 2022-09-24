/*
 * Example of argument-dependent name lookup.
 *
 * References:
 *
 *   [odwyer20190408] ADL insanity
 *     https://quuxplusone.github.io/blog/2019/04/08/adl-insanity/
 *
 *   [20190325turner] C++ Weekly - Argument Dependent Lookup (ADL)
 *     https://youtu.be/agS-h_eaLj8
 *
 *   [20121216bo] Advance C++: Koenig Lookup - Argument Dependent Lookup (ADL)
 *     https://youtu.be/TxgPZXe8XTo 
 *
 *   [wikipedia] Argument-dependent name lookup
 *     https://en.wikipedia.org/wiki/Argument-dependent_name_lookup
 *
 *   [2] C++ ANSI ISO IEC 14882-2003 basic.lookup.koenig
 */

#include <iostream>

namespace foo
{
   class A {};

   void f(const A& a, int i) { std::cout << "Calling foo::f(A&, int)." << std::endl; }
}

int main() 
{
   foo::A a;

   f(a, 0);  // calls foo::f
}
