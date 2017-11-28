/**
 * An example illustrating certain dangerous side-effecs of using auto_ptr...
 *
 * In the code below, only the first client.getPointer() call seems to return
 * the correct pointer.  The next calls to this function return a null pointer.
 */

#include <iostream>
#include <memory>

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
    std::auto_ptr<AbstractBase> pBase;

  public:

    Client() : pBase(new Derived()) {};

    std::auto_ptr<AbstractBase> getPointer() { return pBase; };

};


int main()
{
  Client client;

  // The first one works...
  std::auto_ptr<AbstractBase> p1 = client.getPointer();
  p1->print();

  // ... but the second one results in a segmentation fault because
  // it returns a null pointer.
  std::auto_ptr<AbstractBase> p2 = client.getPointer();
  p2->print();

}
