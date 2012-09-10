/************************************************
 * flag -- Demonstrate the use of flag setting  *
 *      and clearing.  This is a demonstration  *
 *      program that does not run in real life. *
 *      But it is a good example of a very tiny *
 *      part of the code in a terminal driver.  *
 ************************************************/
#include <cstdio>
#include <stdlib.h>
#include <pthread.h>


const char XOFF = 'S' - '@';// Turns off output
const char XON = '0' - '@'; // Turns on output

static int flags = 0; // State flags
//
// ^S in effect
const int STOP_OUTPUT = (1 << 0);

// CD is present
const int CD_SIGNAL   = (1 << 1);

/***********************************************
 * read_ch -- read a single character.         *
 *                                             *
 * Returns the character read.                 *
 ***********************************************/
static char read_ch(void)
{
    // Dummy function
    return ('x');
}

/************************************************
 * write_ch -- write a character to the output  *
 *              (Whatever that is.)             *
 ************************************************/
static void write_ch(const char ch)
{
    // Dummy function
}
/************************************************
 * do_input -- handle the reading and           *
 *      processing of characters.               *
 ************************************************/
static void *do_input(void *)
{
    while (1)
    {
        char ch;         // Character we just read

        ch = read_ch();

        switch (ch) {
            case XOFF:
                flags |= STOP_OUTPUT;
                break;
            case XON:
                flags &= ~STOP_OUTPUT;
                break;
            default:
                write_ch(ch);
                break;
        }
    }
}

/************************************************
 * wait_for_cd_change -- wait for the CD signal *
 *      to change and return the value of the   *
 *      signal.                                 *
 ************************************************/
static int wait_for_cd_change(void)
{
    // Dummy
    return (1);
}
/***********************************************
 * do_signals -- Monitor signals and set flags *
 *      based on the signal changes.           *
 ***********************************************/
void do_signals(void)
{
    while (1) {
        // The current cd level
        int level = wait_for_cd_change();
        if (level) {
            flags |= CD_SIGNAL;
        } else {
            flags &= ~CD_SIGNAL;
        }
    }
}

int main()
{
    int status; // Status of last system call

    // Information on the status thread
    pthread_t input_thread;

    status = pthread_create(&input_thread,
                NULL, do_input, NULL);

    if (status != 0) {
        perror(
            "ERROR: Thread create failed:\n   ");
        exit (8);
    }

    do_signals();
    return(0);
}
