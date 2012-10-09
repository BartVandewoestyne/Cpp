#include <string>
using namespace std;

template<class T>
class NamedObject {
public:
  // this ctor no longer takes a const name, because name-
  // Value is now a reference-to-non-const string. The char*
  // ctor is gone, because we must have a string to refer to
  NamedObject(string& name, const T& value);
 
                               // as above, assume no
                               // operator= is declared
private:
  string& nameValue;           // this is now a reference
  const T objectValue;         // this is now const
};


int main()
{
  string newDog("Persephone");
  string oldDog("Satch");
 
  NamedObject<int> p(newDog, 2);      // as I write this, our dog
                                      // °Persephone is about to
                                      // have her second birthday
   
  NamedObject<int> s(oldDog, 29);     // the family dog Satch
                                      // (from my childhood)
                                      // would be 29 if she were
                                      // still alive
   
  p = s;                              // what should happen to
                                      // the data members in p?
}
