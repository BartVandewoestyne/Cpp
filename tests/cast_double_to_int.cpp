/**
 * Program that shows how a double gets casted to an int.
 * 
 * Apparently, it simply drops the fractional part.
 */
#include <iomanip>
#include <iostream>

int main()
{
    for (double n = -2.0; n < 2.0; n += 0.1)
    {
        std::cout << std::fixed << std::showpos << std::setprecision(1)
	          << "(int)(" << n << "): "
		  << (int)(n) << ", "
	          << "static_cast<int>(" << n << "): " << static_cast<int>(n) << std::endl;
    }
}
