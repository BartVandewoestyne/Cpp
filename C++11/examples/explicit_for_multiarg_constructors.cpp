/*
 * Key idea:
 *
 *   - Up until C++11 there is no reason to use explicit on a multi-arg
 *     constructor.
 *
 *   - From C++11 on, copy-initialization (but not direct initialization)
 *     with an initializer list requires that the constructor NOT be marked
 *     explicit.
 *
 * References:
 *
 *   [peterg20160824] Explicit constructor taking multiple arguments
 *     https://stackoverflow.com/questions/39122101/explicit-constructor-taking-multiple-arguments
 */

struct Foo { Foo(int, int) {} };
struct Bar { explicit Bar(int, int) {} };

class Point {
public:
    explicit Point(int x, int y) {}
};

void func(Point p) {}

int main()
{
    Foo f1(1, 1); // ok
    Foo f2 {1, 1}; // ok

    // OKAY: copy-initialization with an initializer list works here because
    // the constructor is NOT marked explicit.
    Foo f3 = {1, 1}; // ok


    Bar b1(1, 1); // ok

    Bar b2 {1, 1}; // ok

    // NOT OKAY: copy-initialization with an initializer list requires that
    // the constructor NOT be marked explicit.
    //Bar b3 = {1, 1}; // NOT OKAY


    //func({10, 20}); // Error, needs explicit cast
    func(Point(10, 20)); // OK
}
