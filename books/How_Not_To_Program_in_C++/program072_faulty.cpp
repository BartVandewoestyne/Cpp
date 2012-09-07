/************************************************
 * copy -- Copy stdin to stdout.                *
 ************************************************/
#include <stdio.h>

int main()
{
    // Character to copy
    char ch;

    while ((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
    return (0);
}
