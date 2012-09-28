//const double sdmBOOK_VERSION = 2.0;      // in this library,
//                                         // each symbol begins
//class sdmHandle { ... };                 // with "sdm"
//
//sdmHandle& sdmGetHandle();             // see Item 47 for why you
//                                       // might want to declare
//                                       // a function like this

#include <iostream>
using namespace std;

namespace sdm {
  const double BOOK_VERSION = 2.0;
  class Handle {};
  Handle& getHandle();
}

namespace AcmeWindowSystem {
   typedef int Handle;
}

void f1()
{
  using namespace sdm;           // make all symbols in sdm
                                 // available w/o qualification
                                 // in this scope
 
  cout << BOOK_VERSION;          // okay, resolves to
                                 // sdm::BOOK_VERSION

  Handle h = getHandle();        // okay, Handle resolves to
                                 // sdm::Handle, getHandle
                                 // resolves to sdm::getHandle
}

void f2()
{
  using sdm::BOOK_VERSION;        // make only BOOK_VERSION
                                  // available w/o qualification
                                  // in this scope
 
  cout << BOOK_VERSION;           // okay, resolves to
                                  // sdm::BOOK_VERSION
 
  //Handle h = getHandle();         // error! neither Handle
  //                                // nor getHandle were
  //                                // imported into this scope
}

void f3()
{
  cout << sdm::BOOK_VERSION;      // okay, makes BOOK_VERSION
                                  // available for this one use
                                  // only
 
  //double d = BOOK_VERSION;        // error! BOOK_VERSION is
  //                                // not in scope
 
  //Handle h = getHandle();         // error! neither Handle
  //                                // nor getHandle were
  //                                // imported into this scope
}

void f()
{
  using namespace sdm;                 // import sdm symbols
  using namespace AcmeWindowSystem;    // import Acme symbols
 
                                       // freely refer to sdm
                                       // and Acme symbols
                                       // other than Handle
 
  //Handle h;                            // error! which Handle?
 
  sdm::Handle h1;                      // fine, no ambiguity
 
  AcmeWindowSystem::Handle h2;         // also no ambiguity
}
