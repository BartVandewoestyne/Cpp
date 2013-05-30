/**
 * References:
 *
 *   [1] http://j.mp/cpp11ref
 *   [2] http://programmers.stackexchange.com/questions/180216/does-auto-make-c-code-harder-to-understand/
 *   [3] http://thbecker.net/articles/auto_and_decltype/section_01.html
 */

#include <list>
#include <map>
#include <memory>
#include <string>
using namespace std;

class T {};

int main()
{
    // Here is T in the expression.  No need to repeat it again.
    auto p = new T();

    // The same as above.
    T arg1;
    auto pp = make_shared<T>(arg1);

    // If you need to store lambda you may use auto or std::function
    auto my_lambda = [](){};

    // Instead of map<string,list<int>::iterator>::const_iterator it = m.cbegin()
    map<string,list<int>::iterator> m;
    auto it = m.begin();
}
