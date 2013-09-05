#include <iostream>
#include <string>

using std::istream;
using std::ostream;

class Person {
public:
    Person() = default;
    Person(const std::string &name) : name(name) { }
    Person(const std::string &name, const std::string &address) :
           name(name), address(address) { }

    // These functions must be const because they do not change the object on
    // which they are called.
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

private:
    std::string name;
    std::string address;
};

istream &read(istream &is, Person &person)
{
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, const Person &person)
{
    os << person.getName() << " " << person.getAddress();
    return os;
}
