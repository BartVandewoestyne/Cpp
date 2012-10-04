#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "date.h"
#include "address.h"
#include "country.h"
using namespace std;

class Person {
public:
  Person(const string& name, const Date& birthday,
         const Address& addr, const Country& country);
  virtual ~Person();
 
                           // copy constructor and assignment
                           // operator omitted for simplicity
  string name() const;
  string birthDate() const;
  string address() const;
  string nationality() const;
 private:
  string name_;            // implementation detail
  Date birthDate_;         // implementation detail
  Address address_;        // implementation detail
  Country citizenship_;    // implementation detail
};

#endif /* PERSON_H */
