/************************************************
 * print string -- Print a simple string.       *
 ************************************************/
#include <iostream>

extern char *str;       // The string to print

int main()
{
    std::cout << str << std::endl;
    return (0);
}
