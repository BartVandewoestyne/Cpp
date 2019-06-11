/*
 * References:
 * 
 *   [cppreference] http://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
 *
 *   [sahar2016] Exploring std::unique_ptr.
 *     http://shaharmike.com/cpp/unique-ptr/ (haven't read this one yet)
 *
 *   [niting2016] Advantages of using make_unique over new operator [duplicate].
 *     https://stackoverflow.com/questions/37514509/advantages-of-using-make-unique-over-new-operator
 *
 *   [stackoverflow20140321] Differences between std::make_unique and std::unique_ptr.
 *     https://stackoverflow.com/questions/22571202/differences-between-stdmake-unique-and-stdunique-ptr-with-new
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
