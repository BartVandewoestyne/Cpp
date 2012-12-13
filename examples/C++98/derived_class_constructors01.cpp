/**
 * This was a test I wrote after someone asked me the following question:
 *
 *   "If you don't specify a call to the Base class constructor in a Derived
 *    constructor, will the Base class constructor then be called?"
 *
 * According to the code below, it seems like the answer is that it will look
 * for a default constructor of the Base class, and if this default constructor
 * is public or protected, it will be called.  If it is private, it won't.
 */

#include <iostream>

class Base {
// public and protected work, but when using private, you get the
// error 'Base::Base() is private within this context.'
public:
  Base()      { std::cout << "Base()"      << std::endl; }
  Base(int x) { std::cout << "Base(int x)" << std::endl; }
};

class Derived : public Base {
public:
  Derived()      { std::cout << "Derived()"      << std::endl; }
  Derived(int x) { std::cout << "Derived(int x)" << std::endl; }
};

int main()
{
  Derived a;
  Derived b(5);
}
