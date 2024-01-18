/**
 * Example on virtual destructors.
 *
 * Key ideas:
 *
 *   - Declare destructors virtual in polymorphic base classes.
 *   - Gratuitiously declaring all destructors virtual is just as wrong as never declaring them virtual.
 *
 * References:
 *  
 *   [livinginjapan20200505] Effective C++ Series Item 7
 *     https://livinginjapan.github.io/2020-04-29/Effective-C++-Series-Item-6
 *
 *   [stackoverflow20090120] When to use virtual destructors?
 *     http://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
 *
 *   [stackoverflow20110913] Derived class with non-virtual destructor
 *     http://stackoverflow.com/questions/7403883/derived-class-with-non-virtual-destructor
 */

#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base()" << std::endl; }
    virtual ~Base(){ std::cout <<"~Base()" << std::endl; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived()" << std::endl; }
    ~Derived(){ std::cout << "~Derived()" << std::endl; }  // destructor is virtual, because it is virtual in base!  No need to add virtual keyword here!

};

class Derived2 : public Derived
{
public:
    Derived2() { std::cout << "Derived2()" << std::endl; }
    ~Derived2(){ std::cout << "~Derived2()" << std::endl; }  // destructor is virtual, because it is virtual in base!  No need to add virtual keyword here!

};

int main()
{
    std::cout << "\nBase* b = new Base;  delete b;" << std::endl;

    Base* b = new Base;
    delete b;

    std::cout << "\nDerived* d = new Derived;  delete d;" << std::endl;

    Derived* d = new Derived;
    delete d;
    
    std::cout << "\nDerived2* d2 = new Derived2;  delete d2;" << std::endl;

    Derived2* d2 = new Derived2;
    delete d2;
    
    std::cout << "\nBase* b1 = new Derived;  delete b1;" << std::endl;

    // This only works correctly if Base's destructor is virtual.
    Base* b1 = new Derived;
    delete b1;

    std::cout << "\nBase* b2 = new Derived2;  delete b2;" << std::endl;

    Base* b2 = new Derived2;
    delete b2;

    {
        std::cout << "\n{ Base b; } " << std::endl;
        Base b;
    }

    {
        std::cout << "\n{ Derived d; } " << std::endl;
        Derived d;
    }
}
