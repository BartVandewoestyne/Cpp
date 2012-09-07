/*************************************************
 * delete_check -- Check to see if the file      *
 * delete.me exists and tell the user            *
 * to delete it if it does.                      *
 *************************************************/
#include <iostream>
#include <unistd.h>
//#include <cstdio> // including this brings the 'remove' function into scope.

int main()
{
    bool remove_it = false;

    // Test for the existence of the file.
    //
    // NOTE BART:
    // on success (if delete.me exists), the access function returns a zero!!!
    // This bug is not mentioned in the solution of the book!!!
    if (!access("delete.me", F_OK)) {
        remove_it = true;
    }
    if (remove_it) {
        std::cout <<
            "Please remove 'delete.me'\n";
    }
    return (0);
}
