/**
 * Reference:
 *
 *   [1] http://www.learncpp.com/cpp-tutorial/126-pure-virtual-functions-abstract-base-classes-and-interface-classes/
 */
class Base
{
  public:

    // A normal non-virtual function.
    const char* SayHi() { return "Hi"; }
 
    // A normal virtual function.
    virtual const char* GetName() { return "Base"; }
 
    // A pure virtual function.
    // When we add a pure virtual function to our class, we are effectively
    // saying, “it is up to the derived classes to implement this function”.
    virtual int GetValue() = 0;
};


// Using a pure virtual function has two main consequences: first, any class
// with one or more pure virtual functions becomes an abstract base class,
// which means that it can not be instantiated!
int main()
{
  // This gives the following error:
  //   error: cannot declare variable ‘cBase’ to be of abstract type ‘Base’
  //   note:   because the following virtual functions are pure within ‘Base’:
  //   note:       virtual int Base::GetValue()
  //Base cBase;
  //cBase.GetValue();
}
