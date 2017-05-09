/*
 * References:
 *   [1] http://www.fluentcpp.com/2017/05/09/compact-code-becomes-buggy-code-order-evaluations/
 */

#include <iostream>

int u()
{
    std::cout << "u()" << std::endl;
    return 1;
}

int v()
{
    std::cout << "v()" << std::endl;
    return 2;
}

int w()
{
    std::cout << "w()" << std::endl;
    return 3;
}

void f(int a, int b, int c)
{}

int main()
{
    f(u(), v(), w());
}
