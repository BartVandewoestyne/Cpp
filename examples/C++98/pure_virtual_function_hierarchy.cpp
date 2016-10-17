/*
 * Example to illustrate what happens if we have three levels of inheritance,
 * and in the 'middle class' we do not repeate the virtual function declaration.
 *
 *   [1] http://stackoverflow.com/questions/8931612/do-all-virtual-functions-need-to-be-implemented-in-derived-classes
 *       (see footnote in answer from Rob Kennedy).
 */

#include <iostream>

class A {
public:
    virtual void f() = 0;
};

class B : public A {
public:
    //virtual void f() { std::cout << "B::f()" << std::endl; }  // virtual function f() still is virtual if we leave this out.
};

class C : public B {
public:
    virtual void f() { std::cout << "C::f()" << std::endl; }
};

int main()
{
    //A a;  // Error: cannot declare variable 'a' to be of abstract type 'A' (because A::f() is pure).

    std::cout << "non-pointer version:" << std::endl;
    //B b;
    //b.f();
    C c;
    c.f();

    std::cout << "pointer version:" << std::endl;
    //A* pb = new B();
    //pb->f();
    A* pc = new C();
    pc->f();
}
