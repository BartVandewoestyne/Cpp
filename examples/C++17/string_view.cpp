/*
 * References:
 *   [1] http://insights.dice.com/2016/12/15/breaking-down-current-state-c-17/
 *   [2] http://foonathan.net/blog/2017/03/22/string_view-temporary.html
 *   [3] http://www.grimm-jaud.de/index.php/blog/c-17-vermeide-kopieren-mit-std-string-view
 *   [4] C++ Weekly - Ep 73 - std::string_view (https://youtu.be/fj_CF8xK760)
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
