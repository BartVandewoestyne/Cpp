/**
 * Since ca is not null-terminated, the while loop continues until 'by accident'
 * it encounters a zero at the address of cp.  So some junk is printed after
 * "hello".
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp << endl;
        ++cp;
    }
}
