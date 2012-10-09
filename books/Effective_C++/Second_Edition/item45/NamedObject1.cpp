#include <string>
using namespace std;

template<class T>
class NamedObject {
public:
  NamedObject(const char *name, const T& value);
  NamedObject(const string& name, const T& value);
private:
  string nameValue;
  T objectValue;
};


int main()
{
  NamedObject<int> no1("Smallest Prime Number", 2);

  NamedObject<int> no2(no1);      // calls copy constructor
}
