/**
 * My own test example on const pointers.
 */

#include <iostream>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    int* pi1 = &a;
    const int* pi2 = &b;
    const int* const pi3 = &c;

    std::cout << "After initialization:" << std::endl;
    std::cout << "  *pi1 = " << *pi1 << std::endl;
    std::cout << "  *pi2 = " << *pi2 << std::endl;
    std::cout << "  *pi3 = " << *pi3 << std::endl;

    *pi1 = 11;  // ok
    //*pi2 = 22;  // error: assignment of read-only location ‘* pi2’
    //*pi3 = 33;  // error: assignment of read-only location ‘*(const int*)pi3’

    std::cout << "After changing the pointed-to object using dereference operator:" << std::endl;
    std::cout << "  *pi1 = " << *pi1 << std::endl;
    std::cout << "  *pi2 = " << *pi2 << std::endl;
    std::cout << "  *pi3 = " << *pi3 << std::endl;
    std::cout << "  a = " << a << std::endl;
    std::cout << "  b = " << b << std::endl;
    std::cout << "  c = " << c << std::endl;

    a = 5;
    b = 6;
    c = 7;

    std::cout << "After change with local variables:" << std::endl;
    std::cout << "  *pi1 = " << *pi1 << std::endl;
    std::cout << "  *pi2 = " << *pi2 << std::endl;
    std::cout << "  *pi3 = " << *pi3 << std::endl;

    int d = 4;
    pi1 = &d;  // ok
    pi2 = &d;  // ok
    //pi3 = &d;  // error: assignment of read-only variable ‘pi3’

    std::cout << "After changing the pointer value:" << std::endl;
    std::cout << "  *pi1 = " << *pi1 << std::endl;
    std::cout << "  *pi2 = " << *pi2 << std::endl;
    std::cout << "  *pi3 = " << *pi3 << std::endl;
}
