/*
 * Example to illustrate what hiding is in C++.
 *
 * References:
 *   [1] http://stackoverflow.com/questions/11269501/can-i-use-a-method-overriding-a-non-virtual-method
 */

#include <iostream>

class Base {
public:
    //virtual  // need this to avoid hiding
    void f() { std::cout << "Base::f()" << std::endl; }
};

class Derived : public Base {
public:
    void f() { std::cout << "Derived::f()" << std::endl; }
};

int main()
{
    Derived d;
    d.f();       // OK!

    Base* b = new Derived();
    b->f();      // if Base::f() is not virtual, then Base::f() is called here.
                 // if Base::f() is virtual, then Derived::f() is called here.
                 // Thus, if Base::f() is not virtual, it hides Derived::f().
}
