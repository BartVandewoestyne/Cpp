#include <cstdio>
#include <stdlib.h>
#include <pthread.h>
#include <sys/fcntl.h>

// Resource protection mutexes
static pthread_mutex_t resource1 =
        PTHREAD_MUTEX_INITIALIZER;

static pthread_mutex_t resource2 =
        PTHREAD_MUTEX_INITIALIZER;

/************************************************
 * A couple of routines to do work.   Or they    *
 *      would do work if we had any to do.      *
 ***********************************************/
static void wait_for_work(void) {}      // Dummy
static void do_work(void) {}            // Dummy

/***********************************************
 * process_1 -- First process of two.          *
 *                                             *
 * Grab both resources and then do the work    *
 ***********************************************/
static void *process_1(void *)
{
    while (1) {
        wait_for_work();

        pthread_mutex_lock(&resource1);
        pthread_mutex_lock(&resource2);

        do_work();

        pthread_mutex_unlock(&resource2);
        pthread_mutex_unlock(&resource1);
    }
}

/************************************************
 * process_2 -- Second process of two.          *
 *                                              *
 * Grab both resources and then do the work.    *
 *      (but slightly different work from       *
 *      process_1)                              *
 ************************************************/
static void process_2(void)
{
    while (1) {
        wait_for_work();

        pthread_mutex_lock(&resource1);
        pthread_mutex_lock(&resource2);

        do_work();

        pthread_mutex_unlock(&resource2);
        pthread_mutex_unlock(&resource1);
    }
}

int main()
{
    int status; /* Status of last system call */

    /* Information on the status thread */
    pthread_t thread1;

    status = pthread_create(&thread1,
            NULL, process_1, NULL);

    if (status != 0) {
        perror(
            "ERROR: Thread create failed:\n   ");
        exit (8);
    }

    process_2();
    return (0);
}
