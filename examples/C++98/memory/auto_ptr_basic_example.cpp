/*
 * References:
 *   [1] http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c15361/A-TR1-Tutorial-Smart-Pointers.htm
 */

#include <memory>
#include <iostream>
 
class foo 
{
public:
   void print() { std::cout << "foo::print" << std::endl; }
};
 
int main()
{
   std::auto_ptr<foo> ap1(new foo);
   ap1->print();
   std::cout << "ap1 pointer: " << ap1.get() << std::endl;
 
   std::auto_ptr<foo> ap2(ap1);
   ap2->print();
   std::cout << "ap1 pointer: " << ap1.get() << std::endl;
   std::cout << "ap2 pointer: " << ap2.get() << std::endl;
   
   return 0;
}
