#include <iostream>

int main()
{
    int a = 3, b = 4;     // a is 'int', b is 'int'
    decltype(a) c = a;    // c is 'int' and gets initialized to a=3.
    decltype((b)) d = a;  // d is 'int&' and gets initialized to a=3.
    ++c;                  // c becomes 4
    ++d;                  // d becomes 4, but since d is a reference to a, a is
                          // also 4 now!!!

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}
