/************************************************
 * test to see if three variables are in order. *
 ************************************************/
#include <iostream>

int main()
{
    int a,b,c;  // Three simple variables

    a = 7;
    b = 5;
    c = 3;

    // Test to see if they are in order
    if (a > b && b > c)
        std::cout << "a,b,c are in order\n";
    else
        std::cout << "a,b,c are mixed up\n";
    return (0);
}
