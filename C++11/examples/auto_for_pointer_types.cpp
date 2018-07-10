/*
 * References:
 *
 *   [gregoire20180706] const auto* versus const auto for Pointer Types
 *     http://www.nuonsoft.com/blog/2018/07/06/const-auto-versus-const-auto-for-pointer-types/
 *
 *   [stackoverflow20160101] C++11 auto declaration with and without pointer declarator
 *     https://stackoverflow.com/questions/34560365/c11-auto-declaration-with-and-without-pointer-declarator
 */

int main()
{
    int i = 0;

    // const pointer to non-const int
    const auto ip1 = &i;         // ip1 is of type int* const
    ++ip1;                       // error, pointer is const
    *ip1 = 1;                    // ok, int is non-const

    // non-const pointer to const int
    const auto* ip2 = &i;        // ip2 is of type const int*
    ++ip2;                       // OK, pointer is non-const
    *ip2 = 2;                    // error, int is const

    // const pointer to const int
    const auto* const ip3 = &i;  // ip3 is of type const int* const
    ++ip3;                       // error, pointer is const
    *ip3 = 3;                    // error, int is const
}
