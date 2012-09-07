/************************************************
 * copy input file to output file.              *
 ************************************************/
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fcntl.h>

int main() {
    // The fd of the input file
    int in_fd = open("file.in", O_RDONLY);

    // The fd of the output file
    int out_fd = open("file.out",
            O_WRONLY|O_CREAT, 0666);

    char ch;     // Character to copy

    if (in_fd < 0) {
        std::cout <<
            "Error could not open input file\n";
        exit(8);
    }

    if (out_fd < 0) {
        std::cout <<
            "Error could not open output file\n";
        exit(8);
    }

    // We now read 100 characters instead of 1 to speed
    // things up.  We could have also used fstreams instead
    // of file descriptors to speed things up.
    while (1) {
        if (read(in_fd, &ch, 100) != 1)
            break;

        write(out_fd, &ch, 100);
    }
    close(in_fd);
    close(out_fd);
    return (0);
}
