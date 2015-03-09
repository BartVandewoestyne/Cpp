// TODO: check if this is correct.

#include<iostream>

class Nodefault {
public:
    Nodefault(int i) { std::cout << "Nodefault(int)" << std::endl; }
};

class C {
public:

    // I think the default constructor for C must choose a default integer value for
    // Nodefault, because Nodefault needs this (it cannot be default constructed
    // without such a value).
    C() : n(0)
      { std::cout << "C()" << std::endl; }

private:
    Nodefault n;
};

int main()
{
    C c;
}
