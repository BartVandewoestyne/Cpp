/**
 * Question: what does the following program do?
 */
#include <stdio.h>

int main()
{
    int flags = 0x5;    // Some sample flags

    printf("-parity\n" + ((flags & 0x1) != 0));
    printf("-break\n"  + ((flags & 0x2) != 0));
    printf("-xon\n"    + ((flags & 0x4) != 0));
    printf("-rts\n"    + ((flags & 0x8) != 0));
    return (0);
}
