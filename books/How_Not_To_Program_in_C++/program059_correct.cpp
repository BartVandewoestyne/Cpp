/************************************************
 * test the tmp_name function.                  *
 ************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/param.h>
/************************************************
 * tmp_name -- return a temporary file name.    *
 *                                              *
 * Each time this function is called, a new     *
 *      name will be returned.                  *
 *                                              *
 * Returns                                      *
 *      Pointer to the new file name.           *
 ************************************************/
char *tmp_name(void)
{
    // The name we are generating
    static char name[MAXPATHLEN];

    // The directory to put the temporary file in
    const char DIR[] = "/var/tmp/tmp";

    // Sequence number for last digit
    static int sequence = 0;

    ++sequence; /* Move to the next file name */

    std::sprintf(name, "%s.%d", DIR, sequence);
    return(name);
}

int main()
{
    // The first temporary name
    char *a_name = tmp_name();
    char *a_name_copy;
    strcpy(a_name_copy, a_name); // TODO: not sure if this is correct solution...

    // The second temporary name
    char *b_name = tmp_name();

    std::cout << "Name (a): " << a_name_copy << std::endl;
    std::cout << "Name (b): " << b_name << std::endl;
    return(0);
}
