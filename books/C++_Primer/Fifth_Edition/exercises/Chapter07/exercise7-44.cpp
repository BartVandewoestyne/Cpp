#include <iostream>
#include <string>
#include <vector>

using std::vector;

class NoDefault {
public:
    NoDefault(const std::string&)
      { std::cout << "NoDefault(const std::string&)" << std::endl; }
};

int main()
{
  // This is not legal, because the 10 elements from the vector must be able to
  // get default constructed using a default constructor, and NoDefault has no
  // such default constructor.
  //vector<NoDefault> vec(10);
}
