/**
 * Scenario's for when mutable is acceptable:
 *
 *   1. Cached data.
 *   2. Mutexes.
 *
 * References:
 *
 *   [mertz20171018] Mutable
 *     https://arne-mertz.de/2017/10/mutable/
 *
 *   [gregory20170927] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=14m38s
 *
 *   [pravasi20140705] C++ mutable keyword
 *     http://www.geeksforgeeks.org/c-mutable-keyword/
 *
 *   [lipmann20120816] C++ Primer, fifth edition, page 274.
 *     http://www.informit.com/store/c-plus-plus-primer-9780321714114
 *
 *   [save20120418] Motivation for mutable in C++ [duplicate]
 *     https://stackoverflow.com/questions/10212350/motivation-for-mutable-in-c
 *
 *   [user34537_20101229] When have you used C++ 'mutable' keyword?
 *     https://stackoverflow.com/questions/4554031/when-have-you-used-c-mutable-keyword
 */

#include <cstdlib>

class Screen {

public:
    void some_member() const;

private:
    mutable size_t access_ctr;  // may change even in a const object

    // other members as before

};

void Screen::some_member() const
{
    ++access_ctr;  // keep a count of the calls to any member function

    // whatever other work this member needs to do
}
