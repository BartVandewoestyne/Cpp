/*
 * References:
 *
 *   [boccara20190723] https://www.fluentcpp.com/2019/07/23/how-to-define-a-global-constant-in-cpp/
 *     https://www.fluentcpp.com/2019/07/23/how-to-define-a-global-constant-in-cpp/
 */

#include <iostream>

class X
{
public:
    X() { std::cout << "X constructed\n"; }
};

const X x;
