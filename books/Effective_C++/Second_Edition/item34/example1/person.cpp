#include <string>           // for type string (see Item 49)
#include "date.h"
#include "address.h"
#include "country.h"
#include "person.h"
using namespace std;

Person::Person(const string& name, const Date& birthday,
               const Address& addr, const Country& country)
  : name_(name), birthDate_(birthday), address_(addr), citizenship_(country)
{}

Person::~Person() {};

// TODO: copy constructor and assignment operator.

string Person::name() const
{
  return name_;
}

string Person::birthDate() const
{
  //return birthDate_;
  return "birthdate";
}

string Person::address() const
{
  //return address_;
  return "address";
}

string Person::nationality() const
{
  //return citizenship_;
  return "citizenship";
}
