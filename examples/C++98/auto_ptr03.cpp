/**
 * An auto_ptr example that I created myself, just to check
 * if what I do in main() results in an error.
 */

#include <iostream>
#include <memory>
using namespace std;

class A
{
  public:
    void foo() { cout << "A::foo() called." << endl; };
};

class B
{
  private:
    auto_ptr<A> pA;

  public:
    //B() : pA(auto_ptr<A>(new A())) {};
    B() : pA(new A()) {};
    auto_ptr<A> getPointerToA() { return pA; };
};

int main()
{
  B b;
  auto_ptr<A> x = b.getPointerToA();

  // Why does this still work????  Even after resetting or releasing the
  // auto_ptr???
  x.reset();
  x.release();
  x->foo();
}
