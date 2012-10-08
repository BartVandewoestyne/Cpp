/**
 * References:
 *
 *   [1] http://en.wikipedia.org/wiki/Smart_pointer#shared_ptr_and_weak_ptr
 *
 */

#include <memory>

int main()
{
  std::shared_ptr<int> p1(new int(5));
  std::shared_ptr<int> p2 = p1; // Both now own the memory.
   
  p1.reset(); // Memory still exists, due to p2.
  p2.reset(); // Deletes the memory, since no one else owns the memory.
}
