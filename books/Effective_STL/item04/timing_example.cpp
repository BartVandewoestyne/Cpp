#include <climits>
#include <ctime>
#include <iostream>
#include <list>
using std::list;

int main()
{
    list<int> myList;

    std::cout << "ULONG_MAX = " << ULONG_MAX << std::endl;
    const unsigned long int NB_ELEMENTS = 100000000;

    std::cout << "Adding " << NB_ELEMENTS << " elements to the list...";
    std::cout.flush();
    for (unsigned long int i = 1; i <= NB_ELEMENTS; ++i)
    {
        myList.push_back(i);
    }
    std::cout << " done." << std::endl;

    clock_t startTime;

    startTime = clock();
    myList.size() == 0;
    std::cout << "myList.size() == 0 took "
              << ( (clock()-startTime)/(double)CLOCKS_PER_SEC ) << " seconds."
              << std::endl;

    startTime = clock();
    myList.empty();
    std::cout << "myList.empty() took "
              << ( (clock()-startTime)/(double)CLOCKS_PER_SEC ) << " seconds."
              << std::endl;
}
