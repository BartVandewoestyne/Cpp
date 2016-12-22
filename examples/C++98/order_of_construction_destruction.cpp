/*
 * References:
 *   [1] http://stackoverflow.com/questions/654428/what-is-the-order-in-which-the-destructors-and-the-constructors-are-called-in-c
 *   [2] http://stackoverflow.com/questions/28356069/what-order-are-destructors-called-and-member-variables-destroyed-in-c-using-in
 */

#include <iostream>

class Base {
public:
    Base() { std::cout << "Base()" << std::endl; }
    virtual ~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived()" << std::endl; }
    virtual ~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
    Derived d;

    return 0;
}
