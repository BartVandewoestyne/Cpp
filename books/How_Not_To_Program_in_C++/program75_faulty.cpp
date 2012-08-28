/************************************************
 * Test the square_root function.               *
 ************************************************/
#include <iostream>
#include <math.h>

/************************************************
 * ABORT -- print an error message and abort.   *
 ************************************************/
#define ABORT(msg) \
    std::cerr << msg << std::endl;exit(8);
/************************************************
 * square_root -- Find the square root of the   *
 *      value.                                  *
 *                                              *
 * Returns:                                     *
 *      The square root.                        *
 ************************************************/
static int square_root(
    const int value
) {
    if (value < 0)
        ABORT("Illegal square root");

    return (int(sqrt(float(value))));
}

int main() {
    int square; // A number that's square
    int root;   // The square root of the number

    square = 5 * 5;
    root = square_root(square);

    std::cout << "Answer is: " << root << '\n';
    return (0);
}
