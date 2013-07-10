#include <iostream>

class Base {
public:
    virtual void f1() { std::cout << "Base::f1()" << std::endl; }
    virtual void f2(int) { std::cout << "Base::f2(int)" << std::endl; }
};

class Derived : public Base {
public:
    //void f1() { std::cout << "Derived::f1()" << std::endl; }
    //void f2(int) { std::cout << "Derived::f2(int)" << std::endl; }
    void f3(int, int) { std::cout << "Derived::f3(int, int)" << std::endl; }
};

int main()
{
    Base* bp = new Base();
    Derived* dp = new Derived();

    bp->f1();
    bp->f2(2);
    dp->f1();
    dp->f2(2);
    dp->f3(3,3);
}
