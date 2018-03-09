/*
 * References:
 *
 *   [arun20130207] C++ static local function vs global function
 *     https://stackoverflow.com/questions/14742664/c-static-local-function-vs-global-function
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
