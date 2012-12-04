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
 *   [2] http://www.artima.com/cppsource/nevercall.html
 */

class Base
{
  private:
    int value;

  public:
    Base() { value = getValue(); }
    virtual int f() = 0;
    int getValue();
};


int Base::getValue()
{
  return f();
}


class Derived : public Base
{
  public:
    virtual int f() { return 2; }
};


int main()
{
   Derived d; // crashes with pure virtual method called
}
