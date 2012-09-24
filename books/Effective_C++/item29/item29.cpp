// TODO: finish this one!  Check what files we need.

#include <string.h>

class String {
public:
  String(const char *value);        // see Item 11 for pos-
  ~String();                        // sible implementations;
                                    // see Item M5 for comments
                                    // on the first constructor
 
  // Alternative 1
  //operator char *() const;          // convert String -> char*;
                                    // see also Item M5

  // Alternative 2
  operator const char *() const;

private:
  char *data;
};

// Fast, but incorrect implementation of String::operator char*.
//inline String::operator char*() const
//{
//  return data;
//}

// Slower, but safer implementation.
//inline String::operator char*() const
//{
//  char *copy = new char[strlen(data) + 1];
//  strcpy(copy, data);
//
//  return copy;
//}

inline String::operator const char*() const
{
  return data;
}

int main()
{

  const String B("Hello World"); // B is a const object

  // Make alsoB another name for B, but without the constness.
  // This is called 'casting away the constness'...
  String& alsoB = const_cast<String&>(B);

  char *str = B;   // calls B.operator char*()

  strcpy(str, "Hi Mom");  // modifies what str points to

}
