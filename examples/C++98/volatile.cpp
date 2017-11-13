/**
 * References:
 *
 *   [grimm2017] 'Concurrency with Modern C++', Meyers Singleton example around page 161.
 *     https://leanpub.com/concurrencywithmodernc
 *
 *   [meyers2014emc++] Effective Modern C++, Item 40: Use std::atomic for concurrency, volatile for special memory, Scott Meyers.
 *
 *   [murrekatt2011] Is volatile bool for thread control considered wrong?
 *     https://stackoverflow.com/questions/6995310/is-volatile-bool-for-thread-control-considered-wrong
 *
 *   [preston2010] When to use volatile with multi threading?
 *     https://stackoverflow.com/questions/4557979/when-to-use-volatile-with-multi-threading
 *
 *   [ekstrand2010] Why is volatile not considered useful in multithreaded C or C++ programming?
 *     https://stackoverflow.com/questions/2484980/why-is-volatile-not-considered-useful-in-multithreaded-c-or-c-programming
 *
 *   [robison2007] Volatile: Almost Useless for Multi-Threaded Programming
 *     https://software.intel.com/en-us/blogs/2007/11/30/volatile-almost-useless-for-multi-threaded-programming
 *
 *   [alexandrescu2001] volatile: The Multithreaded Programmer's Best Friend
 *     http://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766
 *
 * TODO:
 *   There are nice examples for the volatile keyword in [grimm2017,meyers2014emc++].
 */

// A volatile specifier is a hint to a compiler that an object may change its
// value in ways not specified by the language so that aggressive optimizations
// must be avoided.  For example, a real time clock might be declared:

extern const volatile clock;

// Two successive reads of clock might give different results.
