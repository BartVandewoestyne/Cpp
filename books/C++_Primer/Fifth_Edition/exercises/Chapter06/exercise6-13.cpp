#include <iostream>

typedef int T;

// Passes a copy, leaves the original unchanged.
void f1(T a)
{
    a = 1;
}

// Changes the original.
void f2(T& a)
{
    a = 1;
}

int main()
{
    T x = 5;
    std::cout << "x = " << x << std::endl;
    f1(x);
    std::cout << "x = " << x << std::endl;

    x = 5;
    std::cout << "x = " << x << std::endl;
    f2(x);
    std::cout << "x = " << x << std::endl;
}
