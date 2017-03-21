/*
 * Example illustrating how int gets converted to unsigned int first,
 * if you combine unsigned int and int in an arithmetic operation.
 */
#include <iostream>

int main()
{
    unsigned int a = 2;
    int b = -1;

    if (b < a)  // int gets converted to unsigned int here, before doing the operation.
    {
         std::cout << "b < a" << std::endl;
    }
    else
    {
        std::cout << "b >= a" << std::endl;
    }
}
