/***********************************************
 * Starts two threads                          *
 *                                             *
 *      1) Reads data from /dev/input and puts *
 *              it into a buffer.              *
 *                                             *
 *      2) Takes data from the buffer and      *
 *              writes the data to /dev/output.*
 ***********************************************/
#include <cstdio>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/fcntl.h>

static const int BUF_SIZE = 1024;      // Buffer size
static char buffer[BUF_SIZE];          // The data buffer

// Pointer to end of buffer
static char *end_ptr = buffer + BUF_SIZE;

// Next character read goes here
static char *in_ptr = buffer;

// Next character written comes from here
static char *out_ptr = buffer;

static int count = 0;           // Number of characters in the buffer

/***********************************************
* reader -- Read data and put it in the global *
*      variable buffer.   When data is         *
*      installed the variable count is         *
*      increment and the buffer pointer        *
*      advanced.                               *
************************************************/
static void *reader(void *) {
    // File we are reading
    int in_fd = open("/dev/input", O_RDONLY);

    pthread_mutex_t buffer_mutex;

    while (1) {
        char ch; // Character we just got

        while (count >= BUF_SIZE)
            sleep(1);

        read(in_fd, &ch, 1);

        pthread_mutex_lock(&buffer_mutex);

        ++count;
        *in_ptr = ch;
        ++in_ptr;

        pthread_mutex_unlock(&buffer_mutex);

        if (in_ptr == end_ptr)
            in_ptr = buffer;
    }
}

/***********************************************
 * writer -- Write data from the buffer to     *
 *      the output device.   Gets the data     *
 *      from the global buffer. Global variable*
 *      count is decrement for each character  *
 *      taken from the buffer and the buffer   *
 *      pointer advanced.                      *
 ***********************************************/
static void writer(void)
{
    // Device to write to
    int out_fd = open("/dev/output", O_RDONLY);

    while (1) {
        char ch;        // Character to transfer

        while (count <= 0)
            sleep(1);

        ch = *out_ptr;

        --count;
        ++out_ptr;

        if (out_ptr == end_ptr)
            out_ptr = buffer;

        write(out_fd, &ch, 1);
   }
}

int main() {
    int status; /* Status of last system call */

    /* Information on the status thread */
    pthread_t reader_thread;

    status = pthread_create(&reader_thread, NULL, reader, NULL);

    if (status != 0) {
        perror("ERROR: Thread create failed:\n       ");
        exit (8);
   }

   writer();
   return (0);
}
