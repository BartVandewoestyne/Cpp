/************************************************
 * copy -- Copy stdin to stdout.                *
 ************************************************/
#include <stdio.h>

int main()
{

    while (1)
    {
        int ch; // Character to copy

        ch = getchar();

        if (ch == EOF)
            break;

        putchar(ch);
    }
    return (0);
}
