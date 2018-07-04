/**
 * References:
 *
 *   [1] http://j.mp/cpp11ref
 */

class A
{
    A& operator=(A) = delete; // disallow copying
    A(const A&) = delete;
};

struct B
{
    B(float); // can initialize with a float
    B(long) = delete; // but not with long
};

struct C
{
    virtual ~C() = default;
};
