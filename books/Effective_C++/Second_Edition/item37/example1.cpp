#include <iostream>
using namespace std;

class B {
public:
  // B::mf is nonvirtual (so statically bound).
  // Also notice the difference if you *do* make this function virtual!
  void mf() { cout << "B:mf()" << endl; }
};

class D: public B {
public:
  // D::mf is nonvirtual (so statically bound).
  // Notice the difference in behavior when D has defined its own version
  // of mf!!!
  void mf() { cout << "D:mf()" << endl; }  // hides B::mf; see Item 50
};

int main()
{

  D x;                          // x is an object of type D

  // Using pointer to Base.
  B *pB = &x;                   // get pointer to x

  pB->mf();                     // call mf through pointer

  // Using pointer to Derived.
  D *pD = &x;                   // get pointer to x

  pD->mf();                     // call mf through pointer

}
