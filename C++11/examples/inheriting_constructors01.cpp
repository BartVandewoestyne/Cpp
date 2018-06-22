/**
 * TODO: this example is not working yet!!!  Do we need at least g++ 4.8 ???
 */

#include <iostream>

class Base {
public:
    Base() { std::cout << "B1()" << std::endl; }
    Base(int i) { std::cout << "B1(int)" << std::endl; }
};

class Derived : public Base {
    using Base::Base;
};

int main()
{
    Base b1;
    Base b2(123);
    Derived d1;
    Derived d2(123);
}
