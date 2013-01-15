/**
 * A constexpr function is a named constant expression with parameters.  It’s
 * meant to replace macros and hardcoded literals without sacrificing
 * performance or type safety.
 *
 * References:
 *
 *   [1] http://www.cprogramming.com/c++11/c++11-compile-time-processing-with-constexpr.html
 *   [2] http://blog.smartbear.com/software-quality/bid/248591/using-constexpr-to-improve-security-performance-and-encapsulation-in-c
 */

constexpr int multiply(int x, int y)
{
  return x * y;
}
 
// The compiler may evaluate this at compile time.
const int val = multiply(10, 10);
