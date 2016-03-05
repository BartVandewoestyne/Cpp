/*
 * Example of argument-dependent name lookup.
 *
 * References:
 *   [1] https://en.wikipedia.org/wiki/Argument-dependent_name_lookup
 *   [2] C++ ANSI ISO IEC 14882-2003 basic.lookup.koenig
 */

namespace NS 
{
   class A {};
   void f( A &a, int i) {}
}

int main() 
{
   NS::A a;
   f( a, 0 );    //calls NS::f
}
