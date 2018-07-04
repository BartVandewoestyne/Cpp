/**
 * Example demonstrating the use of shared pointers.
 *
 * When sp2 is created, sp1 does not give up the ownership, changing its
 * wrapped pointer to NULL; it only increments the reference counter.  When
 * the two shared pointer objects get out of scope, the last one that is
 * destroyed will release the resource.
 *
 * References:
 *
 *   [shahar2016] Exploring std::shared_ptr
 *     http://shaharmike.com/cpp/shared-ptr/
 *
 *   [bancila2008] A TR1 Tutorial: Smart Pointers
 *     http://www.codeguru.com/cpp/cpp/cpp_mfc/stl/article.php/c15361/A-TR1-Tutorial-Smart-Pointers.htm
 *
 *   [becker2005] Weak Pointers.
 *     http://www.drdobbs.com/weak-pointers/184402026
 */

#include <memory>
#include <iostream>
 
class foo
{ 
  public:
    void print() { std::cout << "foo::print()" << std::endl; }
};


int main()
{
  std::shared_ptr<foo> sp1(new foo);
  sp1->print();
  std::cout << "sp1 pointer: " << sp1.get() << std::endl;
   
  std::shared_ptr<foo> sp2(sp1);
  sp2->print();
  std::cout << "sp1 pointer: " << sp1.get() << std::endl;
  std::cout << "sp2 pointer: " << sp2.get() << std::endl;
   
  std::cout << "counter sp1: " << sp1.use_count() << std::endl;
  std::cout << "counter sp2: " << sp2.use_count() << std::endl;

  return 0;
}
