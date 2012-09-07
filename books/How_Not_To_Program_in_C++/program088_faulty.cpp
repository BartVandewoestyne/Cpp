/************************************************
 * copy -- Copy the input file to the output    *
 *      file.                                   *
 ************************************************/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>

/************************************************
 * copy_it -- Copy the data                     *
 ************************************************/
void copy_it(
    FILE *in_file,      // Input file
    std::ostream &out_file   // Output file
)
{
    int ch;      // Current char

    while (1) {
        ch = std::fgetc(in_file);
        if (ch == EOF)
            break;
        out_file << ch;
    }
}

int main()
{
    // The input file
    FILE *in_file = std::fopen("in.txt", "r");
    // The output file
    std::ofstream out_file("out.txt");

    // Check for errors
    if (in_file == NULL) {
        std::cerr <<
            "Error: Could not open input\n";
        exit (8);
    }
    if (out_file.bad()) {
        std::cerr <<
            "Error: Could not open output\n";
        exit (8);
    }
    // Copy data
    copy_it(in_file, out_file);

    // Finish output file
    std::fclose(in_file);
    return (0);
}
