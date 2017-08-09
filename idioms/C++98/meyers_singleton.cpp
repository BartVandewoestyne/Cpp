/*
 * This implementation is not thread-safe??? (check why exactly)
 *
 * References:
 *
 *   [meyers2004alexandrescu] C++ and the Perils of Double-Checked Locking,
 *     Meyers S. and Alexandrescu Andrei,
 *     URL: http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
 *
 *   [vlissides1998] John Vlissides. Pattern Hatching: Design Patterns Applied. AddisonWesley, 1998.
 *     (The discussion of the 'Meyers Singleton' is on pp. 69ff.)
 *
 *   [meyers1998] Effective C++, Second Edition, Scott Meyers, Item 47: 'Ensure
 *     that non-local static objects are initialized before they're used.'
 *
 *   [meyers1996] More Effective C++, Scott Meyers, Item 26 'Limiting the
 *     number of objects of a class.'
 *
 *   [] https://stackoverflow.com/questions/13047526/difference-between-singleton-implemention-using-pointer-and-using-static-object
 *
 *   [] https://stackoverflow.com/questions/1661529/is-meyers-implementation-of-the-singleton-pattern-thread-safe
 */

#include <iostream>

namespace SingletonStuff
{
  class Singleton {
  public: 
    void doStuff() { std::cout << "Singleton::doStuff()" << std::endl; }
  friend Singleton& theSingleton();
  private:
    Singleton();
    Singleton(const Singleton& rhs);
  };

  Singleton& theSingleton()
  {
    static Singleton s;
    return s;
  }

  Singleton::Singleton()
  {
    std::cout << "Singleton::Singleton()" << std::endl;
  }
}

int main()
{
  {  // Method 1: include name of the namespace
    SingletonStuff::theSingleton().doStuff();
  }

  {  // Method 2: employing a using declaration to save typing
    using SingletonStuff::theSingleton;

    theSingleton().doStuff();
  }
}
