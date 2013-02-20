/**
 * TODO: check this.
 */

#include <iostream>
#include <typeinfo>

int main()
{
    std::cout << typeid('a').name() << std::endl;   // char
    std::cout << typeid(L'a').name() << std::endl;  // wchar_t
    std::cout << typeid("a").name() << std::endl;   // string
    std::cout << typeid(L"a").name() << std::endl;

    std::cout << typeid(10).name() << std::endl;    // int
    std::cout << typeid(10u).name() << std::endl;   // unsigned int
    std::cout << typeid(10L).name() << std::endl;   // long
    std::cout << typeid(10uL).name() << std::endl;  // unsigned long
    std::cout << typeid(012).name() << std::endl;   // octal integer
    std::cout << typeid(0xC).name() << std::endl;   // hexadecimal integer

    std::cout << typeid(3.14).name() << std::endl;  // double
    std::cout << typeid(3.14f).name() << std::endl; // float
    std::cout << typeid(3.14L).name() << std::endl; // long double

    std::cout << typeid(10).name() << std::endl;    // int
    std::cout << typeid(10u).name() << std::endl;   // unsigned int
    std::cout << typeid(10.).name() << std::endl;   // double
    std::cout << typeid(10e-2).name() << std::endl; // double
}
