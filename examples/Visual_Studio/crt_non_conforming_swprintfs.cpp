/** Program to demonstrate the _CRT_NON_CONFORMING_SWPRINTFS macro.
 *
 * => "In Visual C++ 2005, swprintf conforms to the ISO C Standard, which
 * requires the second parameter, count, of type size_t. To force the old
 * nonstandard behavior, define _CRT_NON_CONFORMING_SWPRINTFS. In a future
 * version, the old behavior may be removed, so code should be changed to use
 * the new conformant behavior."
 *
 * => VS2012: "swprintf conforms to the ISO C Standard, which requires the
 * second parameter, count, of type size_t. To force the old nonstandard
 * behavior, define _CRT_NON_CONFORMING_SWPRINTFS. In a future version, the old
 * behavior may be removed, so code should be changed to use the new conformant
 * behavior."
 * 
 * References:
 *
 *   [1] https://msdn.microsoft.com/en-us/library/ybk95axf.aspx
 *
 * TODO: this is not finished and working yet.  Finish it!
 *
 */
#include <iostream>
#include <wchar.h>

int main()
{
   wchar_t buf[100];

   // ISO C Standard version.
   int len = swprintf( buf, 100, L"%s", L"Hello world" );

   std::cout << "Wrote " << len << " wide characters." << std::endl;

   len = wprintf(L"%s\n", buf);

   std::cout << "Wrote " << len << " wide characters." << std::endl;
}
