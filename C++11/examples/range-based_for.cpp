/**
 * References:
 *
 *   [josuttis202109XX] P201R2 - Fix the Range-Based for Loop
 *     http://josuttis.de/cpp/210929_rangebasedfor_p2012r2.pdf
 *
 *   [boccara20210902] How to Make Your Classes Compatible with Range for Loop
 *     https://www.fluentcpp.com/2021/09/02/how-to-make-your-classes-compatible-with-range-for-loop/
 *
 *   [boccara20210522] The Subtle Dangers of Temporaries in for Loops
 *     https://www.fluentcpp.com/2021/05/22/the-subtle-dangers-of-temporaries-in-for-loops/
 *
 *   [bevin20121113] New syntax - Range-based for
 *     http://mbevin.blogspot.be/2012/11/range-based-for.html
 *
 *   [stackoverflow20110806] How to use range-based for() loop with std::map?
 *     http://stackoverflow.com/questions/6963894/c11-how-to-use-range-based-for-loop-with-stdmap
 */

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Widget {
public:

    Widget(int id) : id(id) {}

    void f_const() const
    {
      std::cout << "f_const()" << std::endl;
    }

    void f_nonconst()
    {
        std::cout << "f_nonconst()" << std::endl;
        id = 111;
    }

    friend std::ostream& operator<<(std::ostream& os, const Widget& w);

private:
    int id;
};

std::ostream& operator<<(std::ostream& os, const Widget& w)
{
    os << "Widget " << w.id;
    return os;
}

int main()
{
    std::cout << "\nWith ints" << std::endl;

    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };

    //for (auto  number : numbers)        // by value
    for (auto& number : numbers)        // by reference
    //for (const auto& number : numbers)  // by const reference
    {
        number += 1;
    }

    for (const auto& number : numbers)
    {
        std::cout << number << std::endl;
    }


    std::cout << "\nWith objects" << std::endl;

    Widget w1(1);
    Widget w2(2);
    std::vector<Widget> widgets = { w1, w2 };

    //for (auto widget : widgets)
    //for (auto& widget : widgets)
    for (const auto& widget : widgets)
    {
        //Widget dummy(999);
        //widget = dummy;
        
        widget.f_const();
        //widget.f_nonconst();
    }

    for (const auto& widget : widgets)
    {
        std::cout << widget << std::endl;
    }

    std::cout << "\nWith std::unique_ptr to objects" << std::endl;

    std::unique_ptr<Widget> pw1(new Widget(1));
    std::unique_ptr<Widget> pw2(new Widget(2));

    std::vector<std::unique_ptr<Widget>> pwidgets;
    pwidgets.push_back(std::move(pw1));
    pwidgets.push_back(std::move(pw2));

    //for (auto pwidget : pwidgets)
    //for (auto& pwidget : pwidgets)
    for (const auto& pwidget : pwidgets)
    {
        std::unique_ptr<Widget> dummy = std::unique_ptr<Widget>(new Widget(222));

        //pwidget = std::move(dummy);
        
        //pwidget->f_const();
        pwidget->f_nonconst();  // note that we can change the pointed-to object when using 'const auto&' here!  Only the pointer is const!
    }

    for (const auto& pwidget : pwidgets)
    {
        std::cout << *pwidget << std::endl;
    }

}
