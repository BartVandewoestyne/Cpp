/**
 * A constexpr function is a named constant expression with parameters.  It’s
 * meant to replace macros and hardcoded literals without sacrificing
 * performance or type safety.
 *
 * References:
 *
 *   [iddn2017reddit] constexpr: why is it needed
 *     https://www.reddit.com/r/cpp/comments/7ddcq9/constexpr_why_is_it_needed/
 *
 *   [allain] Constexpr - Generalized Constant Expressions in C++11
 *     http://www.cprogramming.com/c++11/c++11-compile-time-processing-with-constexpr.html
 *
 *   [bloomfield2015] How to check that a function is constexpr
 *     http://avidinsight.uk/2015/10/how-to-check-that-a-function-is-constexpr/
 *
 *   [meyers2014] Effective Modern C++, Scott Meyers, Item 15.
 *
 *   [krzemienski2014] Compile-time computations
 *     https://akrzemi1.wordpress.com/2011/05/06/compile-time-computations/
 *
 *   [kalev2012] https://blog.smartbear.com/development/using-constexpr-to-improve-security-performance-and-encapsulation-in-c/
 *     http://blog.smartbear.com/software-quality/bid/248591/using-constexpr-to-improve-security-performance-and-encapsulation-in-c
 *
 *   [badie2012] C++11: Simple Compile-time Calculator With Constexpr
 *     http://enki-tech.blogspot.be/2012/09/c11-compile-time-calculator-with.html
 */

constexpr int multiply(int x, int y)
{
  return x * y;
}
 
// The compiler may evaluate this at compile time.
const int val = multiply(10, 10);
