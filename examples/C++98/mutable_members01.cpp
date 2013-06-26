/**
 * References:
 *
 *   [1] C++ Primer, fifth edition, page 274.
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
