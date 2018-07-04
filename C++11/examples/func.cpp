/*
 * Program to illustrate how you can get the function name.
 *
 * Remark:
 *
 *   Visal Studio 2012 does not support this, 2015 does.  See [2].
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/4384765/whats-the-difference-between-pretty-function-function-func
 *   [2] http://stackoverflow.com/questions/15126387/func-c11-functions-local-predefined-variable-wont-compile
 *
 * TODO:
 *   - Check if this is a C++98/03 or C++11/14 feature.  According to [1], it is a C++11 feature.
 */

#include <iostream>

class Foo {
public:
    void bar() { std::cout << __func__ << std::endl; }
};

void foo()
{
    std::cout << __func__ << std::endl;
}

int main()
{
    // Ordinary function.
    foo();

    // Class function.
    Foo f;
    f.bar();

    return 0;
}
