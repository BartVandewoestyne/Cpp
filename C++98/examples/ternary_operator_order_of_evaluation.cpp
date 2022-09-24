/*
 * References:
 *
 *   [boccara20170509] How Compact Code Can Become Buggy Code: Getting Caught By The Order of Evaluations
 *     http://www.fluentcpp.com/2017/05/09/compact-code-becomes-buggy-code-order-evaluations/
 */

#include <iostream>

void a()
{
    std::cout << "a()" << std::endl;
}

void b()
{
    std::cout << "b()" << std::endl;
}

int main()
{
    true  ? a() : b();
    false ? a() : b();
}
