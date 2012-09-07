/************************************************
 * Double a number.                             *
 ************************************************/
#include <iostream>

int main(void)
{
    int number; // A number to double

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << "Twice " << number << " is " <<
        (number * 2) << '\n';
    return (0);
}
