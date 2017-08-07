/*
 * My own example for std::hypot.
 *
 * References:
 *   [1] http://en.cppreference.com/w/cpp/numeric/math/hypot
 */

#include <cmath>
#include <iostream>

int main()
{
  std::cout << "std::hypot(3.0, 4.0) = " << std::hypot(3.0, 4.0) << std::endl;
}
