/*
 * File that illustrates how short-circuiting with boolean operators works.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/628526/is-short-circuiting-boolean-operators-mandated-in-c-c-and-evaluation-order
 */

#include <iostream>

// f will return true if it has been given true as parameter
bool f(bool value)
{
    std::cout << "f() => " << value << std::endl;
    return value;
}

// g will return true if it has been given true as parameter
bool g(bool value)
{
    std::cout << "g() => " << value << std::endl;
    return value;
}

int main()
{
  // g should not get executed.
  if ( f(false) && g(false) )
  {
      std::cout << "f(false) && g(false)" << std::endl;
  }
  std::cout << std::endl;

  // both f and g are executed
  if ( f(true) && g(false) )
  {
      std::cout << "f(true) && g(false)" << std::endl;
  }
  std::cout << std::endl;

  // bot f and g are executed
  if ( f(true) && g(true) )
  {
      std::cout << "f(true) && g(true)" << std::endl;
  }
  std::cout << std::endl;

  // g should not get executed
  if ( f(false) && g(true) )
  {
      std::cout << "f(false) && g(true)" << std::endl;
  }
}
