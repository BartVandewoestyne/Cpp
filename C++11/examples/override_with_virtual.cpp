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
 *   [cppcoreguidelines] C.128: Virtual functions should specify exactly one of virtual, override, or final
 *     https://github.com/isocpp/CppCoreGuidelines/blob/036324/CppCoreGuidelines.md#c128-virtual-functions-should-specify-exactly-one-of-virtual-override-or-final
 *
 *   [sonarsource] "override" or "final" should be used instead of "virtual"
 *     https://rules.sonarsource.com/cpp/RSPEC-3471/
 *
 *   [daniel2016] virtual? override? or both? C++ [duplicate]
 *     https://stackoverflow.com/questions/39932391/virtual-override-or-both-c
 *
 *   [misracpp2008] Rule 10–3–2 (Required) Each overriding virtual function shall be declared with the virtual keyword.
 *     http://www.tlemp.com/download/rule/MISRA-CPP-2008-STANDARD.pdf (page 129)
 *     => Note that this was a guideline from before C++11 was introduced!
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
