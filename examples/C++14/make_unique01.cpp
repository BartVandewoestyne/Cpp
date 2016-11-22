/*
 * References:
 * 
 *   [1] http://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
 *   [2] http://shaharmike.com/cpp/unique-ptr/ (haven't read this one yet)
 */

#include <iostream>
#include <memory>

class Foo
{
public:
    Foo() { std::cout << "Foo()" << std::endl; }
    ~Foo() { std::cout << "~Foo()" << std::endl; }
};

int main()
{
    auto f = std::make_unique<Foo>();
}
