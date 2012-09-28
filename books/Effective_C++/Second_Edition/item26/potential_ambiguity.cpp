/**
 * Remark:
 *   When compiling with g++, without the -pedantic option you don't get
 *   the ambiguity error.  If you do use the -pedantic option, you get it.
 */

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
  f(b); // ambiguity error!
}
