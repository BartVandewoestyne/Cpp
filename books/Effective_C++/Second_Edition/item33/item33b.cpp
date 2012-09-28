#include <string>
using namespace std;

class Base {
public:
private:
  string bm1, bm2;    // base members 1 and 2
};

class Derived: public Base {
public:
  Derived() {}                  // Derived's ctor is
                                // empty -- or is it?
private:
  string dm1, dm2, dm3;         // derived members 1-3
};
