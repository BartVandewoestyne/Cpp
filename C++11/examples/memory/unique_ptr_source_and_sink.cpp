/**
 * Illustrates how move semantics and unique pointer reinforce each other.
 *
 * References:
 *
 *   [josuttis20190902-05] C++ Smart Pointers - Usage and Secrets
 *     https://youtu.be/XH4xIyS9B2I?t=3153
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


// Herb Sutter Style sink function (call by value).
// (Later, acknowledged by Herb to be the worse of the two options,
//  but Josuttis still thinks this is the preferred form).
void sink1(std::unique_ptr<Foo> p) {
  std::cerr << "Sink owns Foo [" << p.get() << "]\n";
}

// Scott Meyers Style sink function (call by rvalue reference).
// (later confirmed by Herb Sutter, but Josuttis still thinks
//  this is the worst form).
void sink2(std::unique_ptr<Foo>&& p) {
  std::cerr << "Sink owns Foo [" << p.get() << "]\n";
}

std::unique_ptr<Foo> source() {
    std::cerr << "Creating Foo in source\n";
    return std::unique_ptr<Foo>(new Foo);
}


int main(int argc, char** argv)
{
    {
        std::cerr << "Calling source()\n";
        auto pmain = source();

        std::cerr << "Now pmain owns Foo [" << pmain.get() << "]\n";

        std::cerr << "Passing it to sink1()\n";
        //sink1(pmain);                    // ERROR: can't copy std::unique_ptr!
        sink1(std::move(pmain));           // OK: can move it!
        pmain.release();                   // Josuttis advises to always release after passing unique pointer to sink function.
    }

    {
        std::cerr << "Calling source()\n";
        auto pmain = source();

        std::cerr << "Now pmain owns Foo [" << pmain.get() << "]\n";

        std::cerr << "Passing it to sink2()\n";
        //sink2(pmain);                    // ERROR: can't copy std::unique_ptr!
        sink2(std::move(pmain));           // OK: can move it!
        pmain.release();                   // Josuttis advises to always release after passing unique pointer to sink function.
    }

    std::cerr << "Main done\n";
    return 0;
}
