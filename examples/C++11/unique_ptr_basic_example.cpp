/**
 * Illustrates the use of unique_ptr.
 *
 * References:
 *   http://eli.thegreenplace.net/2012/06/20/c11-using-unique_ptr-with-standard-library-containers/
 */

#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

struct Foo {

  Foo() {
    cerr << "Foo [" << this << "] constructed\n";
  }

  virtual ~Foo() {
    cerr << "Foo [" << this << "] destructed\n";
  }

};

int main(int argc, char** argv) {

  // .. some code
  {
    unique_ptr<Foo> fp(new Foo());

    //unique_ptr<Foo> fp2(fp);    // ERROR! can't copy unique_ptr
    unique_ptr<Foo> fp3;
    //fp3 = fp;                   // ERROR! can't assign unique_ptr

    cerr << "Exiting scope\n";
  } // fp will be destroyed, and will destruct the pointed object

  return 0;

}
