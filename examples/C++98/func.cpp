/*
 * Program to illustrate how you can get the function name.
 *
 * Remark:
 *
 *   Visal Studio 2012 does not support this, 2015 does.  See
 *   http://stackoverflow.com/questions/15126387/func-c11-functions-local-predefined-variable-wont-compile
 */

#include <iostream>

void foo()
{
    std::cout << __func__ << std::endl;
    return;
}

int main()
{
    foo();
    return 0;
}
