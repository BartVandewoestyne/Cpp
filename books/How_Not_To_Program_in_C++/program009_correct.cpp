/************************************************
 * triangle -- Compute the area of a triangle   *
 ************************************************/
#include <iostream>
int main()
{
    int base = 0;   /* Base of the triangle */
    int height = 0; /* Height of the triangle */

    base = 5;      /* Set the base of the triangle */
    height = 2;    /* Set the height */

    // Area of the triangle
    int area = (base * height) / 2;

    std::cout << "The area is " <<
            area << std::endl;
    return (0);
}
