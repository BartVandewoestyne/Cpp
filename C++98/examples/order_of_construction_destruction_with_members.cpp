/*
 * References:
 *
 *   [stackoverflow20100212] Order of member constructor and destructor calls
 *     http://stackoverflow.com/questions/2254263/order-of-member-constructor-and-destructor-calls
 *
 *   [stackoverflow20150205] What order are destructors called and member variables destroyed in C++ using inhertitance?
 *     http://stackoverflow.com/questions/28356069/what-order-are-destructors-called-and-member-variables-destroyed-in-c-using-in
 */

#include <iostream>

struct A
{
    A() { std::cout << "A()" << std::endl; }
    ~A() { std::cout << "~A()" << std::endl; }
};

struct B
{
    B() { std::cout << "B()" << std::endl; }
    ~B() { std::cout << "~B()" << std::endl; }
};

struct C
{
    C() { std::cout << "C()" << std::endl; }
    ~C() { std::cout << "~C()" << std::endl; }
};

struct Aggregate
{
    Aggregate() { std::cout << "Aggregate()" << std::endl; }
    ~Aggregate() { std::cout << "~Aggregate()" << std::endl; }

    A a;
    B b;
    C c;
};

int main()
{
    Aggregate a;
    return 0;
}
