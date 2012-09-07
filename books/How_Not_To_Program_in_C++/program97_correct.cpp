/************************************************
 * Normally I would put in a comment explaining *
 * what this program is nominally used for.     *
 * But in this case I can figure out no         *
 * practical use for this program.              *
 ************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    // The problem was that when the fork occurs, there is data in the printf
    // buffer.  The fork creates two copies of the process and two copies of the
    // data in the printf buffer.  Thus, when the buffer was flushed later (in
    // both processes) we got a Hello from each of them.

    printf("Hello ");
    fflush(NULL);
    fork();
    printf("\n");
    exit(0);
}
