/**
 * References:
 *
 *   [wikipedia] Curiously recurring template pattern
 *     https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
 *
 *   [boccara20170516] What the CRTP can bring to your code
 *     http://www.fluentcpp.com/2017/05/16/what-the-crtp-brings-to-code/
 *
 *   [boccara20170512] The Curiously Recurring Template Pattern (CRTP)
 *     http://www.fluentcpp.com/2017/05/12/curiously-recursive-template-pattern/
 *
 *   [boccara20170509] An implementation helper for the CRTP
 *     http://www.fluentcpp.com/2017/05/19/crtp-helper/
 *
 *   [dewhurst20170328] Variadic CRTP
 *     http://stevedewhurst.com/once_weakly/once-weakly20170328/once-weakly20170328.pdf
 *
 *   [grimm20161216] C++ ist doch lazy!
 *     http://www.grimm-jaud.de/index.php/blog/c-ist-doch-lazy
 *
 *   [nanjappa20150709] A simple example to understand CRTP
 *     http://codeyarns.com/2015/07/09/how-to-understand-crtp/
 *
 *   [coplien199502XX] Curiously Recurring Template Patterns
 *     http://sites.google.com/a/gertrudandcope.com/info/Publications/InheritedTemplate.pdf
 */

#include <iostream>
using namespace std;

template <typename Derived>
struct Creature
{
    int eye_num;

    friend bool operator == (const Derived& lhs, const Derived& rhs)
    {
        return lhs.IsEqual(rhs);
    }

    friend bool operator != (const Derived& lhs, const Derived& rhs)
    {
        return !(lhs.IsEqual(rhs));
    }
};

struct Bird: Creature<Bird>
{
    int wing_num;

    bool IsEqual(const Bird& b) const
    {
        return eye_num == b.eye_num && wing_num == b.wing_num;
    }
};

struct Fish: Creature<Fish>
{
    int fin_num;

    bool IsEqual(const Fish& f) const
    {
        return eye_num == f.eye_num && fin_num == f.fin_num;
    }
};

int main()
{
    Bird b1, b2, b3;

    b1.eye_num  = 2;
    b2.eye_num  = 2;
    b3.eye_num  = 2;

    b1.wing_num = 2;
    b2.wing_num = 2;
    b3.wing_num = 3;

    if (b1 != b2) cout << "Bird equal\n";
    else          cout << "Bird not equal\n";
    if (b1 == b3) cout << "Bird equal\n";
    else          cout << "Bird not equal\n";

    // You can do the same with Fish:
    // Fish f1, f2, f3;
    // f1.fin_num = 5;
    // and so on ...
}
