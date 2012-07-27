#include <iostream>
#include <string>

/************************************************
 * tmp_name -- return a temporary file name     *
 *                                              *
 * Each time this function is called, a new     *
 * name will be returned.                       *
 *                                              *
 * Returns *
 *      String containing the name.             *
 ************************************************/
std::string tmp_name()
{
    // The name we are generating
    std::string name;

    // Sequence number for last digit
    static int sequence = 0;

    ++sequence; // Move to the next file name

    name = "tmp";

    // Put in the squence digit
    name += static_cast<char>(sequence + '0');

    return(name);
}

int main()
{
    std::string name1 = tmp_name();

    std::cout <<"Name1: " << name1 << '\n';
    return(0);
}
