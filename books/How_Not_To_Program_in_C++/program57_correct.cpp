// TODO: make this portable code.

#include <iostream>

/*
 * A data structure consisting of a flag
 * which indicates which long int parameter
 * follows.
 */
struct data
{
    // Flag indicating what's to follow
    char flag;

    // Value of the parameter
    long int value;
};

/************************************************
 * read_data -- Read data from the given file   *
 ************************************************/
void read_data(
  std::istream &in_file,     // File to read
  struct data &what     // Data to get
)
{
    in_file.read(
        dynamic_cast<char *>(&what),
        sizeof(what));
}
