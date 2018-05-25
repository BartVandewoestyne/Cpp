/*
 * Example to demonstrate why you should not call virtual functions from a
 * constructor.
 *
 * References:
 *
 *   [cppfaq] When my base class’s constructor calls a virtual function on its
 *            this object, why doesn’t my derived class’s override of that
 *            virtual function get invoked?
 *     https://isocpp.org/wiki/faq/strange-inheritance#calling-virtuals-from-ctors
 *
 *   [stroustrup] The C++ Programming Language, Third Edition, section 15.4.3
 *
 *   [stroustrup] The Design and Evolution of C++, section 13.2.4.2
 *     http://stroustrup.com/dne.html
 */

#include <string>
#include <iostream>

class Base {

public:

    Base()
    {
        std::cout << "Base()" << std::endl;
        f();
    }

    virtual void f()
    {
        std::cout << "Base::f()" << std::endl;
    }
};


class Derived : public Base {

public:

    Derived()
      : Base()
      {
          std::cout << "Derived()" << std::endl;
      }

    virtual void f()
    {
        std::cout << "Derived::f()" << std::endl;
    }
};


int main()
{
    // Note that the output is the following:
    //   
    //   Base()
    //   Base::f()  => We are calling Base::f() here, not Derived::f(), even if f is virtual!
    //   Derived()
    //
    Derived d;
}
