/************************************************
 * Simple divide program.                       *
 ************************************************/
#include <iostream>

int main()
{
    int n1, n2; // Two integers

    std::cout << "Enter two integers: ";
    std::cin >> n1 >> n2;

    if (n2 != 0)
        std::cout << "Result is: " <<
            (n1/n2) << '\n';
    else
        std::cout << "Can not divide by zero\n";

    return (0);
}
