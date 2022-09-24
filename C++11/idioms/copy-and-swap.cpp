/*
 * Key idea:
 *   - Implement the copy/move assignment operators in terms of the copy/move
 *     constructor and achieve strong exception safety.
 
 *   - The copy-and-swap idiom has inherent strong exception safety because all
 *     allocations (if any) occur when copying into the other argument, before
 *     any changes have been made to *this. It is generally, however, less
 *     optimized than a more custom implementation of the assignment operators.
 
 * References:
 *
 *   [weinmann20181220] C++: Advanced Topics - The copy-and-swap idiom
 *     https://www.linkedin.com/learning/c-plus-plus-advanced-topics/the-copy-and-swap-idiom
 *
 *   [mansfeld20171209] Copy-and-swap
 *     https://cpppatterns.com/patterns/copy-and-swap.html
 */

#include <utility>

class resource {
    int x = 0;
};

class foo
{
public:

    foo()
      : p{new resource{}}
    { }

    foo(const foo& other)
      : p{new resource{*(other.p)}}
    { }

    foo(foo&& other)
      : p{other.p}
    {
      other.p = nullptr;
    }

    // Note that the class foo has an implementation similar to the Rule of
    // Five, yet its copy and move assignment operators have been replaced with
    // a single assignment operator.  This assignment operator takes its
    // argument by value, making use of the existing copy and move constructor
    // implementations.
    foo& operator=(foo other)
    {
      // To implement the assignment operator, we simply need to swap the
      // contents of *this and the argument, other. When other goes out of
      // scope at the end of the function, it will destroy any resources that
      // were originally associated with the current object.
      swap(*this, other);
      return *this;
    }

    ~foo()
    {
      delete p;
    }

    // To achieve this, we define a swap function for our class on lines 36–41,
    // which itself calls swap on the class’s members (line 40). We use a
    // using-declaration on line 38 to allow swap to be found via
    // argument-dependent lookup before using std::swap — this is not strictly
    // necessary in our case, because we are only swapping a pointer, but is good
    // practice in general.
    friend void swap(foo& first, foo& second)
    {
      using std::swap;
      swap(first.p, second.p);
    }

private:
    resource* p;
};
