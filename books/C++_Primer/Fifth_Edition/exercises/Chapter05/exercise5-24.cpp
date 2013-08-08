#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int i1, i2;

    cin >> i1 >> i2;

    if (i2 == 0)
    {
        throw runtime_error("Second integer must be non-zero!");
    }

    cout << i1 / i2 << endl;
}
