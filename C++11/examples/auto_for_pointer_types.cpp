/*
 * References:
 *
 *   [gregoire20180706] const auto* versus const auto for Pointer Types
 *     http://www.nuonsoft.com/blog/2018/07/06/const-auto-versus-const-auto-for-pointer-types/
 *
 *   [stackoverflow20171114] Behavior of const auto pointers in C++
 *     https://stackoverflow.com/questions/47291244/behavior-of-const-auto-pointers-in-c
 *
 *   [stackoverflow20171109] How does const auto and auto const apply to pointers?
 *     https://stackoverflow.com/questions/47212317/how-does-const-auto-and-auto-const-apply-to-pointers
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

    // non-const pointer to const int (alternative)
    auto const *ip3 = &i;        // ip3 is of type const int*
    ++ip3;                       // OK, pointer is non-const
    *ip3 = 3;                    // error, int is const

    // const pointer to const int
    // (Note: you should probably just use a reference here...)
    const auto* const ip4 = &i;  // ip3 is of type const int* const
    ++ip4;                       // error, pointer is const
    *ip4 = 4;                    // error, int is const
}
