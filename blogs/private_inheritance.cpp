/**
 * References:
 *
 *   [1] http://blog.knatten.org/2012/09/20/private-inheritance/
 */

class Base
{
public:
    void pub() {}
private:
    void priv() {}
};

class DerivedPublic : public Base
{
};

class DerivedPrivate : private Base
{
};

class DerivedPrivate2: private Base
{
public:
    void foo() { pub(); }
};

class NotDerived
{
public:
    void foo() { b.pub(); }
private:
    Base b;
};


int main()
{
    DerivedPublic derivedPublic;
    derivedPublic.pub();
    //derivedPublic.priv(); //error: ‘void Base::priv()’ is private

    DerivedPrivate derivedPrivate;
    //derivedPrivate.pub(); //error: ‘void Base::pub()’ is inaccessible
    //derivedPrivate.priv(); //error: ‘void Base::priv()’ is private

    DerivedPrivate2 derivedPrivate2;
    derivedPrivate2.foo();
    //derivedPrivate2.pub(); //error: ‘void Base::pub()’ is inaccessible
}
