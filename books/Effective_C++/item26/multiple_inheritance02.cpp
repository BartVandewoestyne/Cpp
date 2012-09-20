#include <iostream>
using namespace std;

class Base1 {
public:
  int doIt() { cout << "Base1::doIt()" << endl; }
};

class Base2 {
private:
  void doIt() { cout << "Base2::doIt()" << endl; }
};

class Derived: public Base1,          // Derived doesn't declare
               public Base2 {         // a function called doIt
};

int main()
{
  Derived d;

  d.doIt();                   // error! still ambiguous

  //d.Base1::doIt();  // fine, calls Base1::doIt
  //d.Base2::doIt();  // fine, calls Base2::doIt
}
