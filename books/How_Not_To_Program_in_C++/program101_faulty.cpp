/*************************************************
 * Create a test file containing binary data.    *
 *************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>

int main()
{
    // current character to write
    unsigned char cur_char;

    // output file
    std::ofstream out_file;

    out_file.open("test.out", std::ios::out);
    if (out_file.bad())
    {
        std::cerr << "Can not open output file\n";
        exit (8);
    }

    for (cur_char = 0;
         cur_char < 128;
         ++cur_char)
    {
        out_file << cur_char;
    }
    return (0);
}
