class Address {};

class Person;

// PPMF = "pointer to Person member function"
typedef void (Person::*PPMF)();

class Person {

public:

  Address * personAddress() { return &address; }

  static PPMF verificationFunction()
  { return &Person::verifyAddress; }

private:

  Address address;
  void verifyAddress() {};

};


int main()
{
  Person scott;
  Address *addrPtr = scott.personAddress();

  PPMF pmf = scott.verificationFunction();
  (scott.*pmf)(); // same as calling scott.verifyAddress
}
