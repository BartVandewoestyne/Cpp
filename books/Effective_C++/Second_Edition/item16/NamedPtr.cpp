#include <string>
using namespace std;

template<class T>          // template for classes associating
class NamedPtr {           // names with pointers (from Item 12)

public:
  NamedPtr(const string& initName, T *initPtr);
  NamedPtr& operator=(const NamedPtr& rhs);
 
private:
  string name;
  T *ptr;
};

 
template<class T>
NamedPtr<T>& NamedPtr<T>::operator=(const NamedPtr<T>& rhs)
{
  if (this == &rhs)
    return *this;              // see Item 17

  // assign to all data members
  name = rhs.name;             // assign to name
 
  *ptr = *rhs.ptr;             // for ptr, assign what's
                               // pointed to, not the
                               // pointer itself
 
  return *this;                // see Item 15
}
