/*
 * Key idea:
 *
 *   - std::unique_lock has more functionality then std::lock_guard.
 *     Probably best to see if you can do things with std::lock_guard, but
 *     if not, then you might need std::unique_lock, which might have a bit
 *     more overhead.
 *
 * References:
 *
 *   [brandy20170929] Curiously Recurring C++ Bugs at Facebook (CppCon 2017)
 *     https://youtu.be/lkgszkPnV8g?si=lq9Tk5kVkAhVtV7n&t=1902
 *
 *   [geier2014] Mutex lock guards in C++11
 *     https://geidav.wordpress.com/2014/01/09/mutex-lock-guards-in-c11/
 *
 *   [stackoverflow20131211] std::unique_lock<std::mutex> or std::lock_guard<std::mutex>?
 *     https://stackoverflow.com/questions/20516773/stdunique-lockstdmutex-or-stdlock-guardstdmutex
 */
