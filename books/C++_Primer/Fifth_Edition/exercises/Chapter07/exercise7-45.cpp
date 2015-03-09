// TODO: check if the default constructor for C is correct (see also exercise
// 7-43).

#include <iostream>
#include <vector>

using std::vector;

class Nodefault {
public:
    Nodefault(int i) { std::cout << "Nodefault(int)" << std::endl; }
};

class C {
public:

    C() : n(0)
      { std::cout << "C()" << std::endl; }

private:
    Nodefault n;
};

int main()
{
    // This works, because C has a default constructor.
    vector<C> vec(10);
}
