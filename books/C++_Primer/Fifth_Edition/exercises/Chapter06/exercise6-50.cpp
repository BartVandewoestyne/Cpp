#include <iostream>
using std::cout;
using std::endl;

void f()
{  cout << "f()" << endl; }

void f(int)
{ cout << "f(int)" << endl; }

void f(int,int)
{ cout << "f(int,int)" << endl; }

void f(double, double = 3.14)
{ cout << "f(double, double = 3.14)" << endl; }

int main()
{
  // (a) ERROR: ambiguous because f(int,int) or f(double,double) are both equally possible.
  //f(2.56, 42);

  // (b) f(int)
  f(42);

  // (c) f(int, int)
  f(42, 0);

  // (d) f(double, double)
  f(2.56, 3.14);
}
