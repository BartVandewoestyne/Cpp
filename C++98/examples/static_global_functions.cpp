/*
 * static global functions are invisible to the linker, allowing other
 * compilation units to define functions with the same signature. Using
 * namespaces alleviates this problem to a large degree, but file-static
 * functions predate namespaces, because they are a feature inherited from the
 * C programming language.
 *
 * static functions have internal linkage, that is, they aren't visible outside
 * of their translation unit.
 *
 * A static function simply means that the linker cannot export the function
 * (i.e. make it visible to other translation units).  It makes the function
 * "private" to the current translation unit. It is the same as wrapping the
 * function in an anonymous namespace.
 *
 * References:
 *
 *   [arun20130207] C++ static local function vs global function
 *     https://stackoverflow.com/questions/14742664/c-static-local-function-vs-global-function
 *
 *   [codingfreak20100630] Static Functions in C
 *     http://codingfreak.blogspot.com/2010/06/static-functions-in-c.html
 */

#include <iostream>

static
void f() { std::cout << "f()" << std::endl; }

void g() { std::cout << "g()" << std::endl; }

int main()
{
  f();
  g();
}
