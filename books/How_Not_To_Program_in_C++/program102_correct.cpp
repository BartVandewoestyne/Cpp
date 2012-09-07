/**
 * The zip code 44101 is too large for MS-DOS's 16-bit integer.  The largest
 * number a 16-bit integer can hold is 32767.  The result is that the number
 * overflows into the sign bit, and things go wrong.
 *
 * Note:
 * Win32 systems use 32-bit integers, so this problem does not occur on the
 * current versions of Microsoft Windows.
 */

/********************************************
 * Check a couple of zip codes.             *
 ********************************************/
#include <iostream>

int main()
{
    // A couple of zip codes
    const int cleveland_zip   = 44101;
    const int pittsburgh_zip  = 15201;

    if (cleveland_zip < pittsburgh_zip)
    {
        std::cout <<
            "Cleveland < Pittsburgh (Wrong)\n";
    }
    else
    {
        std::cout <<
            "Pittsburgh < Cleveland (Right)\n";
    }

    return (0);
}
