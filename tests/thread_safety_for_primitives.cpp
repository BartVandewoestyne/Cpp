/*
 * References on whether to synchronize operations on primitive types or not.
 *
 * => I have the impression that in theory, one should use locking, but in
 *    practice things can work without...
 *
 * See also C++11 std::atomic<T> as a possible clean solution.
 *
 * References:
 *
 *   [carmellose20160205] Are C/C++ fundamental types atomic?
 *     https://stackoverflow.com/questions/35226128/are-c-c-fundamental-types-atomic/35226482
 *     
 *   [c00000fd20140123] Testing the need of synchronization lock on primitive data types with C++
 *     https://stackoverflow.com/questions/21319903/testing-the-need-of-synchronization-lock-on-primitive-data-types-with-c
 *
 *   [preshing20130618] Atomic vs. Non-Atomic Operations
 *     http://preshing.com/20130618/atomic-vs-non-atomic-operations/
 *
 *   [preshing20120515] Memory Reordering Caught in the Act
 *     http://preshing.com/20120515/memory-reordering-caught-in-the-act/
 *     https://github.com/mintomic/mintomic/blob/master/tests/template.test_load_store.cpp
 *     https://github.com/mintomic/mintomic/blob/master/tests/template.test_storeload.cpp
 *
 *   [john20120208] Is it ok to read a shared boolean flag without locking it when another thread may set it (at most once)?
 *     https://stackoverflow.com/questions/9200951/is-it-ok-to-read-a-shared-boolean-flag-without-locking-it-when-another-thread-ma
 *
 *   [alcott20111128] is assignment operator '=' atomic?
 *     https://stackoverflow.com/questions/8290768/is-assignment-operator-atomic
 *
 *   [boost2011] Chapter 8. Boost.Atomic
 *     http://www.boost.org/doc/libs/1_63_0/doc/html/atomic.html#atomic.introduction.introduction_purpose
 *
 *   [doc20100901] Should I protect operations on primitive types with mutexes for being thread-safe in C++?
 *     https://stackoverflow.com/questions/3618656/should-i-protect-operations-on-primitive-types-with-mutexes-for-being-thread-saf
 *
 *   [zild20090423] Primitive synchronization primitives — safe?
 *     https://stackoverflow.com/questions/782912/primitive-synchronization-primitives-safe
 *
 * TODO:
 *   * Finish this piece of code that should show that locking is necessary for primitive
 *     types (In [carmellose20160205], it is written "Note that even a simple write may or may not be undivided:"
 */

#include <atomic>
#include <cstddef>
#include <iostream>
#include <thread>
#include <vector>

namespace {
template <typename Incrementable>
void gobots(Incrementable& value, volatile std::size_t num_incs) {
    // num_incs is volatile to prevent the compiler from optimizing this into
    // value += num_incs.
    for (std::size_t i = 0; i < num_incs; ++i) {
        ++value;
    }
}

template <typename Incrementable>
void run_test(std::size_t const num_threads, std::size_t const num_incs) {
    Incrementable value{0};
    std::vector<std::thread> threads(num_threads);
    for (auto& t : threads) {
        t = std::thread(&gobots<Incrementable>, std::ref(value), num_incs);
    }

    for (auto& t : threads) {
        t.join();
    }
    std::size_t const expected = num_threads * num_incs;
    std::cout << "Value should be " << expected << ". It is: " << value << "\n";
}
}

int main(int argc, char** argv) {

    std::size_t const num_threads = 8;
    std::size_t const num_incs = 10000;

    std::cout << "non atomic: ";
    run_test<std::size_t>(8, num_incs);

    std::cout << "    atomic: ";
    run_test<std::atomic<std::size_t>>(8, num_incs);
}
