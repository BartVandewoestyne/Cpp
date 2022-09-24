/*
 * References:
 *   
 *   [bastien20190920] Deprecating volatile (CppCon 2019)
 *     https://youtu.be/KJW_DLaVXIY
 *
 *   [karls20190602] Should volatile really never be used for multi-threading?
 *     https://www.reddit.com/r/cpp/comments/bw2au4/should_volatile_really_never_be_used_for/
 *
 *   [brandy20170929] Curiously Recurring C++ Bugs at Facebook (CppCon 2017)
 *     https://youtu.be/3MB2iiCkGxg?t=1021
 *     
 *   [???]  ???
 *     http://cxx.isvolatileusefulwiththreads.com/
 *
 *   [grimm2017] 'Concurrency with Modern C++', Meyers Singleton example around page 161.
 *     https://leanpub.com/concurrencywithmodernc
 *
 *   [meyers2014emc++] Effective Modern C++, Item 40: Use std::atomic for concurrency, volatile for special memory, Scott Meyers.
 *
 *   [sutter20130211] atomic Weapons: The C++ Memory Model and Modern Hardware
 *     https://herbsutter.com/2013/02/11/atomic-weapons-the-c-memory-model-and-modern-hardware/
 *
 *   [murrekatt2011] Is volatile bool for thread control considered wrong?
 *     https://stackoverflow.com/questions/6995310/is-volatile-bool-for-thread-control-considered-wrong
 *
 *   [ekstrand20100320] Why is volatile not considered useful in multithreaded C or C++ programming?
 *     https://stackoverflow.com/questions/2484980/why-is-volatile-not-considered-useful-in-multithreaded-c-or-c-programming
 *
 *   [regehr2010] Nine ways to break your systems code using volatile
 *     https://blog.regehr.org/archives/28
 *
 *   [preston2010] When to use volatile with multi threading?
 *     https://stackoverflow.com/questions/4557979/when-to-use-volatile-with-multi-threading
 *
 *   [DeMarcus2010] Am I or Alexandrescu wrong about singletons?
 *     https://groups.google.com/forum/?hl=en#!topic/comp.lang.c++.moderated/_O9XxTmkLvU%5B1-25%5D
 *
 *   [sutter20090108] volatile vs. volatile
 *     http://www.drdobbs.com/parallel/volatile-vs-volatile/212701484
 *
 *   [taylor20080305] volatile
 *     https://www.airs.com/blog/archives/154
 *
 *   [robison20071130] Volatile: Almost Useless for Multi-Threaded Programming
 *     https://software.intel.com/en-us/blogs/2007/11/30/volatile-almost-useless-for-multi-threaded-programming
 *
 *   [hedstrom2006] So what about Andrei Alexandrescu's article about Volatile and LockingPtr?
 *     https://sites.google.com/site/kjellhedstrom2/stay-away-from-volatile-in-threaded-code/so-what-about-andrei-alexandrescus-article-about-volatile-and-lockingptr
 *
 *   [hedstrom2006] Stay away from Volatile in threaded code?
 *     https://sites.google.com/site/kjellhedstrom2/stay-away-from-volatile-in-threaded-code
 *
 *   [meyers200409alexandrescu] C++ and the Perils of Double-Checked Locking
 *     http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
 *
 *   [schwartz2003] Does anyone think 'volatile' is a platform-independent way to make variable access thread safe?
 *     https://groups.google.com/forum/embed/#!topic/comp.programming.threads/H6SoLdqRaxg
 *
 *   [alexandrescu2001] volatile: The Multithreaded Programmer's Best Friend
 *     http://www.drdobbs.com/cpp/volatile-the-multithreaded-programmers-b/184403766
 */
