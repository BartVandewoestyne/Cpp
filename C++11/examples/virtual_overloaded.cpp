/*
 * References:
 *
 *   [reddit20190605] Overload of a pure virtual that calls that pure virtual
 *     https://www.reddit.com/r/cpp_questions/comments/bx7ihz/overload_of_a_pure_virtual_that_calls_that_pure/
 *
 *   [stackoverflow20130108] c++ issue with function overloading in an inherited class
 *     https://stackoverflow.com/questions/14212190/c-issue-with-function-overloading-in-an-inherited-class
 */

#include <iostream>

class Base
{
public:
  virtual void f(int x) = 0;
  void f() { f(5); }  // f() overloads the pure virtual f(int) and calls it.
};

class Derived : Base
{
public:
  using Base::f;  // Bring in the f overloads from Base.
  void f(int x) override { std::cout << "Derived::f(int) with argument " << x << std::endl; }
};

int main()
{
    Derived d;
    d.f(42);    // OK!
    d.f();      // error: no matching function for call to 'Derived::f()' => To be solved by bringing in the f overloads from Base via a using-declaration.
}
