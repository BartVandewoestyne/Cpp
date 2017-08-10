/*
 * References on whether to synchronize operations on primitive types or not.
 *
 * => I have the impression that in theory, one should use locking, but in
 *    practice things can work without...
 *
 * See also C++11 std::atomic<T> as a possible clean solution.
 *
 * References:
 *   [1] https://stackoverflow.com/questions/3618656/should-i-protect-operations-on-primitive-types-with-mutexes-for-being-thread-saf?noredirect=1&lq=1
 *   [2] https://stackoverflow.com/questions/782912/primitive-synchronization-primitives-safe
 *   [2] https://stackoverflow.com/questions/9200951/is-it-ok-to-read-a-shared-boolean-flag-without-locking-it-when-another-thread-ma
 *   [3] https://stackoverflow.com/questions/21319903/testing-the-need-of-synchronization-lock-on-primitive-data-types-with-c?noredirect=1&lq=1
 *
 * TODO:
 *   * Finish this piece of code that should show that locking is necessary for primitive
 *     types.
 */

#include <iostream>
#include <thread>

int x = 0;
int y = 0;

void writing()
{
    x = 2000;
    y = 11;
}

void reading()
{
    std::cout << "y: " << y << " ";
    std::cout << "x: " << x << std::endl;
}

int main()
{
    std::thread t1(writing);
    std::thread t2(reading);
    t1.join();
    t2.join();
}
