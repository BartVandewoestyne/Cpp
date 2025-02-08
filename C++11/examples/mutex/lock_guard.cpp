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
 *   [cppreference] http://en.cppreference.com/w/cpp/thread/lock_guard
 *
 *   [hamilton20241030] std::lock_guard vs. std::scoped_lock: When to Choose Which?
 *     https://www.php.cn/faq/1796656796.html
 *
 *   [brotcrunsher2017] Multithreading in C++ [012] - std::lock_guard
 *     https://youtu.be/wg3td0Dz5hw
 *
 *   [geier2014] Mutex lock guards in C++11
 *     https://geidav.wordpress.com/2014/01/09/mutex-lock-guards-in-c11/
 *
 *   [stackoverflow20131211] std::unique_lock<std::mutex> or std::lock_guard<std::mutex>?
 *     https://stackoverflow.com/questions/20516773/stdunique-lockstdmutex-or-stdlock-guardstdmutex
 *
 *   [milewski2012] C++11 Concurrency, Part 7.
 *     https://youtu.be/4zWbQRE3tWk?t=19m55s
 */   

#include <thread>
#include <mutex>
#include <iostream>
 
int g_i = 0;
std::mutex g_i_mutex;  // protects g_i
 
void safe_increment()
{
    std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
 
    std::cout << std::this_thread::get_id() << ": " << g_i << '\n';
 
    // g_i_mutex is automatically released when lock
    // goes out of scope
}
 
int main()
{
    std::cout << __func__ << ": " << g_i << '\n';
 
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
 
    t1.join();
    t2.join();
 
    std::cout << __func__ << ": " << g_i << '\n';
}
