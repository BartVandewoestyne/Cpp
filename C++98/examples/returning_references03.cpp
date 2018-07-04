/**
 * Example function that returns a reference to the shorter of its two string
 * parameters.
 *
 * References:
 *
 *   [1] C++ Primer, 5th edition, section '6.3 Return Types and the return
 *       Statement'.
 */

#include <string>
using namespace std;

const string& shorterString(const string& s1, const string& s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
