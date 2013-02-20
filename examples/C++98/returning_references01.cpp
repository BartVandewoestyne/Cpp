/**
 * TODO: check if this was an example I created myself, or if I got it from
 *       the internet somewhere...
 */
#include <string>
#include <iostream>
using namespace std;

class A {

private:
  string a;

public:

  A(const string& a) : a(a) {} 

  A(const A& rhs) {
    cout << "A(const A& rhs)" << endl;
    a = rhs.getMember();
  }

  A& operator=(const A& rhs) {
    cout << "A::operator=(const A& rhs)" << endl;
    a = rhs.getMember();
  }

  string getMember() const {
    cout << "string getMember() const" << endl;
    return a;
  }

  string& getMember() {
    cout << "string& getMember()" << endl;
    return a;
  }

};

int main()
{
  cout << "Test1" << endl;
  A myA("Initial");
  cout << myA.getMember() << endl;
  cout << endl;

  cout << "Test2" << endl;
  A myA2(myA);
  cout << endl;

  cout << "Test3" << endl;
  A myA3("Initial3");
  myA3 = myA;
  cout << endl;

  cout << "Test4" << endl;
  string b = myA.getMember();
  b = "Changed1";
  cout << myA.getMember() << endl;
  cout << endl;

  cout << "Test5" << endl;
  string& c = myA.getMember();
  c = "Changed2";
  cout << myA.getMember() << endl;
  cout << endl;

  cout << "Test6" << endl;
  myA.getMember() = "Changed3";
  cout << myA.getMember() << endl;
  cout << endl;
}
