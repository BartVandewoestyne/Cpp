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
 *   In constructor ‘Person::Person()’:
 *     error: no matching function for call to ‘Head::Head()’
 *     note:  candidates are:
 *     note:    Head::Head(std::string)
 *     note:      candidate expects 1 argument, 0 provided
 *     note:    Head::Head(const Head&)
 *     note:      candidate expects 1 argument, 0 provided
 *
 */
#include <iostream>
#include <string>
using namespace std;

class Head
{
  public:

    Head() { cout << "Head() called." << endl; }
    Head(string name) { cout << "Head(string name) called." << endl; }

};

class Person
{
  private:
    Head h;

  public:
    Person() { cout << "Person() called." << endl; }
};

int main()
{
  Person p;

  return 0;
}
