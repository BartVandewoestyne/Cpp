/*!
 * Illustrates how in the body of a nonstatic member function, the keyword
 * 'this' is a non-lvalue expression whose value is the address of the object for
 * which the function is called.
 *
 * References:
 *
 *   [1] ISO/IEC 14882:1998(E), section 9.3.2 'The this pointer' [class.this]
 */

#include <iostream>

class Foo {
public:

    // Constructors can not be declared const, volatile or const volatile.
    Foo()
    {
        member = 1;

        //this = new Foo;  // error: lvalue required as left operand of assignment
    }

    // Nonstatic non-const member function: the type of this is Foo*
    void f_nonconst()
    {
        member = 1;        // perfectly legal, because *this is not const
        this->member = 1;  // the same

        //this = new Foo;    // error: lvalue required as left operand of assignment
    }

    // Nonstatic const member function: the type of this is const Foo* (this is
    // a pointer to const; that is, *this has const type)
    void f_const() const
    {
        //member = 1;        // error: assignment of member 'Foo::member' in read-only object
        //this->member = 1;  // error: assignment of member 'Foo::member' in read-only object

        //this = new Foo;  // error: lvalue required as left operand of assignment
    }

private:
    int member;
};

int main()
{
    Foo myFoo;
    myFoo.f_nonconst();
    myFoo.f_const();
}
