/*
 * Illustrates the following from the C99 standard:
 *
 *   "A declaration of a parameter as ``array of type'' shall be adjusted to
 *   ``qualified pointer to type'', [...]"
 *
 * References:
 *
 *   [1] ISO/IEC 9899:1999 6.7.5.3/7.
 *   [2] http://stackoverflow.com/questions/3062005/size-of-array-passed-to-c-function
 *   [3] http://stackoverflow.com/questions/968001/determine-size-of-array-if-passed-to-function
 *   [4] http://stackoverflow.com/questions/16144535/difference-between-passing-array-fixed-sized-array-and-base-address-of-array-as
 */

#include <iostream>

void f1(int* x)
{
    std::cout << "f2(int* x) => sizeof(x) = " << sizeof(x) << std::endl;
}

void f2(int x[])
{
    std::cout << "f2(int x[]) => sizeof(x) = " << sizeof(x) << std::endl;
}

void f3(int x[5])
{
    std::cout << "f3(int x[5]) => sizeof(x) = " << sizeof(x) << std::endl;
}

int main()
{
    int a[10];

    std::cout << "main() => sizeof(a) = " << sizeof(a) << std::endl;

    f1(a);
    f2(a);
    f3(a);
}
