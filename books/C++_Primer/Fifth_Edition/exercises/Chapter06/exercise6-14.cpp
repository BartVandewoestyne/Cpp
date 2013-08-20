#include <iostream>
#include <string>

// No need for a reference for built-in datatypes: copies are cheap.
int abs(int x)
{
    std::cout << "x = " << x << std::endl;
}

// Using a reference to avoid copies.
void process(const std::string& s)
{
    std::cout << "s = " << s << std::endl;
}

int main()
{
  abs(5);
  process("test");
}
