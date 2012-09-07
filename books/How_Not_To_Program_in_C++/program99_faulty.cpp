/*************************************************
 * delete_check -- Check to see if the file      *
 * delete.me exists and tell the user            *
 * to delete it if it does.                      *
 *************************************************/
#include <iostream>
#include <unistd.h>
#include <cstdio>

int main()
{
    // Test for the existence of the file
    if (access("delete.me", F_OK)) {
        bool remove = true;
    }
    if (remove) {
        std::cout <<
            "Please remove 'delete.me'\n";
    }
    return (0);
}
