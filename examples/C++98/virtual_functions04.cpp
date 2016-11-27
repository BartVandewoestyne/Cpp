/**
 * Self-written test-program to see what happens if we remove the virtual
 * keyword from the base class in a three-classes inheritance hierarchy.
 */

#include <iostream>

class A {
public:
    // Remove virtual keyword here to see what happens.
    virtual void foo() { std::cout << "A::foo()" << std::endl; }
};

class B : public A {
public:
    virtual void foo() { std::cout << "B::foo()" << std::endl; }
};

class C : public B {
public:
    virtual void foo() { std::cout << "C::foo()" << std::endl; }
};

int main()
{
    A a;
    B b;
    C c;
    a.foo();
    b.foo();
    c.foo();

    A* ap1 = new A();
    B* bp1 = new B();
    C* cp1 = new C();
    ap1->foo();
    bp1->foo();
    cp1->foo();

    A* ap2 = new A();
    A* bp2 = new B();
    A* cp2 = new C();
    ap2->foo();        // calls A::foo() if you forget the virtual keyword on A::foo()
    bp2->foo();        // calls A::foo() if you forget the virtual keyword on A::foo()
    cp2->foo();        // calls A::foo() if you forget the virtual keyword on A::foo()

    A* ap3 = new A();
    B* bp3 = new B();
    B* cp3 = new C();  // Mind the B* here!  This is to check whether B::foo() and C::foo() are still virtual.
    ap3->foo();
    bp3->foo();        // calls B::foo()
    cp3->foo();        // calls C::foo() (virtual mechanism still works for B and C) 
}
