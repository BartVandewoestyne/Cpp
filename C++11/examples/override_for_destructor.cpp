/*
 * Key idea:
 *
 *   * It is useful to add the override keyword after a virtual destructor
 *     declaration because it is some kind of check: if the Base class does not
 *     have a virtual destructor, but the derived class marks its destructor with
 *     override, then the program is ill-formed and that way you are noticed that
 *     you should add the virtual keyword to the Base class destructor.
 *
 * References:
 *
 *   [stackoverflow20130729] Override identifier after destructor in C++11
 *     http://stackoverflow.com/questions/17923370/override-identifier-after-destructor-in-c11
 */

class Base
{
public:

    //virtual
    ~Base() {}  // Forgot 'virtual' here, which gives error at compile
                // time due to use of 'override' in derived class.
};

class Derived : public Base
{
public:
    ~Derived() override {}  // Error: ~Derived() marked 'override' but does not
                            // override any member functions.
};
