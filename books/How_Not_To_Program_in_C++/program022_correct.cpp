/************************************************
 * Test the logic to limit the size of a        *
 * variable.                                    *
 ************************************************/
#include <iostream>

int main()
{
    int size = 20;      // Size to be limited
    const int MAX = 25; // The limit

    if (size > MAX) {
        std::cout << "Size is too large\n";
        size = MAX;
    }

     std::cout << "Size is " << size << '\n';
     return(0);
}
