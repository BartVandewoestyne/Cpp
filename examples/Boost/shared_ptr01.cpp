/**
 * My own example of how to use a Boost shared_ptr.
 */
#include <iostream>
#include <boost/shared_ptr.hpp>

class foo
{
  public:
    void print() { std::cout << "foo::print" << std::endl; }
};


int main()
{
  boost::shared_ptr<foo> sp1(new foo);
  sp1->print();
  std::cout << "sp1 pointer: " << sp1.get() << std::endl;

  boost::shared_ptr<foo> sp2(sp1);
  sp2->print();
  std::cout << "sp1 pointer: " << sp1.get() << std::endl;
  std::cout << "sp2 pointer: " << sp2.get() << std::endl;

  std::cout << "counter sp1: " << sp1.use_count() << std::endl;
  std::cout << "counter sp2: " << sp2.use_count() << std::endl;

  return 0;
}
