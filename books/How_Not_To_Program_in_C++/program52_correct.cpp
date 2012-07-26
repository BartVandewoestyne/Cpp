/************************************************
 * Demonstration of the rectangle class.        *
 ************************************************/
#include <iostream>

/************************************************
 * rectangle -- hold constant information about *
 *              a rectangle.                    *
 *                                              *
 * Members:                                     *
 *      area -- Area of the rectangle.          *
 *      width -- width of the rectangle.        *
 *      height - length of the rectangle.       *
 ************************************************/
class rectangle
{
    public:
        const int width;  // Rectangle's Width
        const int height; // Rectangle's Height
        const int area;   // Rectangle's Area

    public:
        // Create a rectangle and assign the
        // initial values
        rectangle(
            const int i_width,  // Initial width
            const int i_height  // Initial height
        ) : width(i_width),
            height(i_height),
            area(width*height)
        {}
        // Destructor defaults
        // Copy constructor defaults
        // Assignment operator defaults
};

int main()
{
    // Rectangle to play with
    rectangle sample(10, 5);

    std::cout << "Area of sample is " <<
        sample.area << std::endl;
    return (0);
}
