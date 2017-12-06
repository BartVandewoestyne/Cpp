/*
 * References:
 *
 *   [cppreference] http://en.cppreference.com/w/cpp/thread/lock_guard
 *
 *   [brotcrunsher2017] Multithreading in C++ [012] - std::lock_guard
 *     https://youtu.be/wg3td0Dz5hw
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
