/************************************************
 * test out basic arithmetic that we learned in *
 * first grade.                                 *
 ************************************************/
#include <iostream>

int main()
{
    float third = 1.0 / 3.0;    // The value 1/3
    float one = 1.0;            // The value 1

    if ((third+third+third) == one)
    {
        std::cout <<
            "Equal 1 = 1/3 + 1/3 + 1/3\n";
    }
    else
    {
        std::cout <<
            "NOT EQUAL 1 != 1/3 + 1/3 + 1/3\n";
    }
    return (0);
}
