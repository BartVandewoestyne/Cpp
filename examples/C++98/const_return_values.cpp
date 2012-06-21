/**
 * Demonstrates constant return values.
 */

class Person {

  int age;

public:

  Person(int age_in = 0);
  void modify();

};


Person::Person(int age_in)
{
  age = age_in;
}


void Person::modify()
{
  age++;
}


Person getNewPerson() {
  return Person();
}


const Person getNewConstPerson() {
  return Person();
}


void makeOlder(Person& p) {
  p.modify();
}


int main() {

  /* These two are ok, because the return value of getNewPerson() is not const. */

  getNewPerson() = Person(25);
  getNewPerson().modify();


  /* These cause compile-time errors: */

  // "passing ‘const Person’ as ‘this’ argument of ‘Person& Person::operator=(const Person&)’ discards qualifiers"
  //getNewConstPerson() = Person(1);

  // "passing ‘const Person’ as ‘this’ argument of ‘void Person::modify()’ discards qualifiers"
  //getNewConstPerson().modify();

  // "invalid initialization of non-const reference of type ‘Person&’ from a temporary of type ‘Person’"
  //makeOlder(getNewPerson());

  // "invalid initialization of non-const reference of type ‘Person&’ from a temporary of type ‘const Person’"
  //makeOlder(getNewConstPerson());

}
