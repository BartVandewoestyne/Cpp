/************************************************
 * print_zip -- Print out a couple of zip codes.*
 ************************************************/
#include <iostream>
#include <iomanip>

int main()
{
    // Zip code for San Diego
    const long int san_diego_zip = 92126;

    // Zip code for Boston
    const long int boston_zip = 2126;

    std::cout << "San Diego " << std::setw(5) <<
        std::setfill('0') <<
        san_diego_zip << std::endl;

    std::cout << "Boston " << std::setw(5) <<
        std::setfill('0') <<
        boston_zip << std::endl;

    return (0);
}
