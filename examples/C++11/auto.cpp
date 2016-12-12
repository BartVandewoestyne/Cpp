/**
 * References:
 *
 *   [1] http://j.mp/cpp11ref
 *   [2] http://programmers.stackexchange.com/questions/180216/does-auto-make-c-code-harder-to-understand/
 *   [3] http://thbecker.net/articles/auto_and_decltype/section_01.html
 *   [4] http://arne-mertz.de/2015/07/new-c-features-auto-for-variables/
 *   [5] http://herbsutter.com/2013/08/12/gotw-94-solution-aaa-style-almost-always-auto/
 *   [6] https://blog.feabhas.com/2016/11/getting-head-around-autos-type-deduction-rules/
 */

#include <list>
#include <map>
#include <memory>
#include <string>
using namespace std;

class T {};

int main()
{
    { 
      // In [1], the advice is to prefer using auto in the following cases:

      // Here, T is in the expression.  No need to repeat it again.
      auto p = new T();

      // Here, T is in the expression.  No need to repeat it again.
      T arg1;
      auto pp = make_shared<T>(arg1);

      // If you need to store lambda you may use auto or std::function
      auto my_lambda = [](){};

      // Instead of map<string,list<int>::iterator>::const_iterator it = m.cbegin()
      map<string,list<int>::iterator> m;
      auto it = m.begin();

    }
}
