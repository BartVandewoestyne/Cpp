/**
 * References:
 *
 *   [1] http://en.wikipedia.org/wiki/Volatile_variable
 *   [2] http://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766
 *
 * TODO:
 *   find a good example.
 */

// A volatile specifier is a hint to a compiler that an object may change its
// value in ways not specified by the language so that aggressive optimizations
// must be avoided.  For example, a real time clock might be declared:

extern const volatile clock;

// Two successive reads of clock might give different results.
