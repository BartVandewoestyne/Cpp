/**
 * References:
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=14m38s
 *
 *   [1] C++ Primer, fifth edition, page 274.
 *
 *   [save2012] Motivation for mutable in C++ [duplicate]
 *              https://stackoverflow.com/questions/10212350/motivation-for-mutable-in-c
 *
 *   [acidzombie242010] When have you used C++ 'mutable' keyword?
 *                      https://stackoverflow.com/questions/4554031/when-have-you-used-c-mutable-keyword
 *
 *   [pravasi] C++ mutable keyword
 *             http://www.geeksforgeeks.org/c-mutable-keyword/
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
