#include <iostream>
#include <string>
using namespace std;

const                             // this is a const object...
class {
public:
  template<class T>               // convertible to any type
    operator T*() const           // of null non-member
    { return 0; }                 // pointer...
 
  template<class C, class T>      // or any type of null
    operator T C::*() const       // member pointer...
    { return 0; }
 
private:
  void operator&() const;         // whose address can't be
                                  // taken (see Item 27)...

} MYNULL;                           // and whose name is MYNULL

 
void f(int x)
{
  cout << "f(int x)" << endl;
}
 
void f(string *p)
{
  cout << "f(string *p)" << endl;
}

int main()
{ 
  f(MYNULL);                          // fine, converts MYNULL to
                                    // string*, then calls f(string*
  f(0);
}
