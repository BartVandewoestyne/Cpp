/**
 * Example demonstrating why one should not call virtual functions from
 * constructors or destructors.
 *
 * This example even fails to compile.
 */
class Base
{
  public:
    Base() { f(); } // Results in compile error.
    //Base() {}     // OK!
    virtual void f() = 0;
};


class Derived : public Base
{
  public:
    virtual void f() {}
};


int main()
{
   Derived d; // crashes with pure virtual method called
}
