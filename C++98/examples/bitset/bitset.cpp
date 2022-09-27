/*
 * Note: it seems like bitset is redundant and could use revision or removal,
 *       see [sutter199801XX].  Probably better not to use it.
 *
 * References:
 *
 *   [trivedi20180904] C++ bitset and its application
 *     https://www.geeksforgeeks.org/c-bitset-and-its-application/
 *
 *   [dhamodaran20180308] C++ Bitset With Example
 *     https://owlcation.com/stem/C-bitset-with-example

 *   [josuttis20120330] The C++ Standard Library, A Tutorial and Reference, Second Edition, page 651.
 *     http://www.cppstdlib.com/
 *
 *   [austern20010501] The Standard Librarian: Bitsets and Bit Vectors
 *     http://www.drdobbs.com/the-standard-librarian-bitsets-and-bit-v/184401382
 *
 *   [sutter199801XX] C++ State of the Union
 *     http://www.gotw.ca/publications/mill01.htm
 */

#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    // enumeration type for the bits
    // - each bit represents a color
    enum Color { red, yellow, green, blue, white, black,
                 numColors };

    // create bitset for all bits/colors
    bitset<numColors> usedColors;

    // set bits for two colors
    usedColors.set(red);
    usedColors.set(blue);

    // print some bitset data
    cout << "bitfield of used colors: " << usedColors << endl;
    cout << "number of used colors: " << usedColors.count() << endl;
    cout << "bitfield of unused colors: " << ~usedColors << endl;

    // if any color is used
    if (usedColors.any()) {
        // loop over all colors
        for (int c = 0; c < numColors; ++c) {
            // if the actual color is used
            if (usedColors[(Color)c]) {
            /// ...
            }
        }
    }
}
