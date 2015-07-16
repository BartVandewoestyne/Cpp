/**
 * Example illustrating how to disable copy constructor and assignment operator.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/7823845/disable-compiler-generated-copy-assignment-operator
 */

class Foo {

public:
  Foo() {}

// Disable copy constructor and assignment operator by making them private and
// not defining them.
private:
  Foo(const Foo&);
  Foo& operator=(const Foo&);

};


int main()
{
    Foo A;
    Foo B;

    Foo C(A);  // error
    B = A;     // error
}
