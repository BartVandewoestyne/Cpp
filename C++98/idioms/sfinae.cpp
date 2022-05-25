/*
 * Key idea:
 *
 *   This rule applies during overload resolution of function templates: When
 *   substituting the explicitly specified or deduced type for the template
 *   parameter fails, the specialization is discarded from the overload set
 *   instead of causing a compile error.
 *
 *   This feature is used in template metaprogramming.
 *
 * References:
 *
 *   [wikipedia] Substitution failure is not an error
 *     http://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error
 *
 *   [cppreference] SFINAE
 *     https://en.cppreference.com/w/cpp/language/sfinae
 *
 *   [20191104alhadi] Substitution Failure is Error and Not An Error
 *     https://medium.com/@MKahsari/sfinae-step-by-step-67e6ef6154da
 *
 *   [20180518boccara] How to Make SFINAE Pretty – Part 2: the Hidden Beauty of SFINAE
 *     https://www.fluentcpp.com/2018/05/18/make-sfinae-pretty-2-hidden-beauty-sfinae/
 *
 *   [20180515boccara] How to Make SFINAE Pretty - Part 1: What SFINAE Brings to Code
 *     https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/
 *
 *   [warzecha20171110] An inspiring introduction to Templatemetaprogramming.
 *     https://youtu.be/UnIc_qJ0DRc?t=19m43s
 *
 *   [filipek20160225] SFINAE Followup
 *     http://www.bfilipek.com/2016/02/sfinae-followup.html
 *
 *   [filipek20160218] Notes on C++ SFINAE
 *     http://www.bfilipek.com/2016/02/notes-on-c-sfinae.html
 *
 *   [mueller20151130] Controlling overload resolution #4: SFINAE
 *     https://foonathan.github.io/blog/2015/11/30/overload-resolution-4.html
 *
 *   [guegant20151031] An introduction to C++'s SFINAE concept: compile-time introspection of a class member
 *     http://jguegant.github.io/blogs/tech/sfinae-introduction.html
 *
 *   [watt20150127] C++: SFINAE
 *     http://codeofthedamned.com/index.php/sfinae
 */


// The following example (with function templates, but it goes also for class
// templates) illustrates *a* basic instance of SFINAE (there could be many
// others):

#include <iostream>

struct Test {
  typedef int foo;
};

// In this case, the version that contains the sub-field 'foo' is the only
// valid type.
template <typename T>
void f(typename T::foo) { std::cout << "f(T::foo) called" << std::endl; }

// The version that requires a sub-field called 'foo' will be exluded
// as a possibility for this version.
template <typename T>
void f(T) { std::cout << "f(T) called" << std::endl; }

int main()
{
  f<Test>(10);  // Call f(T::foo)
  f<int>(10);   // Call f(T), without error, even though there is no int::foo,
                // thanks to SFINAE.
}
