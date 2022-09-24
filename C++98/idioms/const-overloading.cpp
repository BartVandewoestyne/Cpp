/*
 * Key ideas:
 *
 *   - const overloading helps you achieve const correctness.
 *
 *   - const overloading is when you have an inspector method and a mutator
 *     method with the same name and the same number of and types of parameters.
 *     The two distinct methods differ only in that the inspector is const
 *     and the mutator is non-const.
 *
 *   - The most common use of const overloading is with the subscript operator:
 *     subscript operators often come in pairs.
 *
 *   - You can, of course, also use const-overloading for things other than the
 *     subscript operator.
 *
 * References:
 *
 *   [C++ FAQ] What’s the deal with “const-overloading”?
 *     https://isocpp.org/wiki/faq/const-correctness#const-overloading
 *
 *   [mao] C++ Const Overloading
 *     https://leimao.github.io/blog/CPP-Const-Overloading/
 *
 *   [stackoverflow20150107] Same function with const and without - When and why?
 *     https://stackoverflow.com/questions/27825443/same-function-with-const-and-without-when-and-why
 *
 *   [stackoverflow20081030] What is the use of const overloading in C++?
 *     https://stackoverflow.com/questions/251159/what-is-the-use-of-const-overloading-in-c
 */

#include <iostream>

struct Foo
{
    // Removing const override breaks compilation.
    void f() const { std::cout << "f() const called" << std::endl; }
    void f() { std::cout << "f() called" << std::endl; }
};

int main()
{
    Foo foo;
    const Foo cfoo;

    foo.f();   // f() called
    cfoo.f();  // f() const called
}
