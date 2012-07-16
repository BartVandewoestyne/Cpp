/************************************************
 * Check the flag.                              *
 ************************************************/
#include <iostream>

// When compiling with -pedantic, you get:
//
//   In function ‘int main()’:
//     warning: overflow in implicit constant conversion [-Woverflow]
//
// The problem is that ch can be a signed character.  That means that if ch is
// 0xFF when converted to a signed integer for comparison purposes you get
// int(ch)=-1 (0xFFFFFFF).  That's not 0xFF and the comparison fails.

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
