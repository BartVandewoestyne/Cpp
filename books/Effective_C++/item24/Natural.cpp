#include <string>
using namespace std;

// A class for representing natural numbers
class Natural {
public:
  Natural(int initValue);
  Natural(const Natural& rhs);
 
private:
  unsigned int value;
 
  void init(int initValue);
  void error(const string& msg);
};
 
inline
void Natural::init(int initValue) { value = initValue; }
 
Natural::Natural(int initValue)
{
  if (initValue > 0) init(initValue);
  else error("Illegal initial value");
}

inline Natural::Natural(const Natural& x)
{ init(x.value); }
