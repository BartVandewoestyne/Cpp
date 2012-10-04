// compilers still need to know about these type
// names for the Person constructor
class string;      // again, see Item 49 for information
                   // on why this isn't correct for string
class Date;
class Address;
class Country;

// class PersonImpl will contain the implementation
// details of a Person object; this is just a
// forward declaration of the class name
class PersonImpl;

class Person {
public:
  Person(const string& name, const Date& birthday,
         const Address& addr, const Country& country);
  virtual ~Person();
 
                                    // copy ctor, operator=
  string name() const;
  string birthDate() const;
  string address() const;
  string nationality() const;
 private:
  PersonImpl *impl;                 // pointer to implementation
};
