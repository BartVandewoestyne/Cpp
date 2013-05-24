/**
 * References:
 *
 *   [1] http://stackoverflow.com/questions/14259602/default-values-in-c-initializer-lists
 */

#include <iostream>

class A {

public:
    A() : x(), y() {}

public:
    int x;
    double y;
};


int main()
{
    A myClass;

    std::cout << myClass.x << std::endl;
    std::cout << myClass.y << std::endl;
}
