/*
 * Testprogram to see what happens with a pure virtual private function.
 */

#include <iostream>

class Base {
public:
  void foo()
  {
      std::cout << "Base::foo()" << std::endl;
      f();                                                        // pure virtual private function called here
  }
private:
  virtual void f() = 0;                                           // pure virtual private function
};

class Derived : public Base {
private:
  virtual void f() { std::cout << "Derived::f()" << std::endl; }  // derived implementation for pure virtual private function.
};

int main()
{
    Derived d1;
    d1.foo();  // amongst others also calls Derived::f()

    Base* d2 = new Derived();
    d2->foo();
}
