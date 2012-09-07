/************************************************
 * Find the area of a rectangle.   The top of   *
 * the rectangle consists of two parts,         *
 * cleverly called PART1 and PART2.             *
 * The side is called SIDE.                     *
 *                                              *
 * So our rectangle looks like:                 *
 * <- TOP_PART1 ->|<-- TOP_PART2 -> |           *
 * +------------------------------+ ^           *
 * |                              | |           *
 * |                              | |           *
 * |                              | | SIDE      *
 * |                              | |           *
 * |                              | |           *
 * +------------------------------+ V           *
 ************************************************/

// First leg of top is 37 feet
#define TOP_PART1 37

// Second part of the top is 33 feet
#define TOP_PART2 33

// Total top size
#define TOP_TOTAL (TOP_PART1 + TOP_PART2)

#define SIDE 10         // 10 Feet on a side

// Area of the rectangle
#define AREA TOP_TOTAL * SIDE

#include <iostream>

int main() {
    std::cout << "The area is " <<
        AREA << std::endl;
    return (0);
}
