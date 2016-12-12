/*
 * Simple test to see if it is also useful to use the 'override' keyword
 * on destructors.
 *
 * References:
 *   [1] http://stackoverflow.com/questions/17923370/override-identifier-after-destructor-in-c11
 */

class Base
{
public:

    ~Base() {}  // Forgot 'virtual' here, which gives error at compile
                // time due to use of 'override' in derived class.
};

class Derived : public Base
{
public:
    virtual ~Derived() override {}
};
