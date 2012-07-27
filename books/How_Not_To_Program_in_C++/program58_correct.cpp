/************************************************
 * tmp_test -- test out the tmp_name function.  *
 ************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sys/param.h>
/************************************************
 * tmp_name -- return a temporary file name     *
 *                                              *
 * Each time this function is called, a new     *
 *      name will be returned.                  *
 *                                              *
 * Returns: Pointer to the new file name.       *
 ************************************************/
char *tmp_name(void) {
    // The name we are generating
    static char name[MAXPATHLEN];

    // The base of the generated name
    const char DIR[] = "/var/tmp/tmp";

    // Sequence number for last digit
    static int sequence = 0;

    ++sequence; /* Move to the next file name */

    sprintf(name, "%s.%d", DIR, sequence);
    return(name);
}
int main() {
    char *a_name = tmp_name();  // A tmp name
    std::cout << "Name: " << a_name << std::endl;
    return(0);
}
