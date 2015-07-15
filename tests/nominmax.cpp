/**
 * Illustrates the NOMINMAX problem on Windows.
 *
 * References:
 *
 *   [1] https://support.microsoft.com/en-us/kb/143208
 *   [2] http://binglongx.com/tag/nominmax/
 *   [3] http://www.suodenjoki.dk/us/archive/2010/min-max.htm
 */
#include <windows.h>
#include <algorithm>

void foo()
{
    // Without NOMINMAX, this gives a compiler error.  When
    // compiling with /D NOMINMAX, this compiles fine.
    int a = std::min(10, 20);

    // Another solution that works.
    int b = (std::min)(10, 20);
}
