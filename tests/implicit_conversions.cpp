/**
 * Program to illustrate different implicit conversions and how to avoid them.
 */

#include <iostream>

int main()
{
    {   // implicit conversion turns floating point number into integer: 'double' to 'int'

        int x1 = 1.0;
        int x2 = static_cast<int>(1.0);
    }

    { // implicit conversion turns string literal into bool: 'const char[1]' to 'bool'

        bool x1 = "";
	bool x2 = static_cast<bool>("");
	if (x1) {
	    std::cout << "x1 is true" << std::endl;
	} else {
	    std::cout << "x1 is false" << std::endl;
	}
	if (x2) {
	    std::cout << "x2 is true" << std::endl;
	} else {
	    std::cout << "x2 is false" << std::endl;
	}
    }
}
