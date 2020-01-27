/**
 * A constexpr function is a named constant expression with parameters.  It is
 * meant to replace macros and hardcoded literals without sacrificing
 * performance or type safety.
 *
 * References:
 *
 *   [grimm20190204] C++ Core Guidelines: Programmierung zur Compilezeit mit constexpr
 *     https://www.heise.de/developer/artikel/C-Core-Guidelines-Programmierung-zur-Compilezeit-mit-constexpr-4296535.html
 *
 *   [popa20180626] Convert Macros to Constexpr
 *     https://devblogs.microsoft.com/cppblog/convert-macros-to-constexpr/
 *
 *   [iddn2017reddit] constexpr: why is it needed
 *     https://www.reddit.com/r/cpp/comments/7ddcq9/constexpr_why_is_it_needed/
 *
 *   [deane2017turner] constexpr ALL the Things! [CppCon 2017]
 *     https://youtu.be/PJwd4JLYJJY
 *
 *   [meyers20141107] Effective Modern C++, Item 15: Use constexpr whenever possible.
 *
 *   [kalev20121219] Using constexpr to Improve Security, Performance and Encapsulation in C++
 *     https://smartbear.com/blog/develop/using-constexpr-to-improve-security-performance-an/
 *
 *   [badie20120910] C++11: Simple Compile-time Calculator With Constexpr
 *     http://enki-tech.blogspot.be/2012/09/c11-compile-time-calculator-with.html
 *
 *   [krzemienski20110506] Compile-time computations
 *     https://akrzemi1.wordpress.com/2011/05/06/compile-time-computations/
 *
 *   [bloomfield20151018] How to check that a function is constexpr
 *     http://avidinsight.uk/2015/10/how-to-check-that-a-function-is-constexpr/
 *
 *   [allain] Constexpr - Generalized Constant Expressions in C++11
 *     http://www.cprogramming.com/c++11/c++11-compile-time-processing-with-constexpr.html
 */

constexpr int multiply(int x, int y)
{
  return x * y;
}
 
// The compiler may evaluate this at compile time.
const int val = multiply(10, 10);
