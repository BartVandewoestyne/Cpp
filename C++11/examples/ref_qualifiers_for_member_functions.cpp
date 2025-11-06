/*
 * Key ideas:
 *
 *   From [learncpp]:
 *   - The use of req-qualifiers is not recommended as best practice.  Instead,
 *     it is recommended to always use the result of an access function
 *     immediately and not saving returned references for use later.
 *
 * References:
 *
 *   [learncpp] LearnCpp - 15.10 — Ref qualifiers
 *     https://www.learncpp.com/cpp-tutorial/ref-qualifiers/
 *
 *   [misracpp2023] Misra C++ 2023 rule 6.8.4
 *     https://nl.mathworks.com/help/bugfinder/ref/misracpp2023rule6.8.4.html
 *
 *   [fertig20220705] The power of ref-qualifiers
 *     https://andreasfertig.com/blog/2022/07/the-power-of-ref-qualifiers/
 *
 *   [boccara20210522] The Subtle Dangers of Temporaries in for Loops
 *     https://www.fluentcpp.com/2021/05/22/the-subtle-dangers-of-temporaries-in-for-loops/
 *
 *   [haupt20150408] Introducing ref-qualifiers for member functions
 *     https://wiggling-bits.net/introducing-ref-qualifiers-for-member-functions/
 *     
 *   [bancila20141017] C++ Gems: ref-qualifiers
 *     http://codexpert.ro/blog/2014/10/17/c-gems-ref-qualifiers/
 *
 *   [ballman20140807] Member Function Ref Qualifiers
 *     https://blog.aaronballman.com/2014/07/member-function-ref-qualifiers/
 *
 *   [krzemieński20140602] Ref-qualifiers
 *     https://akrzemi1.wordpress.com/2014/06/02/ref-qualifiers/
 */

#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_name{};

public:
    Employee(const std::string& name): m_name { name } {}

    const std::string& getName() const &  { return m_name; } //  & qualifier overloads function to match only lvalue implicit objects
    std::string        getName() const && { return m_name; } // && qualifier overloads function to match only rvalue implicit objects
    std::string        getName()       && { return std::move(m_name); } // If the implicit object is a non-const rvalue, use std::move to try to move m_name
};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(const std::string& name)
{
    Employee e { name };
    return e;
}

int main()
{
    Employee joe { "Joe" };
    std::cout << joe.getName() << '\n'; // Joe is an lvalue, so this calls std::string& getName() & (returns a reference)

    std::cout << createEmployee("Frank").getName() << '\n'; // Frank is an rvalue, so this calls std::string getName() && (makes a copy)

    return 0;
}
