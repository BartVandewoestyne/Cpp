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
    printf("Hello ");
    fork();
    printf("\n");
    exit(0);
}
