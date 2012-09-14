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

  void * const MYNULL = 0;          // potential NULL definition

  f(0);
  f(static_cast<string*>(MYNULL));  // calls f(string*)
  f(static_cast<string*>(0));       // calls f(string*)
  f(MYNULL);                        // error!
}
