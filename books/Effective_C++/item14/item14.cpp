// TODO: implement Array::~Array() and NamedArray(int, int, const string&) so 
//       that things compile and run.
#include <string>
#include <vector>
using namespace std;

template<class T>                // base class template
class Array {                    // (from Item 13)

public:
  Array(int lowBound, int highBound);
  ~Array();
 
private:
  vector<T> data;
  size_t size;
  int lBound, hBound;

};

 
template<class T>
class NamedArray: public Array<T> {

public:
  NamedArray(int lowBound, int highBound, const string& name);
 
private:
  string arrayName;

};


int main()
{
  NamedArray<int> *pna =
    new NamedArray<int>(10, 20, "Impending Doom");
   
  Array<int> *pa;
  
  pa = pna;                // NamedArray<int>* -> Array<int>*
   
  delete pa;               // undefined! (Insert theme to
                           //°Twilight Zone here); in practice,
                           // pa->arrayName will often be leaked,
                           // because the NamedArray part of
                           // *pa will never be destroyed
}
