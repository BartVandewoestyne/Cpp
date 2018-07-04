/**
 * Compare this code with the code from C++98/auto_ptr02.cpp.  It shows how the
 * use of boost::shared_ptr solves the problem that I had with std::auto_ptr.
 */

#include <iostream>
#include <boost/shared_ptr.hpp>

class AbstractBase
{
  public:

    // Using an abstract base class results in a segmentation fault.
    virtual void print() = 0;

    // Using an ordinary base class does not result in a segmentation fault,
    // but we don't get the expected derived class object in the call to
    // client.getPointer()...
    //void print() { std::cout << "Base::print() called." << std::endl; };
};


class Derived : public AbstractBase {
  public:
    void print() { std::cout << "Derived::print() called." << std::endl; };
};


class Client
{
  private:
    boost::shared_ptr<AbstractBase> pBase;

  public:

    Client() : pBase(new Derived()) {};

    boost::shared_ptr<AbstractBase> getPointer() { return pBase; };

};


int main()
{
  Client client;

  // The first one works...
  boost::shared_ptr<AbstractBase> p1 = client.getPointer();
  p1->print();

  // ... but the second one results in a segmentation fault because
  // it returns a null pointer.
  boost::shared_ptr<AbstractBase> p2 = client.getPointer();
  p2->print();

}
