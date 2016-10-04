/**
 * A constexpr function is a named constant expression with parameters.  It’s
 * meant to replace macros and hardcoded literals without sacrificing
 * performance or type safety.
 *
 * References:
 *
 *   [1] http://www.cprogramming.com/c++11/c++11-compile-time-processing-with-constexpr.html
 *   [2] http://blog.smartbear.com/software-quality/bid/248591/using-constexpr-to-improve-security-performance-and-encapsulation-in-c
 *   [3] http://enki-tech.blogspot.be/2012/09/c11-compile-time-calculator-with.html
 *   [4] https://akrzemi1.wordpress.com/2011/05/06/compile-time-computations/
 *   [5] http://avidinsight.uk/2015/10/how-to-check-that-a-function-is-constexpr/
 *   [6] EMC++ item 15.
 */

constexpr int multiply(int x, int y)
{
  return x * y;
}
 
// The compiler may evaluate this at compile time.
const int val = multiply(10, 10);
