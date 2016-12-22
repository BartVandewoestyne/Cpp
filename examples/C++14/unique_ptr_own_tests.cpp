/*
 * Some of my own tests with std::unique_ptr.
 */

#include <iostream>
#include <memory>

struct Foo {};

int main()
{
    Foo f;


    /* Creating */

    std::unique_ptr<Foo> pf;

    std::cout << "pf.get() = " << pf.get() << std::endl;


    /* Initializing */

    //pf = &f;  // error

    //pf = std::unique_ptr<Foo>(&f);  // TODO: check why this causes the error 'Aborted (core dumped)'.
    
    //pf = std::unique_ptr<Foo>(new Foo());  // OK, but prefer C++14 std::make_unique

    pf = std::make_unique<Foo>(); // C++14

    std::cout << "pf.get() = " << pf.get() << std::endl;


    /* Resetting */

    pf.reset(new Foo());

    std::cout << "pf.get() = " << pf.get() << std::endl;
}
