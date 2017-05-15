/*
 * Example to illustrate how a static variable in the base class can be
 * modified from any subclass.
 */

#include <iostream>

class Base {
public:
    static int x;
};

int Base::x = 0;

class Derived1 : public Base {
public:
    void increment() { x++; }
};

class Derived2 : public Base {
public:
    void increment() { x++; }
};

int main()
{
    Derived1 d1;
    Derived2 d2;

    d1.increment();
    d2.increment();

    std::cout << "d1.x = " << d1.x << std::endl;
    std::cout << "d2.x = " << d2.x << std::endl;
}
