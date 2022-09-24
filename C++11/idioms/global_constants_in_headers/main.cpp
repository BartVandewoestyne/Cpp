/*
 * Compile with
 *
 *   g++ main.cpp constants.cpp file1.cpp file2.cpp -o test
 */

#include "file1.h"
#include "file2.h"

#include <iostream>

int main()
{
    std::cout << "At beginning of main()" << std::endl;

    printFromFile1();
    printFromFile2();

    std::cout << "At end of main()" << std::endl;
}
