/*************************************************
 * A small part of a set of routines to          *
 * download music to a RIO mp3 player.           *
 *                                               *
 * Full sources for the original can be found    *
 *      at http://www.oualline.com.              *
 *                                               *
 * This just tests the writing of the end of     *
 * block structure to the device.                *
 *************************************************/

#include <stdio.h>
/*
 * The 16 byte end of block structure for a Rio.
 *    (We'd label the fields if we knew what they
 *    were.)
 */
struct end_block_struct
{
    unsigned long int next_512_pos;    // [0123]
    unsigned char next_8k_pos1;        // [4]
    unsigned char next_8k_pos2;        // [5]

    unsigned long int prev_251_pos;    // [6789]
    unsigned char prev_8k_pos1;        // [10]
    unsigned char prev_8k_pos2;        // [11]

    unsigned short check_sum;          // [12,13]
    unsigned short prev_32K_pos;       // [14,15]
};

/*
 * Macro to print offset of the
 * field in the structure
 */
#define OFFSET(what) \
     printf(#what "     %d\n", int(&ptr->what));

int main()
{
    // A structure for debugging the structure
    struct end_block_struct *ptr = NULL;

    printf("Structure size %d\n",
            sizeof(end_block_struct));

    // TODO: fix this one!
    // The problem is that the size of the pointers on my 64 bit system
    // is 8 bytes, while an int is only 4 bytes, so casting to an int loses
    // information!!!

    //printf("sizeof(long unsigned int*) = %d\n", sizeof(long unsigned int*));
    //printf("sizeof(int) = %d\n", sizeof(int));

    OFFSET(next_512_pos);
    OFFSET(next_8k_pos1);
    OFFSET(next_8k_pos2);

    OFFSET(prev_251_pos);
    OFFSET(prev_8k_pos1);
    OFFSET(prev_8k_pos2);

    OFFSET(check_sum);
    OFFSET(prev_32K_pos);
    return (0);
}
