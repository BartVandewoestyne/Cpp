/**
 * References:
 *
 *   [guzman2017] Don't use C++ auto? Restricting auto is not the best decision for your company, and it is unfair to your developers. Instead, train them on how to use it.
 *     http://swdevmastery.com/dont-use-c-auto-restricting-auto-is-not-the-best-decision-for-your-company-and-it-is-unfair-to-your-developers-instead-train-them-on-how-to-use-it/
 *
 *   [carnie2016] Getting your head around auto's type-deduction rules
 *     https://blog.feabhas.com/2016/11/getting-head-around-autos-type-deduction-rules/
 *
 *   [haldar2016] C++ 11 Auto: How to use and avoid abuse
 *     http://www.acodersjourney.com/2016/02/c-11-auto/
 *
 *   [barker2016] C++11 auto declaration with and without pointer declarator
 *     https://stackoverflow.com/questions/34560365/c11-auto-declaration-with-and-without-pointer-declarator
 *
 *   [mertz2015] Modern C++ Features - auto for variables
 *     http://arne-mertz.de/2015/07/new-c-features-auto-for-variables/
 *
 *   [sutter2013] GotW #94 Solution: AAA Style (Almost Always Auto)
 *     http://herbsutter.com/2013/08/12/gotw-94-solution-aaa-style-almost-always-auto/
 *
 *   [becker2013] C++ auto and decltype Explained
 *     http://thbecker.net/articles/auto_and_decltype/section_01.html
 *
 *   [felics2012] Does auto make C++ code harder to understand?
 *     http://programmers.stackexchange.com/questions/180216/does-auto-make-c-code-harder-to-understand/
 *
 *   [roy???] With Respect to « Proper Usage » of auto
 *     http://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/auto-when.html
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

    // According to [7], the below declarations are exactly equivalent.  auto works
    // (almost) exactly the same as template type deduction.  Putting the star
    // explicitly makes the code a bit easier to read, and makes the programmer
    // aware that bar2 is a pointer (but your mileage may vary).
    {
        int foo = 10;
        auto bar1 = &foo;
        auto* bar2 = &foo;
    }
}
