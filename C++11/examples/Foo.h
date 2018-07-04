#include <iostream>

class Foo
{
public:
    Foo()
      { std::cout << "Foo()" << std::endl; }
    Foo(const Foo& other)
      { std::cout << "Foo(const Foo&)" << std::endl; }
    Foo(Foo&& other)
      { std::cout << "Foo(Foo&&)" << std::endl; }
    ~Foo()
      { std::cout << "~Foo()" << std::endl; }

    Foo& operator=(const Foo& other)
      { std::cout << "operator=(const Foo&)" << std::endl; return *this; }
    Foo& operator=(Foo&& other)
      { std::cout << "operator=(Foo&&)" << std::endl; return *this; }
};
