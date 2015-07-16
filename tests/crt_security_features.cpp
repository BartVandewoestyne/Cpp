/**
 * Program to illustrate security features in the CRT.
 *
 * To see the warnings, compile with /Wall.  Note that using /Wall
 * will also generate quite some C4514 warnings for string.h... ignore these.
 *
 * References:
 *
 *   [1] https://msdn.microsoft.com/en-us/library/8ef0s5kh.aspx
 *
 */
#include <cstring>

int main()
{
    char szBuf[10];

    strcpy(szBuf, "test");    // warning: deprecated 

    strcpy_s(szBuf, "test");  // no warning

    return 0;
}
