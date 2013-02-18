/**
 * My own example to demonstrate that adding a class to a vector calls the copy
 * constructor.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/1693042/how-do-stl-containers-copy-objects
 *   [2] http://stackoverflow.com/questions/7382090/c-vector-push-back
 */

#include <iostream>
#include <vector>

class Foo {
public:
    Foo() { std::cout << "Foo()" << std::endl; }
    Foo(const Foo&) { std::cout << "Foo(const Foo&)" << std::endl; }
};


int main()
{
  Foo myFoo;

  std::vector<Foo> myVector;
  myVector.push_back(myFoo);  // Copy constructor called here!

  return 0;
}
