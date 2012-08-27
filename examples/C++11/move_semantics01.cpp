/**
 * References:
 *
 *   [1] http://blog.smartbear.com/software-quality/bid/200558/C-11-Tutorial-Introducing-the-Move-Constructor-and-the-Move-Assignment-Operator
 *
 * TODO:
 *   1. implement the C++03 copy constructor and assignment operator.
 */

#include <cstddef>
#include <vector>
using namespace std;

class MemoryPage
{
  size_t size;
  char * buf;

public:
  explicit MemoryPage(int sz=512):size(sz), buf(new char [size]) {}
  ~MemoryPage() { delete[] buf; }

  // Typical C++03 copy constructor and assignment operator.
  MemoryPage(const MemoryPage&);
  MemoryPage& operator=(const MemoryPage&);

  // C++11 move constructor.
  MemoryPage(MemoryPage&& other): size(0), buf(nullptr)
  {
    // Pilfer other's resource.
    size = other.size;
    buf = other.buf;

    // Reset other.
    other.size = 0;
    other.buf = nullptr;
  }

  // C++11 move assignment operator.
  //MemoryPage& MemoryPage::operator=(MemoryPage&& other)
  MemoryPage& operator=(MemoryPage&& other)
  {
    if (this != &other)
    {
      // release the current object's resources
      delete[] buf;
      size = 0;

      // pilfer other's resource
      size = other.size;
      buf = other.buf;

      // reset other
      other.size = 0;
      other.buf = nullptr;
    }
    return *this;
  }

};


int main()
{
  vector<MemoryPage> vm;

  // Both push_back() calls resolve as push_back(T&&) because their arguments
  // are rvalues.  push_back(T&&) moves the resources from the argument into
  // vector's internal MemoryPage objects using MemoryPage's move constructor.
  // In older versions of C++, the same program would generate copies of the
  // argument since the copy constructor of MemoryPage would be called instead.
  vm.push_back(MemoryPage(1024)); // push_back(T&&) is called
  vm.push_back(MemoryPage(2048)); // push_back(T&&) is called

  // push_back(const T&) is called when the argument is an lvalue:
  MemoryPage mp(1024); // lvalue
  //vm.push_back(mp);    // push_back(const T&) is called (TODO: implement
  //this!)

  // You can enforce the selection of push_back(T&&) in this case by casting
  // an lvalue to an rvalue reference using static_cast:
  vm.push_back(static_cast<MemoryPage&&>(mp)); // push_back(T&&) is called

  // Alternatively, use the new standard function std::move() for the same
  // purpose:
  vm.push_back(std::move(mp)); // push_back(T&&) is called

}
