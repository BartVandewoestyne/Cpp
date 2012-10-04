#include <iostream>
using namespace std;

class B
{
public:
  void mf() { cout << "B::mf()" << endl; }
};

class D
{
public:
  void mf() { cout << "D::mf()" << endl; }
};

int main()
{
  D *pd = new D;
  B *pb = pd; // TODO: error: cannot convert ‘D*’ to ‘B*’ in initialization
  
  pb->mf();                    // call mf through a
                               // pointer-to-base
  
  pd->mf();                    // call mf through a
                               // pointer-to-derived
}
