/*
 * TODO: check if calling a (pure) virtual function in the derived-class
 *       constructor is well-defined.
 */

#include <string>
#include <iostream>

class Base {

public:

    Base() { std::cout << "Base()" << std::endl; }

    virtual void vf() { std::cout << "Base::vf()" << std::endl; }

    virtual void pvf() = 0;
};


class Derived : public Base {

public:

    Derived()
      : Base()
    {
        std::cout << "Derived()" << std::endl;

	vf();  // TODO: is calling a virtual function in the derived-class
               //       constructor well-defined?

	pvf();  // TODO: is calling a pure virtual function in the
                //       derived-class constructor well-defined?
    }

    virtual void vf() { std::cout << "Derived::vf()" << std::endl; }

    virtual void pvf() { std::cout << "Derived::pvf()" << std::endl; }
};


int main()
{
    // Note that with g++ 6.4.0 the output is the following:
    //   
    //   Base()
    //   Derived()
    //   Derived::vf()   => TODO: is this guaranteed by the standard?
    //   Derived::pvf()  => TODO: is this guaranteed by the standard?
    //
    Derived d;
}
