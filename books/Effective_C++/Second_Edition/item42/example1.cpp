class Person { };
 
class Student:                      // this time we use
  private Person { };               // private inheritance
 
void dance(const Person& p);        // anyone can dance
void study(const Student& s);       // only students study
 
int main()
{
  Person p;                           // p is a Person
  Student s;                          // s is a Student
   
  dance(p);                           // fine, p is a Person

  dance(s);                           // error! a Student isn't
                                      // a Person
}
