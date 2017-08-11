/**
 * References:
 *
 *   [1] http://en.wikipedia.org/wiki/Volatile_variable
 *   [2] http://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766
 *   [3] 'Concurrency with Modern C++', Meyers Singleton example around page 161
 *   [4] https://msdn.microsoft.com/en-us/library/12a04hfd.aspx
 *   [5] https://stackoverflow.com/questions/2484980/why-is-volatile-not-considered-useful-in-multithreaded-c-or-c-programming
 *   [6] https://software.intel.com/en-us/blogs/2007/11/30/volatile-almost-useless-for-multi-threaded-programming
 *
 * TODO:
 *   There is a nice example for the volatile keyword in [3].
 */

// A volatile specifier is a hint to a compiler that an object may change its
// value in ways not specified by the language so that aggressive optimizations
// must be avoided.  For example, a real time clock might be declared:

extern const volatile clock;

// Two successive reads of clock might give different results.
