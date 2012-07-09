/**
 * References:
 *
 *   [1] http://www.learncpp.com/cpp-tutorial/126-pure-virtual-functions-abstract-base-classes-and-interface-classes/
 */

#include <iostream>
#include <string>
using namespace std;

class Animal
{
  protected:
    std::string m_strName;
 
  public:
    Animal(std::string strName)
      : m_strName(strName)
    {}
 
    std::string GetName()
    {
      return m_strName;
    }

    // Pure virtual function.
    // A pure virtual function is useful when we have a function that we want
    // to put in the base class, but only the derived classes know what it
    // should return.  A pure virtual function makes it so the base class can
    // not be instantiated, and the derived classes are forced to define these
    // function before they can be instantiated.  This helps ensure the derived
    // classes do not forget to redefine functions that the base class was
    // expecting them to.
    virtual const char* Speak() = 0;

};


class Cow: public Animal
{
  public:
    Cow(std::string strName)
      : Animal(strName)
    {}
 
    // If you forgot to redefine Speak, then you get the error:
    //   error: cannot declare variable ‘cCow’ to be of abstract type ‘Cow’
    //   note:   because the following virtual functions are pure within ‘Cow’:
    //   note:       virtual const char* Animal::Speak()
    virtual const char* Speak() { return "Moo"; }
};
 

int main()
{
  Cow cCow("Betsy");
  cout << cCow.GetName() << " says " << cCow.Speak() << endl;
}
