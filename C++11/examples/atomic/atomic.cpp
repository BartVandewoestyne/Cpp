/*
 * References:
 *
 *   [saif20200825] std::atomic and Memory orders in C++
 *     https://youtu.be/IE6EpkT7cJ4
 *
 *   [pikus20170925] C++ atomics, from basic to advanced - what do they do and what do they really do?
 *     https://youtu.be/ZQFzMfHIxng
 *     https://sched.co/BgtC
 *
 *   [doumler2017] The new C++17 and why it's good for you - Timur Doumler
 *     https://youtu.be/ky_eXBMcJK0?t=18m44s
 *
 *   [grimm2016atomic] Atomics
 *     http://www.modernescpp.com/index.php/atomics
 *
 *   [bgr2016] Is assignment equivalent to load/store for std::atomic<bool>
 *     https://stackoverflow.com/questions/34915926/is-assignment-equivalent-to-load-store-for-stdatomicbool?noredirect=1&lq=1
 *     
 *   [meyers2014emc++] Effective Modern C++, Item 40: Use std::atomic for concurrency, volatile for special memory, Scott Meyers.
 *
 *   [quora2014] How does std::atomic work in C++11?
 *     https://www.quora.com/How-does-std-atomic-work-in-C++11
 *
 *   [bavaza2013] Must I call atomic load/store explicitly?
 *     https://stackoverflow.com/questions/18850752/must-i-call-atomic-load-store-explicitly?noredirect=1&lq=1
 *
 *   [wicht2012] C++11 Concurrency Tutorial - Part 4: Atomic Types
 *     https://baptiste-wicht.com/posts/2012/07/c11-concurrency-tutorial-part-4-atomic-type.html
 *
 *   [sutter2012weapons1] C++ and Beyond 2012: Herb Sutter - atomic<> Weapons, 1 of 2
 *     https://channel9.msdn.com/Shows/Going+Deep/Cpp-and-Beyond-2012-Herb-Sutter-atomic-Weapons-1-of-2
 *
 *   [sutter2012weapons2] C++ and Beyond 2012: Herb Sutter - atomic<> Weapons, 2 of 2
 *     https://channel9.msdn.com/Shows/Going+Deep/Cpp-and-Beyond-2012-Herb-Sutter-atomic-Weapons-2-of-2
 */

#include <thread>
#include <atomic>
#include <iostream>
#include <vector>

struct AtomicCounter {
    std::atomic<int> value;

    AtomicCounter() : value(0) {}

    void increment() {
        ++value;
    }

    void decrement() {
        --value;
    }

    int get() {
        return value.load();
    }
};

int main() {
    AtomicCounter counter;

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread([&counter]() {
            for (int i = 0; i < 500; ++i) {
                counter.increment();
            }
        }));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << counter.get() << std::endl;

    return 0;
}
