/************************************************
 * demonstrate how to do a divide.              *
 ************************************************/
#include <iostream>

/************************************************
 * div -- Do a divide                           *
 *                                              *
 * Returns: Result of the divide.               *
 *                                              *
 * divisor is reset to 1.                       *
 ************************************************/
static int div(
    int *divisor        // Pointer to the divisor
)
{
    int result = 5;     // Dividend

    result=result/(*divisor);     /* Do divide */;
    *divisor=1;
    return (result);
}

int main()
{
    int num = 5;        // Divisor

    std::cout << "Division " <<
        div(&num) << std::endl;
    return (0);
}
