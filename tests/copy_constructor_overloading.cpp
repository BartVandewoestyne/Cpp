/*
 * Program to test what copy-constructor will be called: our user-defined with
 * the defaultArgument = true or a default generated one.
 */

#include <iostream>

class Foo
{
public:

    Foo()
    {
        std::cout << "Foo()" << std::endl;
    }

    Foo(Foo& src, bool defaultArgument = true)
    {
        std::cout << "Foo(Foo& src, bool defaultArgument = true)" << std::endl;
    }
};


int main()
{
    Foo a;
    Foo b(a);
}
