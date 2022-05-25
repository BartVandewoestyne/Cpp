/*
 * Key idea:
 *
 *   - In an expression
 *       f(a, b, c);
 *     the order of evaluation is still unspecified in C++17, but any parameter
 *     is fully evaluated before the next one is started.  That is especially
 *     crucial for complex expressions like this:
 *       f(a(x), b, c(y));
 *
 * References:
 *
 *   [filipek20210816] Stricter Expression Evaluation Order in C++17
 *     https://www.cppstories.com/2021/evaluation-order-cpp17/
 */

#include <iostream>

int g(int x)
{
    std::cout << "g(x)" << std::endl;
    return x;
}

int h(int x)
{
    std::cout << "h(x)" << std::endl;
    return x;
}

int foo(int x)
{
    std::cout << "foo(x)" << std::endl;
    return x;
}

int bar(int x)
{
    std::cout << "bar(x)" << std::endl;
    return x;
}

void f(int a, int b)
{}

int main()
{
    int x = 1;

    // I think it is now guaranteed that after g(x) is executed, we will first
    // execute foo().  The order of foo and bar is still undetermined.
    // TODO: check this!
    f(foo(g(x)), bar(h(x)));
}
