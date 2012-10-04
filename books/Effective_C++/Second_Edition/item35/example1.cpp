class Person {};

class Student : public Person {};

void dance(const Person& p);        // anyone can dance

void study(const Student& s);       // only students study


int main()
{
  Person p;                           // p is a Person
  Student s;                          // s is a Student
  
  dance(p);                           // fine, p is a Person
  
  dance(s);                           // fine, s is a Student,
                                      // and a Student isa Person
  
  study(s);                           // fine
  
  //study(p);                           // error! p isn't a Student
}
