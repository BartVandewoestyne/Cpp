/**
 * My own test example on const pointers.
 */

#include <iostream>

int main()
{
    int a = 1;
    int b = 2;

    int* pi1;
    const int* pi2;

    pi1 = &a;
    pi2 = &b;

    std::cout << "*pi1 = " << *pi1 << std::endl;
    std::cout << "*pi2 = " << *pi2 << std::endl;

    // Using the dereference operator, you can change the contents of where
    // a normal pointer points to.
    *pi1 = 3;

    // But you cannot use the dereference operator to change the contents of
    // a const int* pointer.
    //*pi2 = 4; // error: assignment of read-only location ‘* pi2’

    std::cout << "*pi1 = " << *pi1 << std::endl;
    std::cout << "*pi2 = " << *pi2 << std::endl;

    // We can however still change the values at the locations using the
    // ordinary variables.
    a = 5;
    b = 6;

    std::cout << "*pi1 = " << *pi1 << std::endl;
    std::cout << "*pi2 = " << *pi2 << std::endl;
}
