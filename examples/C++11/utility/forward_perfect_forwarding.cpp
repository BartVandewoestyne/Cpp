/*
 * Illustrates the following use case for std::forward: to cast a templated
 * function parameter (inside the function) the the value category (lvalue or
 * rvalue) the caller used to pass it.  This allows rvalue arguments to be
 * passed on as rvalues, and lvalues to be passed on as lvalues, a scheme
 * called "perfect forwarding".
 * 
 * References:
 *
 *   [aCuria20120312] What's the difference between std::move and std::forward
 *     https://stackoverflow.com/questions/9671749/whats-the-difference-between-stdmove-and-stdforward
 */

#include <iostream>

void overloaded(const int& arg) { std::cout << "by lvalue\n"; }
void overloaded(int&& arg) { std::cout << "by rvalue\n"; }

/* 'T&&' with 'T' being template param is special, and  adjusts 'T' to be
   (for example) 'int&' or non-ref 'int' so std::forward knows what to do. */
template<typename T>
void forwarding(T&& arg)
{
    std::cout << "  => via std::forward: ";
    overloaded(std::forward<T>(arg));

    std::cout << "  => via std::move: ";
    overloaded(std::move(arg)); // conceptually this would invalidate arg

    std::cout << "  => by simple passing: ";
    overloaded(arg);
}

int main()
{
    std::cout << "initial caller passes rvalue:\n";
    forwarding(5);

    std::cout << "initial caller passes lvalue:\n";
    int x = 5;
    forwarding(x);
}
