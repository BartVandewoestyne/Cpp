/************************************************
 * test the check_for_even function.            *
 ************************************************/
#include <iostream>

static int value = 20; // Value of the system size

// Checks global value for even or not.
extern void check_for_even(void);

int main(void)
{
    check_for_even();
    std::cout << "Value is " << value << '\n';
    return (0);
}
