#include <string>
using namespace std;

class Address { };           // where someone lives

class PhoneNumber { };

class Person {
public:
private:
  string name;                   // layered object
  Address address;               // ditto
  PhoneNumber voiceNumber;       // ditto
  PhoneNumber faxNumber;         // ditto
};
