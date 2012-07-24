/**
 * Test program to check if gdb uses the operator<< when printing an object.
 * Aparrently it doesn't...
 */
#include <iostream>

using namespace std;

class A {
  private:
    int i;
  public:
    A(int i);
    friend ostream & operator<<(ostream & out, const A& data);
};

A::A(int i)
  : i(i)
{}

ostream & operator<<(ostream & out, const A& data)
{
  out << "Test: " << data.i;
}


int main()
{
  A x(1);
  cout << x << endl;
  return 0;
}
