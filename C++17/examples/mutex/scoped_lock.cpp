/*
 * Key ideas:
 *
 *   - std::scoped_lock allows us to lock one or multiple mutexes and
 *     guarantees that deadlock is avoided.  The mutexes may have
 *     different type.
 *
 *   - Due to class template argument deduction, you do not have to specify
 *     the types of the mutexes when declaring your scoped_lock.
 *
 *   - A scoped_lock with a a single constructor argument acts like a,
 *     lock_guard.  Therefore, you *can* replace all uses of lock_guard with
 *     scoped_lock, but you shouldn't always (see [holly20210818,
 *     stackoverflow20170325, hamilton20241030]).
 *
 * References:
 *
 *   [hamilton20241030] std::lock_guard vs. std::scoped_lock: When to Choose Which?
 *     https://www.php.cn/faq/1796656796.html
 *
 *   [holly20210818] Why I Still Use std::lock_guard
 *     https://www.approxion.com/why-i-still-use-stdlock_guard/
 *
 *   [josuttis20200926] C++17 - The Complete Guide - 27.1.1 std::scoped_lock
 *
 *   [stackoverflow20170325] std::lock_guard or std::scoped_lock?
 *     https://stackoverflow.com/questions/43019598/stdlock-guard-or-stdscoped-lock
 *
 *   [sonarsource] "std::scoped_lock" should be used instead of "std::lock_guard"
 *     https://rules.sonarsource.com/cpp/RSPEC-5997
 */

#include <mutex>
#include <string>
#include <vector>

// ...

std::vector<std::string> allIssues;
std::mutex allIssuesMx;
std::vector<std::string> openIssues;
std::timed_mutex openIssuesMx;

// C++17 version:

// lock both issue lists:
{
    std::scoped_lock lg(allIssuesMx, openIssuesMx);
    // manipulate both allIssues and openIssues
}

// OLD C++11 version:

// lock both issue lists:
{
    std::lock(allIssuesMx, openIssuesMx);  // lock with deadlock avoidance
    std::lock_guard<std::mutex> lg1(allIssuesMx, std::adopt_lock);
    std::lock_guard<std::mutex> lg2(openIssuesMx, std::adopt_lock);
    // manipulate both allIssues and openIssues
}
