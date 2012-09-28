class Address {};

class Person {

public:

  Address& personAddress() { return address; }

private:

  Address address;

};

int main()
{
  Person scott;
  Address& addr = scott.personAddress();
}
