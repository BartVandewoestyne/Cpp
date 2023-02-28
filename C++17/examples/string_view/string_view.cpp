/*
 * Key ideas:
 *
 *   - When would you use a string_view instead of a string [clow20150924]?
 *       -> Passing as a parameter to a "pure" function.
 *       -> Returning from a function.
 *       -> A reference to part of a long-lived data structure.
 *
 *   - "std::string_view" should be used to pass a read-only string to a function [sonarsource-rspec-6009]
 *       -> Everywhere where you have const std::string& function arguments,
 *          they can be safely replaced with std::string_view ones if you are
 *          not relying on the null-termination character.
 * 
 *   - It is idiomatic to pass std::string_view by value.
 *
 *   - Drawbacks of std::string_view:
 *       -> Lifetime management: there's no connection between the std::string_view and the storage it points to (except what you make yourself).
 *       -> An std::string_view is not necessarily null-terminated.
 *
 * References:
 *
 *   [sonarsource-rspec-6009] "std::string_view" should be used to pass a read-only string to a function
 *     https://rules.sonarsource.com/cpp/RSPEC-6009
 *
 *   [odwyer20211119] A footnote on “Three reasons to pass std::string_view by value”
 *     https://quuxplusone.github.io/blog/2021/11/19/string-view-by-value-ps/
 *
 *   [odwyer20211109] Three reasons to pass std::string_view by value
 *     https://quuxplusone.github.io/blog/2021/11/09/pass-string-view-by-value/
 *
 *   [miller20191009] C++ std::string_view for better performance: An example use case
 *     https://www.nextptr.com/tutorial/ta1217154594/cplusplus-stdstring_view-for-better-performance-an-example-use-case
 *
 *   [oneal20180821] std::string_view: The Duct Tape of String Types
 *     https://blogs.msdn.microsoft.com/vcblog/2018/08/21/stdstring_view-the-duct-tape-of-string-types/
 *
 *   [filipek20180723] Performance of std::string_view vs std::string from C++17
 *     https://www.bfilipek.com/2018/07/string-view-perf.html
 *
 *   [gregoire20180606] C++17: std::string_view
 *     http://www.nuonsoft.com/blog/2018/06/06/c17-stdstring_view/
 *
 *   [mutz20171111] StringViews, StringViews everywhere! - Marc Mutz - Meeting C++ 2017
 *     https://youtu.be/0QFPKgvLhao
 *
 *   [turner20170724] C++ Weekly - Ep 73 - std::string_view
 *     https://youtu.be/fj_CF8xK760
 *
 *   [grimm20170424] C++17: Vermeide Kopieren mit std::string_view
 *     http://www.grimm-jaud.de/index.php/blog/c-17-vermeide-kopieren-mit-std-string-view
 *
 *   [müller20170322] std::string_view accepting temporaries: good idea or horrible pitfall?
 *     http://foonathan.net/blog/2017/03/22/string_view-temporary.html
 *
 *   [clow20150924] CppCon 2015: Marshall Clow 'string_view'
 *     https://www.youtube.com/watch?v=H9gAaNRoon4
 */

#include <string>

// Notice the difference in assembler output when using std::string vs
// std::string_view, as shown in [turner20170724].
//
//std::size_t length(const std::string& s)
std::size_t length(std::string_view s)
{
    return s.size();
}


//void legacy_call(const char* x) {}     // old form without std::string_view
void legacy_call(std::string_view x) {}  // new form using std::string_view

int main()
{
    legacy_call("Hi mom");
    
    std::string foo;
    legacy_call(foo.c_str());  // works
    legacy_call(foo);          // better

    return length("hello world, long string");
}
