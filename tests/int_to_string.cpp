#include <iostream>
#include <sstream>

int main()
{
    std::ostringstream ss;
    ss << "Test" << 1;
    std::cout << ss.str() << std::endl;
}
