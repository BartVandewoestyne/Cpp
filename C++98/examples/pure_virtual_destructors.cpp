/*
 * Key idea:
 *
 *   - Suppose you have a base class that you want to make abstract.  In this
 *     base class, all methods have meaningful default implementations, and you
 *     want the derived classes to inherit them as-is.  However, to make a
 *     class abstract, at least one of its methods must be made pure virtual,
 *     which means the derived classes must override it.  Then you can make the
 *     class abstract by declaring the destructor to be pure virtual.  This
 *     will make your class abstract without forcing you to declare any other
 *     method pure virtual.
 *
 *   - Note that you *must* define a pure virtual destructor.  This is because
 *     the destructor of a base class is always called when a derived object
 *     is destroyed.  Failing to define it will cause a link error.
 *
 * References:
 *
 *   [cppreference] Destructors - Pure virtual destructors
 *     https://en.cppreference.com/w/cpp/language/destructor
 *
 *   [pravasi20190809] Pure virtual destructor in C++
 *     https://www.geeksforgeeks.org/pure-virtual-destructor-c/
 *
 *   [stackoverflow20140114] Why a pure virtual destructor needs an implementation
 *     https://stackoverflow.com/questions/21109417/why-a-pure-virtual-destructor-needs-an-implementation
 *
 *   [bendersky20101113] Pure virtual destructors in C++
 *     https://eli.thegreenplace.net/2010/11/13/pure-virtual-destructors-in-c
 */

#include <iostream>

// Abstract base class - can't be instantiated
//
class Base
{
public:
    virtual ~Base() = 0;
    virtual void method();
};

Base::~Base()
{
  // Compulsory virtual destructor definition,
  // even if it's empty
  std::cout << "Base::~Base()" << std::endl;
}

void Base::method()
{
  // Default implementation.
  // Derived classes can just inherit it, if needed
  std::cout << "Base::method()" << std::endl;
}

// We can now derive from Base, inheriting the
// implementation of method()
//
class Derived : public Base
{
public:
    ~Derived() { std::cout << "Derived::~Derived()" << std::endl; }
};

int main()
{
    Derived d;
}
