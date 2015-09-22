/*
 * Small test program to check how we can default initialize an array in a
 * constructor initializer list.
 *
 * TODO: find reference in C++98 standard that explains this.
 */

#include <iostream>

class Foo {

public:

    Foo() : x() {}  // Probably initializes all elements of x to 0 (check!).

    void print()
    {
        for (int i = 0; i < 5; ++i)
        {
            std::cout << x[i] << std::endl;
        }
    }

private:

    int x[5];

};


int main()
{
    Foo myFoo;
    myFoo.print();
}
