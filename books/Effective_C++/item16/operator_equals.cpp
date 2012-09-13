class Base {

public:
  Base(int initialValue = 0): x(initialValue) {}
 
private:
  int x;

};

 
class Derived: public Base {

public:
  Derived(int initialValue)
  : Base(initialValue), y(initialValue) {}
 
  Derived& operator=(const Derived& rhs);
 
private:
  int y;

};


// ERRONEOUS assignment operator: the data member x in the Base part of a
// Derived object is unaffected by this assignment operator.
//Derived& Derived::operator=(const Derived& rhs)
//{
//  if (this == &rhs) return *this;    // see Item 17
// 
//  y = rhs.y;                         // assign to Derived's
//                                     // lone data member
// 
//  return *this;                      // see Item 15
//}

// CORRECT assignment operator.
Derived& Derived::operator=(const Derived& rhs)
{
  if (this == &rhs) return *this;
 
  Base::operator=(rhs);    // call this->Base::operator=
  y = rhs.y;
 
  return *this;
}


void assignmentTester()
{
  Derived d1(0);                      // d1.x = 0, d1.y = 0
  Derived d2(1);                      // d2.x = 1, d2.y = 1
  d1 = d2;                            // d1.x = 0, d1.y = 1!
}


int main()
{
  assignmentTester();
}
