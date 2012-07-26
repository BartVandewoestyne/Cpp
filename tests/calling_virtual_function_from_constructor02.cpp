/**
 * Example demonstrating why one should not call virtual functions from
 * constructors or destructors.
 *
 * This example compiles, but gives the following error at run time:
 *
 *   pure virtual method called
 *   terminate called without an active exception
 *   Aborted
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/738204/why-might-my-virtual-function-call-be-failing
 */

class Base
{
  public:
    Base() { g(); }
    virtual void f() = 0;
    void g();
};


void Base::g()
{
  f();
}


class Derived : public Base
{
  public:
    virtual void f() {}
};


int main()
{
   Derived d; // crashes with pure virtual method called
}
