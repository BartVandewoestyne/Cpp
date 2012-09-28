#include <cstring>

class String {
public:
  String(const char *value);    // see Item 11 for
                                // function definition
 
  ~String();                    // see Item 11 for
                                // function definition
 
  String& operator=(const String& rhs);
 
private:
  char *data;
};


String::String(const char *value)
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


inline String::~String() {
  delete [] data;
}

 
// an assignment operator that omits a check
// for assignment to self
String& String::operator=(const String& rhs)
{

  // Approach 1: value-equality.
  //if (strcmp(data, rhs.data) == 0) return *this;

  // Approach 2: address-equality (more common in C++ programs).
  if (this == &rhs) return *this;

  delete [] data;    // delete old memory
 
  // allocate new memory and copy rhs's value into it
  data = new char[strlen(rhs.data) + 1];
  strcpy(data, rhs.data);
 
  return *this;      // see Item 15
}


int main()
{
  String a = "Hello";
  a = a;                // same as a.operator=(a)
}
