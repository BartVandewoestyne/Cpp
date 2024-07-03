/*
 * References:
 *
 *   https://www.geeksforgeeks.org/stdadjacent_find-in-c/
 */

#include <iostream>
#include <algorithm>
 
int main()
{
    // Sorted Array with a repeated element
    int A[] = { 10, 13, 16, 16, 18 };
 
    // Size of the array
    int n = sizeof(A) / sizeof(A[0]);
 
    // Iterator pointer which points to the address of the repeated element
    int* it = std::adjacent_find(A, A + n);
 
    // Printing the result
    std::cout << *it;
}
