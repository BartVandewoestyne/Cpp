/**
 * Example to demonstrate the usefulness of explicit constructors.
 *
 * References:
 * 
 *   [1] http://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-in-c-mean
 */
#include <iostream>

class Foo
{
public:

  // Single parameter constructor, can be used as an implicit conversion.
  Foo(int foo) : m_foo(foo)
  //explicit Foo(int foo) : m_foo(foo)
  {
    std::cout << "Foo(int foo)" << std::endl;
  }

  int GetFoo() { return m_foo; }

private:
  int m_foo;
};

// A simple function that takes a Foo object.
void DoBar(Foo foo)
{
  int i = foo.GetFoo();
}

int main()
{

  // The parameter is not a Foo object, but an int.  However, there exists a
  // constructor for Foo that takes an int so this constructor can be used to
  // convert the parameter to the correct type.
  DoBar(42);

  // Prefixing the explicit keyword to the constructor prevents the compiler
  // from using that constructor for implicit conversions.  Adding it to the
  // above class will create a compiler error at the function call DoBar (42).
  // It is now necessary to call for conversion explicitly with DoBar (Foo (42))
  //DoBar(Foo(42));

}
