/************************************************
 * Test the logic to limit the width and height *
 * of a rectangle.                              *
 ************************************************/
#include <iostream>

int main()
{
    // The smallest legal value
    // of width and height
    const int MIN = 10;

    int width = 5;      // Current width
    int height = 50;    // Current height

    if (width < MIN) {
        std::cout << "Width is too small\n";
        width = MIN;
    }

    if (height < MIN) {
        std::cout << "Height is too small\n";
        height = MIN;
    }

    std::cout << "area(" << width << ", " <<
        height << ")=" <<
        (width * height) << '\n';
    return (0);
}
