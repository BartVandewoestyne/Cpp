#include <iostream>
#include <string>
using namespace std;

void f(int x)
{
  cout << "f(int x)" << endl;
}

void f(string *ps)
{
  cout << "f(string *ps)" << endl;
}


int main()
{
  f(0);
}
