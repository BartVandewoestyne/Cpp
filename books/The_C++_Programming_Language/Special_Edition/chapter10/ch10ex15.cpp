/**
  * (*1) Given this program:
  *
  *       #include <iostream>
  *       
  *       int main()
  *       {
  *         std::cout << "Hello, world!\n";
  *       }
  *
  * modify it to produce this output:
  *
  *   Initialize
  *   Hello, world!
  *   Clean up
  *
  * Do not change main() in any way.
  */

#include <iostream>
using namespace std;

// See section 10.4.9:
//
//   "A variable defined outside any function (that is, global, namespace, and
//    class static variables) is initialized (constructed) before main() is
//    invoked, and any such variable that has been constructed will have its
//    destructor invoked after exit from main()."
//
class Dummy{
  public:
    Dummy() { cout << "Initialize" << endl; }
    ~Dummy() { cout << "Clean up" << endl; }
};
Dummy d;

int main()
{
  std::cout << "Hello, world!\n";
}
