#include <string>

struct Person {

    // These functions must be const because they do not change the object on
    // which they are called.
    std::string name() const { return name; }
    std::string address() const { return address; }

    std::string name;
    std::string address;
};
