/*
 * Illustrates the usefulness of dynamic_cast<>
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/2253168/dynamic-cast-and-static-cast-in-c
 */

#include <iostream>
#include <cstdlib>
using namespace std;

class Base
{
public:
    virtual void DoIt() = 0;    // pure virtual
    virtual ~Base() {};
};

class Foo : public Base
{
public:
    virtual void DoIt() { std::cout << "Foo" << std::endl; }; 
    void FooIt() { std::cout << "Fooing It..." << std::endl; }
};

class Bar : public Base
{
public :
    virtual void DoIt() { std::cout << "Bar" << std::endl; }
    void BarIt() { std::cout << "Baring It..." << std::endl; }
};

Base* CreateRandom()
{
    if( (rand()%2) == 0 )
        return new Foo;
    else
        return new Bar;
}

int main()
{
    std::cout << "Using C-style casts:" << std::endl;

    for( int n = 0; n < 10; ++n )
    {
        // main() can 't tell what kind of object CreateRandom() will return...
        Base* base = CreateRandom();
        base->DoIt();

        // ... so this C-style cast is decidedly not type-safe.
        Bar* bar = (Bar*)base;
        bar->BarIt();
    }


    std::cout << "Using dynamic_cast<>:" << std::endl;

    for( int n = 0; n < 10; ++n )
    {
        Base* base = CreateRandom();
        base->DoIt();

        Bar* bar = dynamic_cast<Bar*>(base);
        Foo* foo = dynamic_cast<Foo*>(base);
        if (bar)
            bar->BarIt();
        if (foo)
            foo->FooIt();
    }


     return 0;
}
