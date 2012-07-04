/**
 * Example illustrating the use of auto_ptr.
 *
 * Note:
 *
 *   auto_ptr IS NOW CONSIDERED DEPRECATED!  Use C++11's std::unique_ptr,
 *   std::shared_ptr and std::weak_ptr!!!
 *
 * The major problems introduced by auto_ptr are:
 *
 *   1. Copying and assigning changes the owner of a resource, modifying not
 *      only the destination but also the source, which it not intuitive.
 *   2. It cannot be used in STL containers because the constraint that a
 *      container's elements must be copy constructable and assignable does
 *      not apply to this class.
 *
 * Reference:
 *
 *   http://www.developer.com/net/cplus/article.php/3834316/Easy-C-Resource-Management-with-sharedptr.htm
 */

#include <memory>
#include <iostream>
 
class foo
{
  public:
    void print() {std::cout << "foo::print" << std::endl;}
};
 

int main()
{
  std::auto_ptr<foo> ap1(new foo);
  ap1->print();
  std::cout << "ap1 pointer: " << ap1.get() << std::endl;
   
  // After creating and initializing object ap2, ap1 gives up the ownership of
  // the resource, and its wrapper pointer becomes NULL.
  std::auto_ptr<foo> ap2(ap1);
  ap2->print();
  std::cout << "ap1 pointer: " << ap1.get() << std::endl;
  std::cout << "ap2 pointer: " << ap2.get() << std::endl;

  return 0;
}
