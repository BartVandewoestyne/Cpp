/**
 * The problem with this code is the following (from the book):
 *
 * The initialization of log_file can call new. Of course, our new new uses the
 * log_file, so the log_file may be used before it gets constructed, confusing
 * the whole mess.
 */

/************************************************
 * simple debugging library that overrides the  *
 * standard new and delete operators so that we *
 * log all results.                             *
 ************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>

// Define the file to write the log data to
std::ofstream log_file("mem.log");

/************************************************
 * operator new -- Override the system new so   *
 *      that it logs the operation.  This is    *
 *      useful for debugging.                   *
 *                                              *
 * Note: We have verified that the real new     *
 *      calls malloc on this system.            *
 *                                              *
 * Returns a pointer to the newly created area. *
 ************************************************/
void *operator new(
    // Size of the memory to allocate
    const size_t size
)
{
    // Result of the malloc
    void *result = (void *)malloc(size);

    log_file <<
        result << " =new(" <<
        size << ")" << std::endl;

    return (result);
}

/************************************************
 * operator delete -- Override the system       *
 *      delete to log the operation.   This is  *
 *      useful for debugging.                   *
 *                                              *
 * Note: We have verified that the real delete  *
 *      calls free on this system.              *
 ************************************************/
void operator delete(
    void *data // Data to delete
)
{
    log_file << data << " Delete" << std::endl;
    free (data);
}

// Dummy main
int main()
{
    return (0);
}
