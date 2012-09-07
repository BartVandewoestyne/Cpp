/**
 * Answer: The printf call prints whatever string you give it.  If you add 1 to
 * a character string, you get the string minus the first character.  So:
 *
 *     printf("-xxx") prints -xxx
 *
 *     printf("-xxx" + 1) prints xxx
 *
 * The expression ((flags & 0x4) != 0) returns a 0 or 1 depending on whether
 * the bit is set.  The programmer is printing -word if the bit is
 * set ("-word" + 0).  The output is word if it is clear ("-word" + 1).
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
