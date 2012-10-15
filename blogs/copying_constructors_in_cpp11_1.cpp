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
    std::cout << "Create Widget from Widget:\n";
    std::cout << "  Direct init w/parens: ";   Widget wcopy1(w);  endLine();
    std::cout << "  Copy init           : ";   Widget wcopy2 = w; endLine();
    std::cout << "  Direct init w/braces: ";   Widget wcopy3 {w}; endLine();
    endLine();
  }
 
  const Widget cw;
 
  {
    std::cout << "Create Widget from const Widget:\n";
    std::cout << "  Direct init w/parens: ";   Widget wcopy1(cw);  endLine();
    std::cout << "  Copy init           : ";   Widget wcopy2 = cw; endLine();
    std::cout << "  Direct init w/braces: ";   Widget wcopy3 {cw}; endLine();
    endLine();
  }
}
