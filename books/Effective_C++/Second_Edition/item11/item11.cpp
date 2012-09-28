#include <cstring>

// A poorly designed String class.
class String {

public:

  String(const char *value);
  ~String();
  // no copy ctor or operator=

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


void doNothing(String localString)
{}


void problem1()
{
  String a("Hello");
  String b("Hello");
  b = a;
}


void problem2()
{
  String a("Hello");     // define and construct a

  {                      // open new scope

    String b("World");   // define and construct b

    b = a;               // execute default o=, lose b's memory

  }                      // close scope, call b's destructor

  String c = a;          // c.data is undefined!
                         // a.data is already deleted
}


void problem3()
{
  String s = "The Truth Is Out There";
  doNothing(s);
}


int main()
{
  problem1();
  problem2();
  problem3();
}
