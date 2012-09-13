/**
 * References:
 *
 *   [1] http://en.wikipedia.org/wiki/C%2B%2B11#Explicitly_defaulted_and_deleted_special_member_functions
 */

// The following type explicitly declares that it is using the default
// constructor:
struct SomeType {
    SomeType() = default; // The default constructor is explicitly stated.
    SomeType(OtherType value);
};

// Certain features can be explicitly disabled. For example, the following type
// is non-copyable:
struct NonCopyable {
    NonCopyable & operator=(const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable() = default;
};

// The = delete specifier can be used to prohibit calling any function, which
// can be used to disallow calling a member function with particular parameters.
// For example:
struct NoInt {

    void f(double i);

    // An attempt to call f() with an int will be rejected by the compiler,
    // instead of performing a silent conversion to double.
    void f(int) = delete;

};

// This can be generalized to disallow calling the function with any type other
// than double as follows:
struct OnlyDouble {
    void f(double d);
    template<class T> void f(T) = delete;
};
