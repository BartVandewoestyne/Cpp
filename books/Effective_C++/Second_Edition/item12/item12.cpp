#include <string>
using namespace std;

template<class T>
class NamedPtr {

public:
  NamedPtr(const string& initName, T *initPtr);

private:

  //string name;
  //const string name;
  const string& name;      // must be initialized via initializer list???

  //T *ptr;
  T * const ptr;           // must be initialized via initializer list???

};

// Method 1: use the member initialization list.
// template<class T>
// NamedPtr<T>::NamedPtr(const string& initName, T *initPtr  )
// : name(initName), ptr(initPtr)
// {}

// Method 2: make assignments in the constructor body.
template<class T>
NamedPtr<T>::NamedPtr(const string& initName, T *initPtr)
{
  name = initName;
  ptr = initPtr;
}
