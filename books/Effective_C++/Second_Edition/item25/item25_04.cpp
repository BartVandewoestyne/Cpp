#include <iostream>
#include <string>
using namespace std;

#define MYNULL 0L   // MYNULL is now a long int

void f(long int x)
{
  cout << "f(long int x)" << endl;
}

void f(string *ps)
{
  cout << "f(string *ps)" << endl;
}

int main()
{
  f(MYNULL);  // fine, calls f(long int)
}
