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
  }

};

int main()
{
  Person p;       // calls Person() constructor

  Person c(p);    // direct initialization!!!

  Person d = p;   // copy initialization!!!  Note that copy constructor is
                  // called here!

  p = c;          // calls operator=()
}
