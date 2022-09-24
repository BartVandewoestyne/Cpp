/*
 * References:
 *
 *   [wikipedia] Copy constructor (C++) - Examples - User-defined copy constructor
 *     https://en.wikipedia.org/wiki/Copy_constructor_(C%2B%2B)#User-defined_copy_constructor
 */

#include <iostream>

struct Person {

  Person() {
    std::cout << "Person()" << std::endl;
  }

  Person(const Person& param) {
    std::cout << "Person(const Person&)" << std::endl;
  }

  Person& operator=(const Person& rhs) {
    std::cout << "operator=()" << std::endl;
    return *this;
  }

};

Person createPerson()
{
    std::cout << "At start of createPerson()." << std::endl;

    Person p;

    std::cout << "Right before return statement in createPerson()." << std::endl;

    return p;
}

int main()
{
  std::cout << "=> Person p;" << std::endl;
  Person p;       // calls Person() constructor

  std::cout << "=> Person c(p);" << std::endl;
  Person c(p);    // direct initialization!!!

  std::cout << "=> Person d = p;" << std::endl;
  Person d = p;   // copy initialization!!!  Note that copy constructor is
                  // called here!

  std::cout << "=> p = c;" << std::endl;
  p = c;          // calls operator=()

  // Note that some compilers will call the copy constructor here, while
  // others don't (these probably use RVO???)
  std::cout << "=> p2 = createPerson();" << std::endl;
  Person p2 = createPerson();
}
