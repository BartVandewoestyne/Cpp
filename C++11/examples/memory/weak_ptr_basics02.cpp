/**
 * References:
 *
 *   [1] http://en.wikipedia.org/wiki/Smart_pointer#shared_ptr_and_weak_ptr
 *
 */

#include <iostream>
#include <memory>

int main()
{
  std::shared_ptr<int> sp1(new int(5));
  std::weak_ptr<int> wp1 = sp1;  // sp1 owns the memory.
   
  {
    std::shared_ptr<int> sp2 = wp1.lock();  // Now sp1 and sp2 own the memory.
    if (sp2)  // Always check to see if the memory still exists.
    { 
      std::cout << "Do something with sp2." << std::endl;
    }
  } // sp2 is destroyed.  Memory is owned by sp1.
   
  sp1.reset(); // Memory is deleted.
   
  std::shared_ptr<int> sp3 = wp1.lock();  // Memory is gone, so we get an empty
  if (sp3)                                // shared_ptr.
  {
    // Will not execute this.
    std::cout << "This should NOT be printed!" << std::endl;
  }
}
