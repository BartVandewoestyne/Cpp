/************************************************
 * Toy program to print three characters.       *
 ************************************************/
#include <iostream>

int main()
{
    //A character to be printed
    char ch = 'A';

    std::cout << ch;        // Output A
    std::cout << static_cast<char>(ch+1);      // Output B
    std::cout << static_cast<char>(ch+2);      // Output C
    std::cout << std::endl;
    return (0);
}
