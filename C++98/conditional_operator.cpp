/*
 * References:
 *
 *   [cppreference] Conditional operator
 *     https://en.cppreference.com/w/cpp/language/operator_other#Conditional_operator
 */

#include <iostream>

int main()
{   
    // simple rvalue example
    int n = 1 > 2 ? 3 : 4;  // 1 > 2 is false, so n = 4
    std::cout << "n = " << n << std::endl;

    // simple lvalue example
    int a = 1;
    int b = 2; 
    (a == b ? a : b) = 3;  // a == b is false, so a = 1 and b = 3
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
