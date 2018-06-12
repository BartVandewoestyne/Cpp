/*
 * Example that demonstrates how one can change the access level of a virtual
 * function (not that it is good style though!)
 *
 * References:
 *
 *   [tower120_20180606] C++ override private pure virtual method as public
 *     https://stackoverflow.com/questions/50722824/c-override-private-pure-virtual-method-as-public
 *     https://www.reddit.com/r/cpp/comments/8p1s70/overriding_private_virtual_method_as_public/
 *
 *   [nakiya20101104] How and why is it possible to change access level of a member?
 *     http://stackoverflow.com/questions/4094534/how-and-why-is-it-possible-to-change-access-level-of-a-member
 *
 *   [ellis1990stroustrup] The Annotated C++ Reference Manual
 *     TODO: find section that discusses this
 */

#include <iostream>

class Base {
public:
    virtual void f() { std::cout << "Base::f()" << std::endl; }
};

class DerivedPublic : public Base {
public:
    virtual void f() { std::cout << "DerivedPublic::f()" << std::endl; }
};

class DerivedProtected : public Base {
protected:
    virtual void f() { std::cout << "DerivedProtected::f()" << std::endl; }
};

class DerivedPrivate : public Base {
private:
    virtual void f() { std::cout << "DerivedPrivate::f()" << std::endl; }
};

int main()
{
    Base* b = new Base();
    b->f();


    Base* db_public = new DerivedPublic();
    db_public->f();

    Base* db_protected = new DerivedProtected();
    db_protected->f();  // allowed!

    Base* db_private = new DerivedPrivate();
    db_private->f();  // allowed!


    DerivedPublic* d_public = new DerivedPublic();
    d_public->f();

    DerivedProtected* d_protected = new DerivedProtected();
    //d_protected->f();  // Error: 'virtual void DerivedProtected::f()' is protected

    DerivedPrivate* d_private = new DerivedPrivate();
    //d_private->f();  // Error: 'virtual void DerivedPrivate::f()' is private
}
