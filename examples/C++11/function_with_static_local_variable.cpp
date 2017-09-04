/*
 * My own test example to see how a local static variable inside
 * a std::function behaves.
 */

#include <functional>
#include <iostream>

void increment_counter()
{
    static int counter = 0;
    counter++;
    std::cout << counter << std::endl;
}

int main()
{
    std::function<void(void)> f = increment_counter;
    std::function<void(void)> g = increment_counter;

    f();  // Counter statically initialized to 0.
    g();  // Counter NOT again statically initialized to 0!
}
