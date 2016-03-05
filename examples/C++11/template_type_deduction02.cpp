/*
 * Explaining Template Argument Deduction.
 *
 * References:
 *   [1] https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Core-C-/Stephan-T-Lavavej-Core-C-2-of-n
 *   [2] C++ ANSI ISO IEC 14882-2011, temp.deduct
 */

#define EXAMPLE 12

#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

#if EXAMPLE == 1 || EXAMPLE == 3

template <typename T> void meow(T t) {
    cout << t << endl;
}

#elif EXAMPLE == 2

template <typename T> void meow(T one, T two) {
    cout << one << " " << two << endl;
}

#elif EXAMPLE == 4

// const is dropped here, T is int
// pass-by-value, so copying the value and modifying the copy!
//
// The rule about dropping constness only applies when you're calling a
// function template that's taking a parameter by value.
template <typename T> void meow(T t) {
    t *= 2; 
    cout << t << endl;
}

#elif EXAMPLE == 5

// If it's taking a reference, then argument constness is *not* dropped,
// because this would be a horrible safety problem.
template <typename T> void meow(T& t) {
    t *= 2; 
    cout << t << endl;
}

#elif EXAMPLE == 6

// When called with a const int, T is deduced to be int.
template <typename T> void meow(const T& t) {
    cout << t << endl;
}

#elif EXAMPLE == 7

// When called with an int, the top-level const will be ignored and T
// will be deduced to be int.
template <typename T> void meow(const T t) {
    cout << t << endl;
}

#elif EXAMPLE == 8

template <typename T> void meow(T t) {
    typedef typename make_unsigned<T>::type U;
    U u = static_cast<U>(t);
    cout << u << endl;
}

#elif EXAMPLE == 9

// ERROR: does not compile!  Can't figure out what T is.
template <typename T> void meow(typename make_unsigned<T>::type t) {
    cout << t << endl;
}

#elif EXAMPLE == 10

template <typename T> void meow(T val, function<void (T)> f) {
    f(val);
}

#elif EXAMPLE == 11

// This is some kind of trick to make it work!

template <typename T> struct Identity {
    typedef T type;
};

template <typename T> void meow(T val,
                                typename Identity<function<void (T)>>::type f) {
    f(val);
}

#elif EXAMPLE == 12

template <typename T> void meow(const basic_string<T>& s) {
    cout << "str " << s << endl;
}

template <typename T> void meow(const T* ptr) {
    cout << "ptr " << ptr << endl;
}

#endif

int main() {

#if EXAMPLE == 1

    meow(1729);
    meow<int>(1729);  // also compiles and runs, but more verbose
                      // Don't try to help the compiler, simply let template
                      // argument deduction do its job!
#elif EXAMPLE == 2

    meow(17, 29);  // works
    //meow(17, 29L);  // error: no matching function for call to ‘meow(int, long int)’

#elif EXAMPLE == 3

    int n = 1234;
    meow(n);

#elif EXAMPLE == 4 || EXAMPLE == 5 || EXAMPLE == 6

    // top level cv-qualifier
    const int n = 1234;
    //n *= 2;  // error: assignment of read-only variable
    meow(n);

#elif EXAMPLE == 7

    int n = 1234;
    ++n;
    meow(n);

#elif EXAMPLE == 8 || EXAMPLE == 9

    int n = -1234;
    meow(n);

#elif EXAMPLE == 10

    // Template argument deduction works here!
    function<void (int)> fxn = [](int x) { cout << "lambda " << x << endl; };
    meow(1729, fxn);

    // Template argument deduction does not work here because of the lambda.
    //meow(1729, [](int x) { cout << "lambda " << x << endl; });

#elif EXAMPLE == 11

    meow(1729, [](int x) { cout << "lambda " << x << endl; });

#elif EXAMPLE == 12

    string s("peppermint");
    meow(s);

    meow("peppermint");

#endif

    cout << "Template argument deduction!" << endl;

}
