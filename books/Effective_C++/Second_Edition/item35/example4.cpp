#include <string>
using namespace std;

void error(const string& msg);      // defined elsewhere

class Bird {
public:
  virtual void fly();               // birds can fly
};

class Penguin: public Bird {
public:
  virtual void fly() { error("Penguins can't fly!"); }
 };
