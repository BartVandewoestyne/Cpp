/**
 * Example demonstrating how NOT to return a reference!
 *
 * References:
 *
 *   [1] C++ Primer, 5th edition, section '6.3 Return Types and the return
 *       Statement'.
 */

#include <string>
using namespace std;

const string& manip()
{
    string ret;

    // transform ret in some way

    if (!ret.empty()) {
        return ret;      // WRONG: returning a reference to a local object!
    }
    else
    {
        return "Empty";  // WRONG: "Empty" is a local temporary string.
    }
}
