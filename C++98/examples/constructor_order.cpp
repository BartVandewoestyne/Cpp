/**
 * Example demonstrating in what order and how constructors get called.
 *
 * From the moment we leave in the Head() constructor, everything is fine and
 * we get the output:
 *
 *   Head() called.
 *   Person() called.
 * 
 * Leaving out the Head() constructor results in:
 *
 *   In constructor 'Person::Person()':
 *     error: no matching function for call to 'Head::Head()'
 *     note:  candidates are:
 *     note:    Head::Head(std::string)
 *     note:      candidate expects 1 argument, 0 provided
 *     note:    Head::Head(const Head&)
 *     note:      candidate expects 1 argument, 0 provided
 *
 */
#include <iostream>
#include <string>

class Head
{
  public:

    Head() { std::cout << "Head()" << std::endl; }
    Head(const std::string& name) { std::cout << "Head(const string&)" << std::endl; }

};

class Person
{
  private:
    Head h;

  public:
    Person() { std::cout << "Person()" << std::endl; }
};

int main()
{
  Person p;

  return 0;
}
