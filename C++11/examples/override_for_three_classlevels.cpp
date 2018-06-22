/*
 * Test program to see what happens if intermediate B does not override f().
 */

#include <iostream>

class A
{
public:
    virtual void f() { std::cout << "A::f()" << std::endl; }
};

class B : public A
{
public:
//    virtual void f() override { std::cout << "B::f()" << std::endl; }  // commenting this out will use A::f()
};

class C : public B
{
public:
    virtual void f() override { std::cout << "C::f()" << std::endl; }  // This works, even if B does not override f().
};

int main()
{
    A a;
    B b;
    C c;

    a.f();
    b.f();
    c.f();
}
