/*
 * Illustrates that flowing off the end of a function results in undefined
 * behavior in a value-returning function.
 *
 * References:
 *   [1] http://stackoverflow.com/questions/1610030/why-does-flowing-off-the-end-of-a-non-void-function-without-returning-a-value-no
 */

#include <iostream>

class Foo {
public:
  int getX() {};  // note that we forgot to return the int!
};

int main()
{
    Foo f;
    std::cout << f.getX() << std::endl;  // undefined behavior
}
