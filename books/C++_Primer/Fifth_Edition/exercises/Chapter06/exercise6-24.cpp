/**
 * TODO:
 *   Check this!
 *
 * Possible problems:
 *   1. This function can only be called for arrays of 10 ints.
 *   2. Better to pass a reference to the array?
 */
#include <iostream>
using namespace std;

void print(const int ia[10])
//void print(const int (&ia)[10])  // Better pass it as a reference?
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

int main()
{
    int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(ia);
}
