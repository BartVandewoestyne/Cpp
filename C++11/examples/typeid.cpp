/*
 * Small test for myself to see what typeid(32.0).name() returns.
 */

#include <cstdint>
#include <iostream>
#include <typeinfo>

int main()
{
    std::cout << typeid(int(1)).name() << "\n";
    std::cout << typeid(std::uint32_t(1)).name() << "\n";
}
