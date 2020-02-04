/* 
 * Illustrates one danger of using shared_ptr in a multithreaded environment.
 *
 * Remarks:
 *   * A separate synchronization mechanism (like std::mutex or so) is still needed
 *     to use std::shared_ptr safely in multiple threads.
 *
 * References:
 *
 *   [stackoverflow20130123] std::shared_ptr thread safety
 *     https://stackoverflow.com/questions/14482830/stdshared-ptr-thread-safety
 */

#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

std::shared_ptr<int> global_instance = std::make_shared<int>(0);
std::mutex global_instance_mutex;

void thread_fcn()
{
    // This is thread-safe and will work fine, though it's useless.  Many
    // short-lived pointers will be created and destroyed.
    for(int i = 0; i < 10000; i++)
    {
        std::shared_ptr<int> temp = global_instance;
    }

    // Without the lock_guard, this code is not thread-safe.  While all
    // the threads are the same, the "final" value of this is almost
    // certainly NOT going to be number_of_threads*10000 = 100,000.
    // It'll be something else.
    for(int i = 0; i < 10000; i++)
    {
        // Comment this in to be safe!
        const std::lock_guard<std::mutex> lock(global_instance_mutex);

        *global_instance = *global_instance + 1;
    }

}

int main(int argc, char** argv)
{
    std::cout << "global instance at begin: " << *global_instance << std::endl;

    std::thread thread1(thread_fcn);
    std::thread thread2(thread_fcn);
    std::thread thread3(thread_fcn);
    std::thread thread4(thread_fcn);
    std::thread thread5(thread_fcn);
    std::thread thread6(thread_fcn);
    std::thread thread7(thread_fcn);
    std::thread thread8(thread_fcn);
    std::thread thread9(thread_fcn);
    std::thread thread10(thread_fcn);

    //std::chrono::milliseconds duration(10000);
    //std::this_thread::sleep_for(duration);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();
    thread9.join();
    thread10.join();

    std::cout << "global instance at end: " << *global_instance << std::endl;

    return 0;
}
