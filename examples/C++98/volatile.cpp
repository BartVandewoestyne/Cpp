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
 *   [regehr2010] Nine ways to break your systems code using volatile
 *     https://blog.regehr.org/archives/28
 *
 *   [preston2010] When to use volatile with multi threading?
 *     https://stackoverflow.com/questions/4557979/when-to-use-volatile-with-multi-threading
 *
 *   [ekstrand2010] Why is volatile not considered useful in multithreaded C or C++ programming?
 *     https://stackoverflow.com/questions/2484980/why-is-volatile-not-considered-useful-in-multithreaded-c-or-c-programming
 *
 *   [DeMarcus2010] Am I or Alexandrescu wrong about singletons?
 *     https://groups.google.com/forum/?hl=en#!topic/comp.lang.c++.moderated/_O9XxTmkLvU%5B1-25%5D
 *
 *   [sutter2009] volatile vs. volatile
 *     http://www.drdobbs.com/parallel/volatile-vs-volatile/212701484
 *
 *   [robison2007] Volatile: Almost Useless for Multi-Threaded Programming
 *     https://software.intel.com/en-us/blogs/2007/11/30/volatile-almost-useless-for-multi-threaded-programming
 *
 *   [hedstrom2006] So what about Andrei Alexandrescu's article about Volatile and LockingPtr?
 *     https://sites.google.com/site/kjellhedstrom2/stay-away-from-volatile-in-threaded-code/so-what-about-andrei-alexandrescus-article-about-volatile-and-lockingptr
 *
 *   [hedstrom2006] Stay away from Volatile in threaded code?
 *     https://sites.google.com/site/kjellhedstrom2/stay-away-from-volatile-in-threaded-code
 *
 *   [meyers2004alexandrescu] C++ and the Perils of Double-Checked Locking
 *     http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
 *
 *   [schwartz2003] Does anyone think 'volatile' is a platform-independent way to make variable access thread safe?
 *     https://groups.google.com/forum/embed/#!topic/comp.programming.threads/H6SoLdqRaxg
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
