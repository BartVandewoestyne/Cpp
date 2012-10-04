/**
 * TODO: get this to compile...
 */
#include <string>
using namespace std;

#include "Person.h"          // because we're implementing
                             // the Person class, we must
                             // #include its class definition

#include "PersonImpl.h"      // we must also #include
                             // PersonImpl's class definition,
                             // otherwise we couldn't call
                             // its member functions. Note
                             // that PersonImpl has exactly
                             // the same member functions as
                             // Person; their interfaces
                             // are identical

Person::Person(const string& name, const Date& birthday,
               const Address& addr, const Country& country)
{
  impl = new PersonImpl(name, birthday, addr, country);
}

string Person::name() const
{
  return impl->name();
}
