/*
 * Example program illustrating in what order constructors and destructors are
 * being called in an inheritance hierarchy.
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
    ~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
    Derived d;
}
