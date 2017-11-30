/*
 * References:
 *   [1] http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c15361/A-TR1-Tutorial-Smart-Pointers.htm
 */

#include <iostream>
#include <memory>

void show(const std::weak_ptr<int>& wp)
{
   std::shared_ptr<int> sp = wp.lock();
   std::cout << *sp << std::endl;
}
 
int main()
{
   std::weak_ptr<int> wp;
   {
      std::shared_ptr<int> sp(new int(44));
      wp = sp;
 
      show(wp);
   }
 
   std::cout << "expired : " << std::boolalpha << wp.expired()
             << std::endl;
 
   return 0;
}
