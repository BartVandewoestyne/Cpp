/**
 * TODO: on my 64 bit machine, this prints -7296, check why it doesn't
 * print 128.
 */
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    //  'q'      = 0111 0001
    // ~'q'      = 1000 1110
    // ~'q' << 6 = 1000 0000 = 2^7 = 128
    std::cout << (~'q' << 6) << std::endl;
}
