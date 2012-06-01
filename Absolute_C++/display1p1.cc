#include <iostream>
using namespace std;

int main()
{
  int numberOfLanguages;

  cout << "Hello reader.\n"
       << "Welcome to c++.\n";

  cout << "How many programming languages have you used? ";
  cin >> numberOfLanguages;

  if (numberOfLanguages < 1)
    cout << "Read the preface.  You may prefer\n"
         << "a more elementary book by the same author.\n";
  else
    cout << "Enjoy the book.\n";
  return 0;
}
