#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r;     // a is 'int'
    auto b = ci;    // b is 'int'
    auto c = cr;    // c is 'int'
    auto d = &i;    // d is 'int*'
    auto e = &ci;   // e is 'const int*'
    auto &g = ci;   // g is 'const int&'

    // OK: assignment from 'int' to 'int'
    std::cout << a << std::endl;
    a = 42;
    std::cout << a << std::endl;

    // OK: assignment from 'int' to 'int
    std::cout << b << std::endl;
    b = 42;
    std::cout << b << std::endl;

    // OK: assignment from 'int' to 'int'
    std::cout << c << std::endl;
    c = 42;
    std::cout << c << std::endl;

    // error: invalid conversion from ‘int’ to ‘int*’
    //d = 42;

    // error: invalid conversion from ‘int’ to ‘const int*’
    //e = 42;

    // error: assignment of read-only reference ‘g’
    //g = 42;
}
