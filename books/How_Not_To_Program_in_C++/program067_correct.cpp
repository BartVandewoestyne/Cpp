/************************************************
 * Compute a simple average.  Because this      *
 * takes a long time (?) we output some         *
 * chatter as we progress through the system.   *
 ************************************************/
#include <stdio.h>

/************************************************
 * average -- Compute the average given the     *
 *      total of the series and the number      *
 *      of items in the series.                 *
 *                                              *
 * Returns:                                     *
 *      The average.                            *
 ************************************************/
int average(
    const int total,// The total of the series
    const int count // The number of items
)
{
    return (total/count);
}

int main()
{
    int ave;    // Average of the number

    printf("Starting....");
    fflush(stdout);
    ave = average(32, 0);
    printf("..done\n");

    printf("The answer is %d\n", ave);
    return (0);
}
