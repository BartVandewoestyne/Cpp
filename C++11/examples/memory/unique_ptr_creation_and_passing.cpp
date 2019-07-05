/**
 * Illustrates how move semantics and unique pointer reinforce each other.
 *
 * References:
 *
 *   [filipek20170220] Modernize: Sink Functions
 *     http://www.bfilipek.com/2017/02/modernize-sink-functions.html
 *
 *   [sutter20130605] GotW #91 Solution: Smart Pointer Parameters
 *     https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/
 *
 *   [bendersky20120620] C++11: using unique_ptr with standard library containers
 *     http://eli.thegreenplace.net/2012/06/20/c11-using-unique_ptr-with-standard-library-containers/
 */
 
#include <iostream>
#include <cstdlib>
#include <memory>

struct Foo {

  Foo() {
    std::cerr << "Foo [" << this << "] constructed\n";
  }

  virtual ~Foo() {
    std::cerr << "Foo [" << this << "] destructed\n";
  }

};


void sink(std::unique_ptr<Foo> p) {
  std::cerr << "Sink owns Foo [" << p.get() << "]\n";
}


std::unique_ptr<Foo> source() {
    std::cerr << "Creating Foo in source\n";
    return std::unique_ptr<Foo>(new Foo);
}


int main(int argc, char** argv) {

    std::cerr << "Calling source()\n";
    auto pmain = source();

    std::cerr << "Now pmain owns Foo [" << pmain.get() << "]\n";

    std::cerr << "Passing it to sink()\n";
    //sink(pmain);                    // ERROR: can't copy std::unique_ptr!
    sink(std::move(pmain));           // OK: can move it!

    std::cerr << "Main done\n";
    return 0;

}
