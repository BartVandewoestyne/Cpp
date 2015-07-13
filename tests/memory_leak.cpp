/**
 * Create an artificial memory leak.
 *
 * TODO:
 *
 *   - improve this example
 */

#include <iostream>

int main()
{
    unsigned int nb_arrays = 10000;
    unsigned int arraysize = 10000;

    std::cout << "This program will allocate " <<  nb_arrays*arraysize*sizeof(int)/(1024) << " KB but never deallocate." << std::endl;

    // Create arrays of ints, but never delete the memory allocated for them.
    for (int i = 1; i <= nb_arrays; ++i)
    {
        int *p = new int[arraysize];
    }

    std::cin.ignore();
}
