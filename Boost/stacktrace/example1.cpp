/*
 * References:
 *
 *   [stackoverflow] Boost stack-trace not showing function names and line numbers
 *     https://stackoverflow.com/questions/52583544/boost-stack-trace-not-showing-function-names-and-line-numbers
 */

#include <boost/stacktrace.hpp>

#include <iostream>

void foo()
{
  std::cout << boost::stacktrace::stacktrace();
}

int factorial(int x)
{
  if (x < 2)
  {
    std::cout << boost::stacktrace::stacktrace();
    return 1;
  }
  return x * factorial(x - 1);
}

int main()
{
  std::cout << "Calling foo():" << std::endl;
  foo();

  std::cout << "Calling factorial(4):" << std::endl;
  factorial(4);
}