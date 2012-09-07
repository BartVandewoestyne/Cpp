/************************************************
 * test_max -- Test the max function.           *
 ************************************************/
#include <iostream>

/************************************************
 * max -- return the larger of two integers.    *
 *                                              *
 * Returns:                                     *
 *      biggest of the two numbers.             *
 ************************************************/
const int max(
    const int &i1,      // A number
    const int &i2       // Another number
)
{
    if (i1 > i2)
        return (i1);
    return (i2);
}

int main()
{
    // I is the biggest of the two expression
    const int i = max(1+2, 3+4);

    std::cout <<
        "The biggest expression is " <<
        i << std::endl;

    return (0);
}
