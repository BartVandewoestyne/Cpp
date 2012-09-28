#include <cstring>

class String {

public:

  String(const char *value);

  // This compiles.
  String& operator=(const String& rhs) { return *this; }
  // This won't compile.
  //String& operator=(const String& rhs) { return rhs; }
  // This compiles, but doesn't let client code compile.
  //String& operator=(String& rhs) { return rhs; }

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


int main()
{
  String x("Test");
  x = "Hello";          // same as x.op=("Hello);
}
