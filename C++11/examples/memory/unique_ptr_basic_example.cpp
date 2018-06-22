/**
 * Illustrates the use of unique_ptr.
 *
 * References:
 *
 *   [filipek20171204] 5 ways how unique_ptr enhances resource safety in your code
 *     http://www.bfilipek.com/2017/12/why-uniqueptr.html
 *
 *   [nelson20120626] C++11: unique_ptr
 *     http://www.drdobbs.com/cpp/c11-uniqueptr/240002708
 *
 *   [bendersky20120620] C++11: using unique_ptr with standard library containers
 *     http://eli.thegreenplace.net/2012/06/20/c11-using-unique_ptr-with-standard-library-containers/
 */

#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

struct Foo {

  Foo() { cerr << "Foo [" << this << "] constructed\n"; }

  virtual ~Foo() { cerr << "Foo [" << this << "] destructed\n"; }

};

int main(int argc, char** argv)
{

  // .. some code
  {
    unique_ptr<Foo> fp(new Foo());

    //unique_ptr<Foo> fp2(fp);    // ERROR! can't copy unique_ptr
    unique_ptr<Foo> fp3;
    //fp3 = fp;                   // ERROR! can't assign unique_ptr

    cerr << "Exiting scope\n";
  } // fp will be destroyed, and will destruct the pointed object

  cerr << "Demonstrating reset functionality:\n";
  {
    cerr << "Creating new unique_ptr...\n";
    unique_ptr<Foo> fp(new Foo());
    cerr << "done.\n";

    cerr << "Resetting...\n";
    fp.reset(new Foo());
    cerr << "done.\n";
  }

  return 0;
}
