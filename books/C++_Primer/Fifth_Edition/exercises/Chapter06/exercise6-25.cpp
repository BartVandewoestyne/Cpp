#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        string ss1(argv[1]);
        string ss2(argv[2]);
        std::cout << ss1 + ss2 << std::endl;
    }
    else
    {
        std::cout << "Please specify 2 arguments." << std::endl;
    }
}
