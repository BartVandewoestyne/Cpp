/*
 * Answer:
 *
 *   As long as p1 and p2 are valid pointers into the array, this should work???
 *
 * TODO: check this!
 */
#include <iostream>

int main()
{
    int a[] = { 0, 1, 2, 3, 4 };

    int *p1 = &a[0];
    int *p2 = &a[4];

    p1 += p2 - p1;

    std::cout << "*p1 = " << *p1 << std::endl;
    std::cout << "*p2 = " << *p2 << std::endl;
}
