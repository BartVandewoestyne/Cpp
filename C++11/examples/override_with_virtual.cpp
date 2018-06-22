/*
 * The general advice is:
 *
 *   * Use virtual for the base class function declaration.
 *     (This is technically necessary.)
 *
 *   * Use override (only) for a derived class' override.
 *     (This helps maintenance.)
 *
 * Clang-Tidy also gives warnings like
 *
 *   "prefer using 'override' or (rarely) 'final' instead of 'virtual'"
 *
 * References:
 *
 *   [daniel2016] virtual? override? or both? C++ [duplicate]
 *     https://stackoverflow.com/questions/39932391/virtual-override-or-both-c
 */

class Base
{
public:
    virtual void print() const = 0;
    virtual void printthat() const = 0;
    virtual void printit() const = 0;
};

class Derived : public Base
{
public:
    // only virtual keyword for overriding.
    virtual void print() const {}

    // only override keyword for overriding (PREFERRED)
    void printthat() const override {}

    // using both virtual and override keywords for overriding.
    virtual void printit() const override {}
};
