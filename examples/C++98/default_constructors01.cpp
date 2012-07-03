/**
 * This example shows that no default constructor is provided if you define
 * other constructors with arguments.
 *
 * References:
 *
 *   `Professional C++, 2nd Edition', page 149.
 */

#include <iostream>
using namespace std;

class Person {

public:

  // Default constructor, no arguments.
  // If you comment this constructor out, then you will see that
  // the compiler does not automatically generates one for you!
  Person() {
    cout << "Default constructor called." << endl;
  };


  // Constructor with argument.
  Person(int age) {
    cout << "Constructor with age argument called." << endl;
  };

};


int main() {

  // If the default constructor is not explicitly declared (commented out),
  // then this results in the error:
  // 
  //   error: no matching function for call to ‘Person::Person()’
  //   note: candidates are: Person::Person(int)
  //   note:                 Person::Person(const Person&)
  //
  Person p1;

  // This works.
  Person p2(30);

}
