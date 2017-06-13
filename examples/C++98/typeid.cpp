/*
 * Small test for myself to see what typeid(32.0).name() returns.
 */

#include <iostream>
#include <typeinfo>

int main()
{
    std::cout << "32.0 is of type " << typeid(32.0).name() << '\n';
}
