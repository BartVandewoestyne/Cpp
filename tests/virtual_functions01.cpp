/**
 * This is a test I did after I was cleaning up some code at work.
 */
#include <iostream>

class Top {
public:
    virtual void f1() = 0;
};

class Middle : public Top {
public:
    virtual void f1() = 0;  // QUESTION: is this line necessary???
    virtual void f2() = 0;
};

class Bottom : public Middle {
public:
    virtual void f1() { std::cout << "Bottom::f1()" << std::endl; };
    virtual void f2() { std::cout << "Bottom::f2()" << std::endl; };
};

int main()
{
    Bottom b;
    b.f1();
    b.f2();
}
