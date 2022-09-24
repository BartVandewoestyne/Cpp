/**
 * Example demonstrating a case where the virtual keyword is really necessary
 * in order to get polymorphic behavior.
 *
 *   -> Non-virtual member functions bind statically.  Function resolution
 *      occurs at compile time.
 *
 *   -> Virtual member functions bind dynamically.  Function resolution
 *      occurs when the object is created.
 *
 * References:
 *
 *   [powell20150923] CppCon 2015: Richard Powell “Intro to the C++ Object Model"
 *     https://youtu.be/iLiDezv_Frk?t=929
 *
 *   [stackoverflow20110618] What does the virtual keyword mean when overriding a method?
 *     http://stackoverflow.com/questions/6397356/what-does-virtual-keyword-when-overriding-method
 */

#include <iostream>
using namespace std;

class Base {
  public:
    //virtual  // comment this out to see the difference in behavior!
    void foo() { cout << "Base::foo()" << endl; }
};

// Derived::foo doesn't need to repeat the virtual keyword because Base::foo has
// already used it.  This is guaranteed by the standard, and you can rely on it.
// However, some think it best to keep that in for clarity.
class Derived : public Base {
  public:
    //virtual // this second 'virtual' is optional, but clearer if you write it.
    void foo() { cout << "Derived::foo()" << endl; }
};

int main()
{
  // No problem here, we always call Derived::foo().
  Derived d;
  d.foo();

  // Pay attention!!!  Here, we have the following behavior:
  //
  //   Derived::foo() is called if Base::foo() is virtual
  //     (Derived::foo() then _overrides_ Base::foo() and the object is
  //      polymorphic.)
  //
  //   Base::foo()    is called if Base::foo() is not virtual
  Base& b = d;
  b.foo();
}
