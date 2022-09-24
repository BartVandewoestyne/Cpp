/*
 * References:
 *
 *   [oopscene20201013] C++17: std::any
 *     https://oopscenities.net/2020/10/30/cpp17_std_any/
 */

#include <any>
#include <iostream>


struct A
{
  int n;
  A(int n) : n{n} { std::cout << "Constructor\n"; }
  ~A() { std::cout << "Destructor\n"; }
  A(A&& a) : n{a.n} { std::cout << "Move constructor\n"; }
  A(const A& a) : n{a.n} { std::cout << "Copy constructor\n"; }
  void print() const { std::cout << n << "\n"; }
};


int main()
{
    {
        // The instance of std::any will store a copy (in this case a 'moved
        // version') of the original object that was created.  Therefore, the
        // output here is:
        //   Constructor
        //   Move constructor
        //   Destructor
        //   Destructor
        std::any some = A{4516};
    }
    
    std::cout << std::endl;

    {
        // Using std::make_any is very similar to std::make_shared in the way
        // that it will take care of creating the object instead of
        // copying/moving it.  The parameters passed to std::make_any are the
        // ones you would pass to the object's constructor.  Here, the output
        // is:
        //   Constructor
        //   Destructor
        auto some = std::make_any<A>(4517);
    }

    std::cout << std::endl;

    {
        std::cout << "When invoking the print() method:" << std::endl;

        // std::any_cast<A> returns a copy of the given object.
        //   Constructor
        //   Copy constructor
        //   4517
        //   Destructor
        //   Destructor
        auto some = std::make_any<A>(4517);
        std::any_cast<A>(some).print();
    }

    std::cout << std::endl;

    {
        std::cout << "After avoiding a copy by using a reference:" << std::endl;

        // If you want to avoid a copy and use a reference, you need to ask for
        // that explicitly in the call to std::any_cast.  The output will be:
        //   Constructor
        //   4517
        //   Destructor
        auto some = std::make_any<A>(4517);
        std::any_cast<A&>(some).print();
    }

    std::cout << std::endl;

    {
        // It is also possible to use std::any_cast<T> passing a pointer to an
        // instance of std::any instead of a reference.
        // In such case, if the cast is possible, will return a valid pointer
        // to a T* object, otherwise it will return a nullptr.
        //
        // Notice that in the example below, we are passing a pointer to 'some'
        // instead of a reference.  When this occurs, the implementation
        // returns a pointer to the target type if the stored object is of the
        // same data type (second line) or a null pointer if not (third line,
        // where we are trying to cast the object from type A to int).
        // Using this overloaded version with pointers avoids throwing an
        // exception and allows you to check if the returned pointer is null.
        auto some = std::make_any<A>(4517);
        std::any_cast<A>(&some)->print();
        std::cout << std::any_cast<int>(&some) << "\n";
    }
    
}
