/************ *********** ************ **********
 * Simple syntax testing.                       *
 ************************************************/
#include <iostream>

int main(void)
{
    int x,y;    // Two numbers

    x = 1;

    y = (x<<2) + 1; // x<<2 = 4 so y = 4+1 = 5
    std::cout << "Y=" << y << std::endl;
    return (0);
}
