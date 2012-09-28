// TODO: 
//   * second String example about conceptual constness.
//   * mutable example + trick example

#include <cstring>
#include <iostream>
using namespace std;

class String {
public:

  String(const char *value)
  {
    if (value) {
      data = new char[strlen(value) + 1];
      strcpy(data, value);
    }
    else {
      data = new char[1];
      *data = '\0';
    }
  }
 
  // operator[] for non-const objects
  char& operator[](int position)
  { return data[position]; }

  // operator[] for const objects
  const char& operator[](int position) const
  { return data[position]; }

  operator char *() const { return data; }
 
private:
  char *data;
};


int main()
{
  String s1 = "Hello";
  cout << s1[0];                  // calls non-const
                                  // String::operator[]
  const String s2 = "World";
  cout << s2[0];                  // calls const
                                  // String::operator[]

  String s = "Hello";                      // non-const String object
   
  cout << s[0];                            // fine — reading a
                                           // non-const String
   
  s[0] = 'x';                              // fine — writing a
                                           // non-const String
   
  const String cs = "World";               // const String object
   
  cout << cs[0];                           // fine — reading a
                                           // const String
   
  //cs[0] = 'x';                             // error! — writing a
                                           // const String

  const String s3 = "Hello";  // decare constant object

  char *nasty = s3;           // calls op char*() const

  *nasty = 'M';              // modifies s.data[0]

  cout << s3;                 // writes "Mello"

}
