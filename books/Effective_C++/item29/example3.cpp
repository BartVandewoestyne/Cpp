#include <string.h>

class String {
public:
  String(const char *value);        // see Item 11 for pos-
  ~String();                        // sible implementations;
                                    // see Item M5 for comments
                                    // on the first constructor
 
  char& operator[](int index) const
  {
    return data[index];
  }

private:
  char *data;
};


int main()
{
  String s = "I'm not constant";

  s[0] = 'x';    // fine, s isn't const

  const String cs = "I'm constant";

  cs[0] = 'x';   // this modifies the const string, but compilers won't notice
}
