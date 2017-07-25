/*
 * My own example of constness for Foo** pointers.
 *
 * References:
 *   [1] https://isocpp.org/wiki/faq/const-correctness#constptrptr-conversion
 */

int main()
{
    int a = 1;
    int* pa = &a;
    int** ppa = &pa;
    **ppa = 11;

    int b = 2;
    int* pb = &b;
    //const int** ppb = &pb;      // error: invalid conversion from 'int**' to 'const int**' [-fpermissive]
    const int* const* ppb = &pb;  // ok
    //**ppb = 22;                 // error: assignment of read-only location '*(const int*)(* ppb)'
    //*ppb = &a;                  // error: assignment of read-only location '* ppb'
    //ppb = &a;                   // error: cannot convert 'int*' to 'const int* const*' in assignment
    ppb = &pa;                    // ok
}
