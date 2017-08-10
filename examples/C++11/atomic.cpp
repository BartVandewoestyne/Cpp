/*
 * References:
 *   [1] https://www.quora.com/How-does-std-atomic-work-in-C++11
 *   [2] https://baptiste-wicht.com/posts/2012/07/c11-concurrency-tutorial-part-4-atomic-type.html
 *   [3] http://www.modernescpp.com/index.php/atomics
 *   [4] https://stackoverflow.com/questions/18850752/must-i-call-atomic-load-store-explicitly?noredirect=1&lq=1
 *   [5] https://stackoverflow.com/questions/34915926/is-assignment-equivalent-to-load-store-for-stdatomicbool?noredirect=1&lq=1
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
