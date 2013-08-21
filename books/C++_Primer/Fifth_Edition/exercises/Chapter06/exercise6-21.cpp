#include <iostream>

int f(int x, const int* y)
{
    return (x > *y) ? x : *y;
}

int main()
{
    int a = 7;
    int b = 6;
    int *c = &b;

    std::cout << f(a, c) << std::endl;
}
