/************************************************
 * print_element --  Print an element in a      *
 *      matrix.                                 *
 ************************************************/
#include <iostream>

// A simple matrix
int matrix[3][3] = {
    {11, 12, 13},
    {21, 22, 23},
    {31, 32, 33}
};

int main()
{
    std::cout << "Element[1,2] is " <<
        matrix[1,2] << std::endl;
    return (0);
}
