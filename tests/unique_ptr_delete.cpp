/*
 * Test program to exiperiment with passing const std::unique_ptr<T>& as parameter.
 * (which is to be avoided according to [1], solution 3d)
 * 
 * References:
 *
 *   [1] https://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/
 */

#include <memory>

class Widget
{};

void f(const std::unique_ptr<Widget>& pw)
{
    delete pw.get();  // allowed, but runtime error: causes double delete
}

void g(Widget* pw)
{
    delete pw;  // allowed, but bad to delete p2 here...
}

int main()
{
    auto p1 = std::make_unique<Widget>();
    auto p2 = new Widget();

    f(p1);
    g(p2);

    //delete p2;  // better to delete p2 here
}
