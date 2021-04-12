/*
 * References:
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
 *   [bolton20161215] Breaking Down the Current State of C++ 17
 *     http://insights.dice.com/2016/12/15/breaking-down-current-state-c-17/
 */

#include <string>

// Notice the difference in assembler output when using std::string vs
// std::string_view, as shown in [4].
//
//std::size_t length(const std::string& s)
std::size_t length(const std::string_view& s)
{
    return s.size();
}

int main()
{

    return length("hello world, long string");
}
