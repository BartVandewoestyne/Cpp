/*
 * TODO: check if this program really works and does what it is intended to do.
 *
 * References:
 *
 *   [stackoverflow] Maximum memory that can be allocated dynamically and at compile time in c++
 *     http://stackoverflow.com/questions/13074689/maximum-memory-that-can-be-allocated-dynamically-and-at-compile-time-in-c
 */

#include <cstddef>
#include <iostream>
#include <new>

int main()
{
    bool atMaximum = false;
    unsigned long long nbBytesAllocated = 0;
    
    do {
       char *test = NULL;
       try {
           test = new char[1]();
           nbBytesAllocated++;
       } catch(const std::bad_alloc& e) {
           atMaximum = true;
       }
    } while (!atMaximum);

    std::cout << "Maximum number of bytes allocated: " << nbBytesAllocated << std::endl;
}
