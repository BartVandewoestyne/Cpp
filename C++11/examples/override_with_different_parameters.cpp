#include <iostream>

class Base
{
public:
  virtual void f() { std::cout << "Base::f()" << std::endl; }
};

class Derived : public Base
{
public:
  void g() { f(); }
  void f() override { std::cout << "Derived::f()" << std::endl; }
  void f(int) { std::cout << "Derived::f(int)" << std::endl; }
};

int main()
{
    Derived d;
    d.g();
}
