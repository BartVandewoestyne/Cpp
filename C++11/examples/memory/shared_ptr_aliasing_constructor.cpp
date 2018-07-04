/**
 * Example on one of std::shared_ptr's lesser-known constructors, called the 'aliasing constructor'.
 *
 * References:
 *
 *   [1] ISO/IEC 14882:2011 section 20.7.2.2.1 shared_ptr constructors [util.smartptr.shared.const]
 *   [2] https://www.justsoftwaresolutions.co.uk/cplusplus/shared-ptr-secret-constructor.html
 */

#include <cassert>
#include <memory>

/* Suppose we have a class X with a member that is an instance of some class Y... */

struct Y {
};

struct X {
    Y y;
};

struct do_nothing_deleter {
    template<typename T> void operator()(T*) {}  // BUG
};

void store_for_later(std::shared_ptr<Y>) {}

void foo() {

    // We have a dynamically allocated instance of X that we're managing with a shared_ptr<X>.
    std::shared_ptr<X> px(std::make_shared<X>());


    // We want to pass the Y member to a library that takes a shared_ptr<Y>.  We could construct
    // a shared_ptr<Y> that refers to the member, with a do-nothing deleter, so the library
    // doesn't acutally try and delete the Y object, but what if the library keeps hold of the
    // shared_ptr<Y> and our original shared_ptr<X> goes out of scope?
    std::shared_ptr<Y> py(&px->y, do_nothing_deleter());

    store_for_later(py);

}  // our X object is destroyed
   // Our stored shared_ptr<Y> now points midway throgh a destroyed object, which is rather undesirable.


void bar() {

    std::shared_ptr<X> px(std::make_shared<X>());

    // This is where the aliasing constructor comes in: rather than fiddling with deleters, we just say
    // that our shared_ptr<Y> shares ownership with our shared_ptr<X>.
    std::shared_ptr<Y> py(px, &px->y);

    store_for_later(py);

}  // our X object is kept alive


// The pointer doesn't have to be directly related at all: the only requirement is that the lifetime of the
// new pointer is at least as long as the lifetime of the shared_ptr objects that reference it.  If we had a new class
// X2 that held a dynamically allocated Y object, we could still use the aliasing constructor to get a shared_ptr<Y>
// that referred to our dynamically-allocated Y object.
struct X2 {
    std::unique_ptr<Y> y;
    X2() : y(new Y) {}
};

void baz() {
    std::shared_ptr<X2> px(std::make_shared<X2>());
    std::shared_ptr<Y> py(px, px->y.get());
    store_for_later(py);
}  // our X2 object is kept alive


// This could be used for classes that use the pimpl idiom, or trees where you
// want to be able to pass round pointers to the child nodes, but keep the whole
// tree alive. Or, you could use it to keep a shared library alive as long as a
// pointer to a variable stored in that library was being used. If our class X
// loads the shared library in its constructor and unloads it in the destructor,
// then we can pass round shared_ptr<Y> objects that share ownership with our
// shared_ptr<X> object to keep the shared library from being unloaded until all
// the shared_ptr<Y> objects have been destroyed or reset.

void nuance()
{
    using namespace std;

    int i;
    shared_ptr<int> sp(shared_ptr<X>(), &i);
    assert(sp.use_count() == 0);
    assert(sp.get() == &i);
}

int main()
{
  foo();

  bar();

  baz();

  nuance();
}
