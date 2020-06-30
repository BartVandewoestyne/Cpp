/*
 * References:
 *
 *  [cppreference] http://en.cppreference.com/w/cpp/memory/enable_shared_from_this
 *
 *  [kumar20200524] enable_shared_from_this - overview, examples, and internals
 *    https://www.nextptr.com/tutorial/ta1414193955/enable_shared_from_this-overview-examples-and-internals
 *
 *  [odwyer20190919] Back to Basics: Smart Pointers
 *    https://youtu.be/xGDLkt-jBJ4?t=2578
 *
 *  [klitzke2017] Notes on std::shared_ptr and std::weak_ptr
 *    https://eklitzke.org/notes-on-std-shared-ptr-and-std-weak-ptr
 *
 *  [mortoray2013] Safely using enable_shared_from_this
 *    https://mortoray.com/2013/08/02/safely-using-enable_shared_from_this/
 *
 *  [fido2009] What is the usefulness of `enable_shared_from_this`?
 *    https://stackoverflow.com/questions/712279/what-is-the-usefulness-of-enable-shared-from-this
 *
 *  [becker2005] Weak Pointers.
 *    http://www.drdobbs.com/weak-pointers/184402026
 */

#include <memory>
#include <iostream>
 
struct Good : std::enable_shared_from_this<Good> // note: public inheritance
{
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
};
 
struct Bad
{
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() { std::cout << "Bad::~Bad() called\n"; }
};
 
int main()
{
    // Good: the two shared_ptr's share the same object
    std::shared_ptr<Good> gp1 = std::make_shared<Good>();
    std::shared_ptr<Good> gp2 = gp1->getptr();
    std::cout << "gp2.use_count() = " << gp2.use_count() << '\n';
 
    // Bad: shared_from_this is called without having std::shared_ptr owning the caller 
    try {
        Good not_so_good;
        std::shared_ptr<Good> gp1 = not_so_good.getptr();
    } catch(std::bad_weak_ptr& e) {
        // undefined behavior (until C++17) and std::bad_weak_ptr thrown (since C++17)
        std::cout << e.what() << '\n';    
    }
 
    // Bad, each shared_ptr thinks it's the only owner of the object
    std::shared_ptr<Bad> bp1 = std::make_shared<Bad>();
    std::shared_ptr<Bad> bp2 = bp1->getptr();
    std::cout << "bp2.use_count() = " << bp2.use_count() << '\n';
} // UB: double-delete of Bad
