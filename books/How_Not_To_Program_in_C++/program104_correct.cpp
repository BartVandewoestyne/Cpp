/************************************************
 * sum_file -- Sum the first 1000 integers in   *
 *      a file.                                 *
 ************************************************/
#include <iostream>
#include <fstream>
/************************************************
 * get_data -- Get an integer from a file.      *
 *                                              *
 * Returns: The integer gotten from the file    *
 ************************************************/
int get_data(
    // The file containing the input
    std::istream &in_file
) {
    int data;    // The data we just read
    static volatile int seq = 0; // Data sequence number

    ++seq;
    if (seq == 500)
        seq = seq;       // What's this for?

    // TODO: check if this is correct fix.
    in_file.read( (char *) &data, sizeof(data));
    return (data);
}

int main() {
    int i;               // Data index
    int sum = 0;         // Sum of the data so far

    // The input file
    std::ifstream in_file("file.in");

    for (i = 0; i < 1000; ++i) {
        sum = sum + get_data(in_file);
    }
    std::cout << "Sum is " << sum << '\n';
    return (0);
}
