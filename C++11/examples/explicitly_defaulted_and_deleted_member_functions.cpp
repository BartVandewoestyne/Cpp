/**
 * Key ideas:
 *
 *   - Basic examples of defaulted and deleted functions.
 *   - The = delete specifier can also be used to prohibit calling *any* function,
 *     which can be used to disallow calling a member function with particular parameters.
 *
 * References:
 *
 *   [wikipedia] Explicitly defaulted and deleted special member functions.
 *     http://en.wikipedia.org/wiki/C%2B%2B11#Explicitly_defaulted_and_deleted_special_member_functions
 *
 *   [20210916vorbrodt] = delete; // not just for special member functions
 *     https://vorbrodt.blog/2021/09/16/delete-not-just-for-special-member-functions/
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
// (but note however that there is a shorter and sweeter syntax in C++20:
//   void f(auto) = delete;)
struct OnlyDouble {
    void f(double d);
    template<class T> void f(T) = delete;
};
