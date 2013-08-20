#include "Chapter6.h"

int fact(int val)
{
    int ret = 1;  // local variable to hold the result as we calculate it.
    while (val > 1)
        ret *= val--;  // assign ret*val to ret and decrement val
    return ret;        // return the result
}
