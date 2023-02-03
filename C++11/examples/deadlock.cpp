/*
 * Key ideas:
 *
 *   - Deadlocks can be solved by:
 *     -> Prefer locking a single mutex: if you don't need two mutexes at the
 *        same time, then only use one mutex at the same time
 *     -> using std::lock to lock more than one mutex.
 *     -> if using std::lock is not possible, try to lock your mutexes in the
 *        same order for all threads.
 *     -> Avoid locking a mutex and then calling some user function, because
 *        then you never know what the user provided function will do.  It might
 *        end up locking another mutex and then you have two mutexes being locked.
 *        Or it might even try to lock the same mutex again.
 *
 * Compile and run:
 *
 *   clang -g -fsanitize=thread deadlock.cpp -lpthread -lstdc++
 *   TSAN_OPTIONS=detect_deadlocks=1:second_deadlock_stack=1 ./a.out
 *  
 * References:
 *
 *   [youtube] C++ Threading #4: Deadlock
 *     https://youtu.be/_N0B5ua7oN8
 *
 *   [youtube20190813] DeadLock With Example In C++
 *     https://youtu.be/VG2Va80XZdo
 */

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
std::mutex m2;

void thread1()
{

    // To solve the deadlock, make sure m1 and m2 are locked in the same order
    // as they are in thread2.

    m1.lock();
#ifdef FORCE_DEADLOCK
    std::this_thread::sleep_for(std::chrono::seconds(1));
#endif
    m2.lock();

    std::cout << "Critical section of thread 1" << std::endl;

    m1.unlock();
    m2.unlock();
}

void thread2()
{
    m2.lock();
#ifdef FORCE_DEADLOCK
    std::this_thread::sleep_for(std::chrono::seconds(1));
#endif
    m1.lock();

    std::cout << "Critical section of thread 2" << std::endl;

    m2.unlock();
    m1.unlock();
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
