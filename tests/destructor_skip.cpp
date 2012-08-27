/**
 * References:
 *
 *   [1] http://efesx.com/2012/07/31/unexpected-skip-of-a-destructor/
 */
#include <iostream>
#include <stdexcept>

struct A {
  A() { std::cout << "A" << std::endl; }
  ~A() { std::cout << "~A" << std::endl; }
};

void myfunc () {
  A temp;
  throw std::runtime_error("moo");
}

int main () {
  myfunc();
}
