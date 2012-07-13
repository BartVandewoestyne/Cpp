/**
 * Same as factory01, but now with C++98's std::auto_ptr<T> smartpointer.
 *
 * Remarks:
 *
 *   1. In C++11, the use of auto_ptr is deprecated and one can use maybe one
 *      of the unique_ptr, shared_ptr or weak_ptr smart pointer types.
 */

#include <memory>
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
    auto_ptr<Base> create(int number);
};

void Sub1::foo()
{
  cout << "Sub1::foo()" << endl;
}

void Sub2::foo()
{
  cout << "Sub2::foo()" << endl;
}

auto_ptr<Base> Factory::create(int number)
{
  auto_ptr<Base> myPointer;

  switch (number)
  {
    case 1:
      myPointer = auto_ptr<Base>(new Sub1);
      break;
    case 2:
      myPointer = auto_ptr<Base>(new Sub2);
      break;
    default:
      myPointer.reset();
      break;
  }
  return myPointer;
}

int main()
{
  Factory f;
  auto_ptr<Base> b1 = f.create(1);
  b1->foo();
  auto_ptr<Base> b2 = f.create(2);
  b2->foo();
}
