/************************************************
 * bit test -- Test the routine to print out    *
 *      the bits in a flag.                     *
 ************************************************/
#include <iostream>
/************************************************
 * bit_out -- print a graphical                *
 *      representation of  each bit in a        *
 *      16 bit word.                            *
 *                                              *
 * For example:                                 *
 *      0×55AF will print -X-X-X-XX-X-XXXX      *
 ************************************************/
void bit_out(
    const short int value       // Value to print
)
{
    // The bit we are printing now
    short int bit = (1<<16);

    int count;                  // Loop counter

    for (count = 0; count < 16; ++count)
    {
        if ((bit & value) != 0)
            std::cout << "X";
        else
            std::cout << '-';
        bit >>= 1;
    }
    std::cout << std::endl;
}
int main()
{
    bit_out(0x55AF);
    return (0);
}
