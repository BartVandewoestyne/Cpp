/**
 * Example on static member initialization.
 *
 * TODO: check for errors and add reference.
 */

#include <iostream>

class Bar {
public:
    Bar() { std::cout << "Bar()" << std::endl; }
};

class Foo {
private:
    static Bar b;
};

Bar Foo::b = Bar();

int main()
{
    std::cout << "main()" << std::endl;
}
