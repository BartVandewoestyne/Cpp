/**
 * References:
 *
 *   [1] http://scottmeyers.blogspot.de/2012/10/copying-constructors-in-c11.html
 */

#include <iostream>
 
class Widget {
public:
  Widget(){};
 
  Widget(const Widget&) { std::cout << "Widget copy ctor  "; }
  Widget(Widget&&) { std::cout << "Widget move ctor  "; }         // added this
     
 
  template<typename T>
  Widget(const T&) { std::cout << "Generalized Widget copy ctor  "; }
 
  template<typename T>
  Widget(T&&) { std::cout << "Universal Widget ctor  "; }
};
 
void endLine() { std::cout << '\n'; }

int main()
{
  Widget w;
  {
    std::cout << "Create auto from Widget:\n";
    std::cout << "  Direct init w/parens: ";   auto wcopy1(w);   endLine();       // now using auto
    std::cout << "  Copy init           : ";   auto wcopy2 = w;  endLine();
    std::cout << "  Direct init w/braces: ";   auto wcopy3 {w};  endLine();
    endLine();
  }
 
  const Widget cw;
  {
    std::cout << "Create auto from const Widget:\n";
    std::cout << "  Direct init w/parens: ";   auto wcopy1(cw);   endLine();
    std::cout << "  Copy init           : ";   auto wcopy2 = cw;  endLine();
    std::cout << "  Direct init w/braces: ";   auto wcopy3 {cw};  endLine();
    endLine();
  }
}
