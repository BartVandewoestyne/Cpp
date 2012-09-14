#include <iostream>
#include <string>
using namespace std;

class Person {
public:
  Person() { cout << "Person()" << endl; }

  ~Person() { cout << "~Person()" << endl; }
 
private:
  string name, address;
};


class Student: public Person {
public:
  Student() { cout << "Student()" << endl; }
  ~Student() { cout << "~Student()" << endl; }
 
private:
  string schoolName, schoolAddress;
};


// Expensive version with pass by value.
//Student returnStudent(Student s) { return s; }

// Cheap version with pass by reference.
const Student& returnStudent(const Student& s) { return s; }

int main()
{
  cout << "Hello 1" << endl;

  Student plato;                      // Plato studied under Socrates

  cout << "Hello 2" << endl;
   
  returnStudent(plato);               // call returnStudent

  cout << "Hello 3" << endl;
}
