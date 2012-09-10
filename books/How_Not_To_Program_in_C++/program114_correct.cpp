/************************************************
 * Sum -- This program sums the sine of the     *
 *      numbers from 1 to MAX. (For no good     *
 *      reason other than to have something     *
 *      to do that takes a long time.)          *
 *                                              *
 * Since this takes a long time, we have a      *
 * second thread that displays the progress of  *
 * the call.                                    *
 ************************************************/
#include <cstdio>
#include <cmath>
#include <pthread.h>
#include <stdlib.h>

/* Counter of what we've summed so far */
static volatile int counter;

/************************************************
 * status_monitor -- Monitor the status and     *
 *      tell the user how far things have       *
 *      progressed.                             *
 *                                              *
 * This thread merely waits for the user to     *
 * press <enter> and then reports the current   *
 * value of counter.                            *
 ************************************************/
static void *status_monitor(void *) {
    /* buffer to stuff that comes in */
    char buffer[3];

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        printf("Progress %d\n", counter);
        fflush(stdout);
    }
}

/************************************************
 * sum -- Sum the sine of the numbers from 0 to *
 *      0x3FFFFFFF.  Actually we don't care     *
 *      about the answer, all we're trying to   *
 *      do is create some sort of compute       *
 *      bound job so that the status_monitor    *
 *      can be demonstrated.                    *
 ************************************************/
static void sum(void) {
    static double sum = 0;       /* Sum so far */

    for (counter = 0;
         counter < 0x3FFFFFF;
         ++counter)
    {
        sum += sin(double(counter));
    }

    printf("Total %f\n", sum);
    exit (0);
}

int main() {
    // Status of last system call
    int status;

    // Information on the status thread
    pthread_t status_thread;

    status = pthread_create(&status_thread, NULL,
                status_monitor, NULL);

    if (status != 0) {
        perror(
            "ERROR: Thread create failed:\n   ");
        exit (8);
    }

    sum();

    return(0);
}
