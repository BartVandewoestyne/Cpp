/*
 * My own example for static variables inside (member) functions.
 */

#include <iostream>

void foo()
{
    static int n = 10;
    ++n;
    std::cout << "n = " << n << "\n";
}

class Bar
{
public:
    void bar()
    {
        static int x = 100;
        ++x;
        std::cout << "x = " << x << "\n";
    }
};

int main()
{
    foo();
    foo();

    Bar b;
    b.bar();
    b.bar();
}
