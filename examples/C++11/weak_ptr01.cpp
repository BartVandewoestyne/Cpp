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

  std::shared_ptr<int> p1(new int(5));
  std::weak_ptr<int> wp1 = p1; // p1 owns the memory.
   
  {
    std::shared_ptr<int> p2 = wp1.lock(); // Now p1 and p2 own the memory.
    if (p2) // Always check to see if the memory still exists.
    { 
      std::cout << "Do something with p2." << std::endl;
    }
  } // p2 is destroyed.  Memory is owned by p1.
   
  p1.reset(); // Memory is deleted.
   
  std::shared_ptr<int> p3 = wp1.lock(); // Memory is gone, so we get an empty
                                        // shared_ptr.
  if (p3)
  {
    // Will not execute this.
    std::cout << "This should NOT be printed!" << std::endl;
  }

}
