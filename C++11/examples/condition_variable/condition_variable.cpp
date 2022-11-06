/*
 * Key ideas:
 *
 *   - Condition variables allow us to synchronize threads via notifications.
 *     So, you can implement workflows like sender/receiver or producer/consumer.
 *     In such a workflow, the receiver is waiting for the sender's notification.
 *     If the receiver gets the notification, it continues its work.
 *
 *   - In fact, it can happen that the receiver finished its task before the
 *     sender has sent its notification. How is that possible? The receiver is
 *     susceptible to spurious wakeups. So the receiver wakes up, although no
 *     notification happens. To protect it from this, one has to add a predicate
 *     to the wait method.
 *
 * References:
 *
 *   [cppcoreguidelines] C++ Core Guidelines - CP.42: Don’t wait without a condition
 *     https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconc-wait
 *
 *   [grimm20180604] C++ Core Guidelines: Be Aware of the Traps of Condition Variables
 *     https://www.modernescpp.com/index.php/c-core-guidelines-be-aware-of-the-traps-of-condition-variables
 *
 *   [grimm20160523] Condition Variables
 *     https://www.modernescpp.com/index.php/condition-variables
 */

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady;

void doTheWork()
{
    std::cout << "Processing shared data." << std::endl;
}

void waitingForWork()
{
    std::cout << "Worker: Waiting for work." << std::endl;

    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck, []{return dataReady;});  // prevent spurious wakeup!!!
    doTheWork();
    std::cout << "Work done." << std::endl;
}

void setDataReady()
{
    std::lock_guard<std::mutex> lck(mutex_);
    dataReady = true;
    std::cout << "Sender: Data is ready." << std::endl;
    condVar.notify_one();
}

int main()
{
    std::thread t1(waitingForWork);
    std::thread t2(setDataReady);

    t1.join();
    t2.join();
}
