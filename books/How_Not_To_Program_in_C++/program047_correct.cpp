/************************************************
 * read config file -- Open a configuration     *
 *      file and read in the data.              *
 *                                              *
 * Designed to work on both UNIX and MS-DOS.    *
 *                                              *
 * Note: Incomplete program.                    *
 ************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>  // book forgot this include...

#ifdef MS_DOS

// DOS path
const char name[] = "\\root\\new\\table";

#else /* MS_DOS */

// UNIX path
const char name[] = "/root/new/table";

#endif /* MS_DOS */


int main() {
    // The file to read
    std::ifstream in_file(name);

    if (in_file.fail())   // correct version
    //if (in_file.bad())  // wrong version from book
    {
        std::cerr <<
            "Error: Could not open " << std::endl;
        std::cerr << name << std::endl;
        exit (8);
    }

    return (0);
}
