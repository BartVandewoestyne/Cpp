/************************************************
 * Check the flag.                              *
 ************************************************/
#include <iostream>

int main()
{
    char ch;    // The flag

    ch = 0xFF;  // Set the flag

    // Check the flag
    if (ch == 0xFF)
        std::cout << "Success\n";
    else
        std::cout << "Fails\n"; 

    return (0);
}
