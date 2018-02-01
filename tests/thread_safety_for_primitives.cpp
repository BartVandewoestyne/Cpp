/*
 * Illustrate that synchronize operations on primitive types are necessary
 * (or not?).
 *
 * => From reading the below posts on StackOverflow, I have the impression that
 *    in order to avoid undefined behavior, one should use locking.  However,
 *    it seems that in practice things can work without locking???
 *
 * See also C++11's std::atomic<T> as a possible clean solution.
 *
 * References:
 *   [1] https://stackoverflow.com/questions/3618656/should-i-protect-operations-on-primitive-types-with-mutexes-for-being-thread-saf?noredirect=1&lq=1
 *   [2] https://stackoverflow.com/questions/782912/primitive-synchronization-primitives-safe
 *   [2] https://stackoverflow.com/questions/9200951/is-it-ok-to-read-a-shared-boolean-flag-without-locking-it-when-another-thread-ma
 *   [3] https://stackoverflow.com/questions/21319903/testing-the-need-of-synchronization-lock-on-primitive-data-types-with-c?noredirect=1&lq=1
 *
 * TODO:
 *   * Find a piece of code that illustrates that locking is necessary for
 *     primitive types.
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
    std::thread thread1(writing);
    std::thread thread2(reading);
    thread1.join();
    thread2.join();
}
