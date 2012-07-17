#include <iostream>

// Value of the control system size
int value = 30;

/************************************************
 * check_for_even -- Check to see if global     *
 *      value is even.                          *
 ************************************************/
void check_for_even(void)
{
    if ((value % 2) == 0)
        std::cout << "Ok\n";
    else
        std::cout << "Value problem\n";
}
