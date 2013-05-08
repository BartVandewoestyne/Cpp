#include <iostream>

void f_a()
{
    int* ip, i, &r = i;

    std::cout << ip << std::endl;  // uninitialized pointer to int
    std::cout << i << std::endl;   // uninitialized int
    std::cout << r << std::endl;   // reference to uninitialized integer
}

void f_b()
{
    int i, *ip = 0;

    std::cout << i << std::endl;    // uninitialized int
    std::cout << ip << std::endl;   // pointer to int, initialized to
                                    // the null pointer
}

void f_c()
{
    int* ip, ip2;

    std::cout << ip << std::endl;   // uninitialized pointer to int
    std::cout << ip2 << std::endl;  // uninitialized int
}

int main()
{
    f_a();
    f_b();
    f_c();
}
