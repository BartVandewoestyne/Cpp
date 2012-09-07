/************************************************
 * Print a bunch of greetings.                  *
 ************************************************/
#include <iostream>

#define MAX 10

int main()
{
    int counter;        // Current greeting

    for (counter =MAX; counter > 0; --counter)
        std::cout <<"Hi there\n";

    return (0);
}
