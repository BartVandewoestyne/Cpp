/*
 * TODO: check if calling a (pure) virtual function in the derived-class constructor
 *       is well-defined.
 */

#include <string>
#include <iostream>

class Base {

public:

    Base()
    {
        std::cout << "Base()" << std::endl;
    }

    virtual void f()
    {
        std::cout << "Base::f()" << std::endl;
    }

    virtual void g() = 0;
};


class Derived : public Base {

public:

    Derived()
      : Base()
      {
          std::cout << "Derived()" << std::endl;
	  f();  // TODO: is calling a virtual function in the derived-class constructor well-defined?
	  g();  // TODO: is calling a pure virtual function in the derived-class constructor well-defined?
      }

    virtual void f()
    {
        std::cout << "Derived::f()" << std::endl;
    }

    virtual void g()
    {
        std::cout << "Derived::g()" << std::endl;
    }
};


int main()
{
    // Note that the output is the following:
    //   
    //   Base()
    //   Derived()
    //   Derived::f()  => TODO: is this guaranteed by the standard?
    //   Derived::g()  => TODO: is this guaranteed by the standard?
    //
    Derived d;
}
