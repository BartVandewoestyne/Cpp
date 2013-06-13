#include <climits>
#include <cstdint>
#include <iostream>

int main()
{
    // TODO: check this one, printed value for a is weird.
    uint8_t a = UINT8_MAX;
    std::cout << "a = " << a << ", a + 1 = " << a + 1 << std::endl;

    int b = INT_MAX;
    std::cout << "b = " << b << ", b + 1 = " << b + 1 << std::endl;

    // TODO: check this one, seems not working... but
    // http://en.wikipedia.org/wiki/Integer_overflow gives this example.
    int16_t c = 30000;
    std::cout << "c = " << c << ", c + 30000 = " << c + 30000 << std::endl;
}
