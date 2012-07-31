/************************************************
 * buffer demo.  Show how big buffers can speed *
 * up I/O.                                      *
 ************************************************/
#include <stdio.h>

/* Nice big buffer */
#define BUF_SIZE  (50 * 1024)

/************************************************
 * print_stuff -- Print a bunch of stuff in a   *
 *      big buffer.                             *
 ************************************************/
void print_stuff(void)
{
    // Buffer to hold the data
    static char buffer[BUF_SIZE];

    // Printing counter.
    int i;

    /* Things go much faster with this */
    setbuf(stdout, buffer);

    for (i = 0; i < 10; ++i)
        printf("Hello world\n");
}


int main()
{
    print_stuff();
    printf("That's all\n");
    return (0);
}
