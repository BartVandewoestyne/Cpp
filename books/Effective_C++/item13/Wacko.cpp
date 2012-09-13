#include <string>
#include <iostream>
using namespace std;

class Wacko {
public:

  Wacko(const char *s): s1(s), s2(0) {}

  Wacko(const Wacko& rhs): s2(rhs.s1), s1(0) {}

private:
  string s1, s2;
};

 
int main()
{
  Wacko w1 = "Hello world!";
  Wacko w2 = w1;
}
