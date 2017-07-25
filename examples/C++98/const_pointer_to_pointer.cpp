/*
 * My own example of constness for int** pointers.
 *
 * References:
 *   [1] https://isocpp.org/wiki/faq/const-correctness#constptrptr-conversion
 *   [2] https://stackoverflow.com/questions/4246445/const-qualifier-for-pointers-to-pointers
 */

int main()
{
    int x = 99;
    int *px = &x;

    {
      int a = 1;
      int* pa = &a;
      int** ppa = &pa;
      **ppa = 11;
    }

    {
      int a = 1;
      int* pa = &a;
      //const int** ppa = &pa;      // error: invalid conversion from 'int**' to 'const int**' [-fpermissive]
      const int* const* ppa = &pa;  // ok
      //**ppa = 11;                 // error: assignment of read-only location '*(const int*)(* ppa)'
      //*ppa = &x;                  // error: assignment of read-only location '* ppa'
      //ppa = &x;                   // error: cannot convert 'int*' to 'const int* const*' in assignment
      ppa = &px;                    // ok
    }

    {
      int a = 1;
      int* pa = &a;
      //const int** ppa = &pa;      // error: invalid conversion from 'int**' to 'const int**' [-fpermissive]
      const int* const* const ppa = &pa;  // ok
      //**ppa = 11;                 // error: assignment of read-only location '*(const int*)(* ppa)'
      //*ppa = &x;                  // error: assignment of read-only location '* ppa'
      //ppa = &x;                   // error: cannot convert 'int*' to 'const int* const*' in assignment
      //ppa = &px;                    // error: error: assignment of read-only variable 'ppa'
    }
}
