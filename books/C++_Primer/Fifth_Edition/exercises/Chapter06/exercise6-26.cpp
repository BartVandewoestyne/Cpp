// TODO: improve this

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
    }
}
