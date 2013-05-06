#include <iostream>

int main()
{
    int i = 42;       // Declare variable i to be 42.
    int *p1 = &i;     // Define p1 as a pointer and set it to the address of i.
    *p1 = *p1 * *p1;  // Square the content of where i points to.

    // The variable i now has the value 42*42 = 1764.
    std::cout << i << std::endl;
}
