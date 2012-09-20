// TODO: 'fix' this code so we indeed see the potential ambiguity error when
//       compiling.

#include <iostream>
using namespace std;

// Forward declaration for class B.
class B;

class A {
public:
  // An A can be constructed from a B.
  A(const B&)
  {
    cout << "A(const B&)" << endl;
  }
};

class B {
public:
  // A B can be converted to an A.
  operator A() const
  {
    cout << "operator A() const" << endl;
    A *a = new A(*this);
    return *a;
  }
};

void f(const A&)
{
  cout << "f(const A&)" << endl;
}


int main()
{
  B b;
  f(b);  // TODO: why doesn't this result in an ambiguity error???
}
