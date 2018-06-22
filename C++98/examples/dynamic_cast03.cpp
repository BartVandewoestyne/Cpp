/*
 * Example illustrating the usefulness of dynamic_cast, base on the example in [1].
 *
 * References:
 *
 *   [1] https://www.securecoding.cert.org/confluence/display/cplusplus/EXP05-CPP.+Do+not+use+C-style+casts
 */

#include <iostream>

class Base {
public:

    // If you forget the virtual destructor, things can go wrong (see the delete statements
    // at the end of this example).  Only dynamic_cast reports at compile time:
    //
    //   error: cannot dynamic_cast ‘apbt[1]’ (of type ‘class Base*’) to type ‘class Derived*’ (source type is not polymorphic)
    //
    // but an old-style C-cast or a static_cast doesn't report this.
    //
    //virtual ~Base() { std::cout << "~Base()" << std::endl; }
    
};

class Derived1: public Base 
{
    virtual ~Derived1() { std::cout << "~Derived1()" << std::endl; }
};

class Derived2: public Base 
{
    virtual ~Derived2() { std::cout << "~Derived2()" << std::endl; }
};

void doit(Derived1* pd)
{
    if (pd)
    {
      std::cout << "doit(Derived1*)" << std::endl;
    }
    else
    {
      std::cout << "doit(NULL) called!" << std::endl;
    }
}

int main()
{
    Base* apbt[3];

    std::cout << "\nSituation 1: allocate a Derived1 and cast to a Derived1:" << std::endl;

    // All three casts *seem* to work, but only dynamic_cast reports it
    // if you forgot to declare your virtual destructor in the base class.

    apbt[0] = new Derived1;                  // this doesn't make much sense without virtual functions
    doit((Derived1*)apbt[0]);                // bad!
    doit(static_cast<Derived1*>(apbt[0]));   // bad!
    doit(dynamic_cast<Derived1*>(apbt[0]));  // ok!


    std::cout << "\nSituation 2: allocate a Derived2 and cast to a Derived1:" << std::endl;

    // Only dynamic_cast can detect the incorrect cast at runtime here.
    
    apbt[1] = new Derived2;                  // this doesn't make much sense without virtual functions
    doit((Derived1*)apbt[1]);                // bad: cast should fail!
    doit(static_cast<Derived1*>(apbt[1]));   // bad: cast should fail!
    doit(dynamic_cast<Derived1*>(apbt[1]));  // ok! bad cast reported as null pointer


    std::cout << "\nCheck: did we cleanup correctly?" << std::endl;

    // Note that if you forget the virtual ~Base() destructor, then no destructors get called!
    // Apparently, only dynamic_cast reports it if you forgot it.
    delete apbt[0];
    delete apbt[1];
}
