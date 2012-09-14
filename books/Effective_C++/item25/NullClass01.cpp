#include <iostream>
#include <string>
using namespace std;

// a first cut at a class yielding MYNULL pointer objects
class NullClass {
public:
  template<class T>                       // generates
    operator T*() const { return 0; }     // operator T* for
};                                        // all types T; each
                                          // function returns
                                          // the null pointer

const NullClass MYNULL;             // MYNULL is an object of
                                  // type NullClass
 
void f(int x)
{
  cout << "f(int x)" << endl;
}
 
void f(string *p)
{
  //cout << "f(string *p)" << endl;
}

int main()
{ 
  f(MYNULL);                          // fine, converts MYNULL to
                                    // string*, then calls f(string*
}
