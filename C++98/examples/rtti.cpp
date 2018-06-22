/*
 * RTTI is provided through two operators:
 *
 *   - The typeid operator.
 *   - The dynamic_cast operator.
 *
 * Most modern compilers enable RTTI by default.  To disable it, use the
 * following flags:
 *
 *   g++: -fno-rtti
 *   clang: ???
 *   Visual Studio: /GR[-]
 *
 * If you disable RTTI, you should see that typeid and dynamic_cast are no
 * longer available.  g++ for example gives the compile-time errors:
 *
 *   error: cannot use typeid with -fno-rtti
 *   error: ‘dynamic_cast’ not permitted with -fno-rtti
 *
 * References:
 *
 *   [1] https://gcc.gnu.org/onlinedocs/gcc-5.2.0/gcc/C_002b_002b-Dialect-Options.html
 *   [2] https://msdn.microsoft.com/en-us/library/we6hfdy0.aspx
 *   [3] http://www.bogotobogo.com/cplusplus/dynamic_cast.php
 */

#include <iostream>
#include <typeinfo>

class Base {
public:
  virtual void vf()
  {
    std::cout << "Base::vf()" << std::endl;
  }
};

class Derived : public Base {
public:
  void vf()
  {
    std::cout << "Derived::vf()" << std::endl;
  }
};

int main()
{

 /** Test typeid() **/

 std::cout << typeid(int).name() << std::endl;


 /** Test dynamic_cast() via a quite useless example... **/

 Base b;
 Derived d;

 // Cast a derived class to its base class (should be ok).
 Base* pb = dynamic_cast<Base*>(&d);
 pb->vf();

 // This cast should work.
 Derived* pd1 = dynamic_cast<Derived*>(pb);
 pd1->vf();

 // This cast will fail at runtime and produce a null pointer.
 Derived* pd2 = dynamic_cast<Derived*>(&b);
 if (pd2)
 {
   pd2->vf();
 }
 else
 {
    std::cout << "pd2 was null" << std::endl;
 }

 return 0;
}
