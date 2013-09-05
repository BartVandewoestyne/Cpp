#include <iostream>
#include <string>

using std::istream;
using std::ostream;

struct Person {

    // These functions must be const because they do not change the object on
    // which they are called.
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

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
