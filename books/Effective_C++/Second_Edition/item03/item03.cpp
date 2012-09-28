#include <cstdlib>
#include <string>
using namespace std;

int main()
{
  // stringArray1 points to enough memory for 10 string objects, but no objects
  // have been constructed in that memory.  Furthermore, you have no way to
  // initialize the objects in the array.  In other words, stringArray1 is
  // pretty useless.
  string *stringArray1 =
    static_cast<string*>(malloc(10 * sizeof(string)));
  
  // This will release the memory pointed to by stringArray1, but no destructors
  // will be called on the string objects in that memory.
  free(stringArray1);


  // stringArray2 points to an array of 10 fully constructed string objects,
  // each of which can safely be used in any operation taking a string. 
  string *stringArray2 = new string[10];

  // Here, a destructor is called for each object in the array before any memory
  // is released. 
  delete [] stringArray2; // see Item 5 for why the "[]" is necessary.
}
