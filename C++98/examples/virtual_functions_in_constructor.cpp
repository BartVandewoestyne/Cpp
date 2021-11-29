/*
 * Example to demonstrate why you should not call virtual functions from a
 * constructor.
 *
 * Note that there are ways around it, see for example the 'Dynamic Binding
 * During Initialization' idiom (AKA 'Calling Virtuals During Initialization'):
 *
 *   https://isocpp.org/wiki/faq/strange-inheritance#calling-virtuals-from-ctor-idiom
 *
 * References:
 *
 *   [cppfaq] When my base class’s constructor calls a virtual function on its
 *            this object, why doesn’t my derived class’s override of that
 *            virtual function get invoked?
 *     https://isocpp.org/wiki/faq/strange-inheritance#calling-virtuals-from-ctors
 *
 *
 *   [karpov20211126] Virtual function calls in constructors and destructors (C++)
 *     https://pvs-studio.com/en/blog/posts/cpp/0891/
 *
 *   [powell20150923] CppCon 2015: Richard Powell 'Intro to the C++ Object Model'
 *     https://youtu.be/iLiDezv_Frk?t=1669
 *
 *   [meyers20050605] Never Call Virtual Functions during Construction or Destruction
 *     https://www.artima.com/cppsource/nevercall.html
 *
 *   [meyers20050522] Effective C++, Third Edition, Item 9: Never call virtual
 *     functions during construction or destruction.
 *     http://www.aristeia.com/EC3E/3E_item9.pdf
 *
 *   [stroustrup] The C++ Programming Language, Third Edition, section 15.4.3
 *
 *   [stroustrup] The Design and Evolution of C++, section 13.2.4.2
 *     http://stroustrup.com/dne.html
 */

#include <string>
#include <iostream>

class Base {

public:

    Base()
    {
        std::cout << "Base()" << std::endl;
        f();
    }

    virtual void f()
    {
        std::cout << "Base::f()" << std::endl;
    }
};


class Derived : public Base {

public:

    Derived()
      : Base()
      {
          std::cout << "Derived()" << std::endl;
      }

    virtual void f()
    {
        std::cout << "Derived::f()" << std::endl;
    }
};


int main()
{
    // Note that the output is the following:
    //   
    //   Base()
    //   Base::f()  => We are calling Base::f() here, not Derived::f(), even if f is virtual!
    //   Derived()
    //
    Derived d;
}
