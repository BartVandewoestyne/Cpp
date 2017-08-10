/*
 * References on whether to synchronize operations on primitive datatypes or not.
 * I have the impression that in theory one should use locking, but in practice things
 * can work without???
 *
 * See also std::atomic<T> as a solution.
 *
 *   [1] https://stackoverflow.com/questions/3618656/should-i-protect-operations-on-primitive-types-with-mutexes-for-being-thread-saf?noredirect=1&lq=1
 *   [2] https://stackoverflow.com/questions/782912/primitive-synchronization-primitives-safe
 *   [2] https://stackoverflow.com/questions/9200951/is-it-ok-to-read-a-shared-boolean-flag-without-locking-it-when-another-thread-ma
 *   [3] https://stackoverflow.com/questions/21319903/testing-the-need-of-synchronization-lock-on-primitive-data-types-with-c?noredirect=1&lq=1
 *
 * TODO: create a piece of code that shows that locking is necessary.
 */
