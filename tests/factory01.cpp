/**
 * Example demonstrating some kind of Factory pattern.  You need this if you
 * want to return instances of subclasses of an abstract base class, but the
 * exact subclass type to return is decided at runtime.
 *
 * Remarks:
 *
 *   1. It's probably better to use C++98's auto_ptr or C++11's unique_ptr,
 *      shared_ptr or weak_ptr smart pointer types.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/2861270/returning-an-abstract-class-from-a-function
 */

#include <iostream>
using namespace std;

// Due to at least one pure virtual function, base is an abstract class.
class Base
{
  public:
    virtual void foo() = 0;
};

class Sub1 : public Base
{
  public:
    virtual // not really necessary
    void foo();
};

class Sub2 : public Base
{
  public:
    virtual // not really necessary
    void foo();
};

// The Factory will create either a Sub1 or a Sub2 instance, depending on the
// value of the specified number.  Note that since we do not know whether we
// will return Sub1 or Sub2, we return a pointer to Base.  Returning a Base
// itself is not possible since Base is an abstract class and cannot be
// instantiated.
class Factory
{
  public:
    Base* create(int number);
};

void Sub1::foo()
{
  cout << "Sub1::foo()" << endl;
}

void Sub2::foo()
{
  cout << "Sub2::foo()" << endl;
}

Base* Factory::create(int number)
{
  Base* myPointer(NULL);

  switch (number)
  {
    case 1:
      myPointer = new Sub1;
      break;
    case 2:
      myPointer = new Sub2;
      break;
    default:
      myPointer = NULL;
      break;
  }
  return myPointer;
}

int main()
{
  Factory f;
  Base *b1 = f.create(1);
  b1->foo();
  Base *b2 = f.create(2);
  b2->foo();
}
