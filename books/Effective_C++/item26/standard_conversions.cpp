#include <iostream>
using namespace std;

void f(int) { cout << "f(int)" << endl; }

void f(char) { cout << "f(char)" << endl; }

int main()
{
  double d = 6.02;

  // Error: ambiguous!
  //f(d);

  // Fine, calls f(int).
  f(static_cast<int>(d));

  // Fine, calls f(char).
  f(static_cast<char>(d));
}
