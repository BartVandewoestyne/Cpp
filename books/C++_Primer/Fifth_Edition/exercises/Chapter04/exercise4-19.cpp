/**
 * TODO: check these answers!
 */

#include <vector>

using std::vector;

int main()
{
    int ival = 1;
    int *ptr = &ival;
    vector<int> vec = {1, 2, 3};

    // (a) This first checks whether the pointer is a nullpointer or not, and
    // then checks whether the integer to which ptr points is zero or not.
    // Once this check is done, ptr gets incremented (and points to something
    // strange???)
    ptr != 0 && *ptr++;

    // (b) This first increments ival, and then applies a logical AND with the
    // new value.
    ival++ && ival;

    // (c) It is not sure in what order these will be evaluated, so undefined
    // behavior.
    vec[ival++] <= vec[ival];
}
