/**
 * References:
 *
 *   [1] http://www.cprogramming.com/c++11/c++11-compile-time-processing-with-constexpr.html
 */

constexpr int multiply(int x, int y)
{
  return x * y;
}
 
// The compiler may evaluate this at compile time.
const int val = multiply(10, 10);
