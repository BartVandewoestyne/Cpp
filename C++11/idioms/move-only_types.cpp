/*
 * Reasons for move-only types:
 *
 *   - Objects which manage resources (perhaps physical ones) that
 *     cannot/should not be shared between objects.  For example
 *     a Socket class (see [stackoverflow20151024]).
 *
 *   - Other?
 *
 * Examples of move-only types:
 *
 *   std::atomic
 *   std::unique_ptr
 *
 * References:
 *
 *   [microsoft20190705] Value Types (Modern C++)
 *     https://docs.microsoft.com/en-us/cpp/cpp/value-types-modern-cpp
 *
 *   [stackoverflow20151024] Is there a point to define move-only objects in c++11?
 *     https://stackoverflow.com/questions/33316942/is-there-a-point-to-define-move-only-objects-in-c11
 *
 *   [fekete20140926] Using Auto for Declaring Variables of Move-only Types
 *     https://www.codeproject.com/Articles/823658/Using-Auto-for-Declaring-Variables-of-Move-only-Ty
 *
 *   [meyers20140724] Should move-only types ever be passed by value?
 *     http://scottmeyers.blogspot.com/2014/07/should-move-only-types-ever-be-passed.html
 */

#include <string>
#include <utility>

class Foo
{
public:

    Foo(const std::string& name)
        : m_name(name) {}

    virtual ~Foo() {}

    Foo(Foo&&) = default;
    Foo& operator=(Foo&&) = default;

    Foo(const Foo&) = delete;
    Foo& operator=(const Foo&) = delete;

    std::string name() const { return m_name; }

private:
    std::string m_name;
};

int main()
{
    Foo foo("foo");


    // Copy constructor: not available
    
    //Foo bar(foo);   // error: use of deleted function 'Foo::Foo(const Foo&)'
    //Foo bar = foo;  // error: use of deleted function 'Foo::Foo(const Foo&)'


    // Assignment operator: not available
    Foo bar("bar");
    //bar = foo;      // error: use of deleted function 'Foo& Foo::operator=(const Foo&)'


    // Move constructor: available
    Foo baz(std::move(foo));

    // Move assignment operator: available
    bar = std::move(baz);
}
