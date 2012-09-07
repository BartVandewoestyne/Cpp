/************************************************
 * send_file -- Send a file to a remote link    *
 * (Stripped down for this example.)            *
 ************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>

// Size of a block
const int BLOCK_SIZE = 256;

/************************************************
 * send_block -- Send a block to the output port*
 ************************************************/
void send_block(
    std::istream &in_file,   // The file to read
    std::ostream &serial_out // The file to write
)
{
    int i;      // Character counter

    for (i = 0; i < BLOCK_SIZE; ++i) {
        int ch; // Character to copy

        ch = in_file.get();
        serial_out.put(ch);
        serial_out.flush();
    }
}

int main()
{
    // The input file
    std::ifstream in_file("file.in");

    // The output device (faked)
    std::ofstream out_file("/dev/null");

    if (in_file.bad())
    {
        std::cerr <<
            "Error: Unable to open input file\n";
        exit (8);
    }

    if (out_file.bad())
    {
        std::cerr <<
            "Error: Unable to open output file\n";
        exit (8);
    }

    while (! in_file.eof())
    {
      std::cout << "test\n" << std::endl;
        // The original program output
        // a block header here
        send_block(in_file, out_file);
        // The original program output a block
        // trailer here. It also checked for
        // a response and resent the block
        // on error
    }
    return (0);
}
