#include <vector>
using namespace std;

template<class T>
class Array {

public:
  Array(int lowBound, int highBound);
 
private:
  vector<T> data;               // the array data is stored
                                // in a vector object; see
                                // Item 49 for info about
                                // the vector template
 
  size_t size;                  // # of elements in array
 
  int lBound, hBound;           // lower bound, higher bound
};

 
// IMPORTANT: class members are initialized in the order of their declaration in
// the class; the order in which they are listed in a member initialization list
// makes not a whit of difference. 
template<class T>
Array<T>::Array(int lowBound, int highBound)
: size(highBound - lowBound + 1),
  lBound(lowBound), hBound(highBound),
  data(size)
{}
