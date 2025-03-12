/*
 * Key idea:
 *
 *   In C++, the equals-sign-plus-braces syntax is usually treated the same as
 *   the braces-only version.
 *
 * References:
 *   [meyers201411] Effective Modern C++ - Item 7
 */

int main()
{
    int z1{0};
    int z2 = {0};  // usually treated the same as the braces-only version
}
