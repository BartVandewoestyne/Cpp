/**
 * Question:
 *
 *   What is the output of this program?
 *
 * References:
 *
 *   [1] http://blog.knatten.org/2012/09/14/c-puzzle-1-initialization-order/
 */

#include <iostream>
using namespace std;

class Parent
{
public:
    Parent(int p=0.0) : p(p)
    {
        cout << "Parent(" << p << ")" << endl;
    }

    int p;
};


class Member
{
public:
    Member(int m=0.0) : m(m)
    {
        cout << "Member(" << m << ")" << endl;
    }

    Member& operator=(const Member& rhs)
    {
            cout << "Member is copied" << endl;
            m = rhs.m;
    }

    int m;
};


// UNDEFINED BEHAVIOR
class Derived : public Parent
{
public:

    // Note that the initialization order does not macht the order in
    // which the foo and bar variables are defined!!!
    Derived() : foo(10), bar(foo*2)
    {
        Parent(7);
        m = Member(42);
    }

    // The problem is in these two lines!!!
    int bar;
    int foo;

    Member m;
};

// CORRECT BEHAVIOR
// class Derived : public Parent
// {
// public:
//     Derived() : Parent(7), foo(10), bar(foo*2), m(42) {}
// 
//     int foo;
//     int bar;
//     Member m;
// };


int main()
{
    Derived d;
    cout << d.p << " " << d.foo << " " << d.bar << " " << d.m.m << endl;
};
