#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const std::size_t ARRAY_SIZE = 10;
    int a[ARRAY_SIZE];
    int b[ARRAY_SIZE];

    // initialize elements
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        a[i] = i;
    }

    // copy into another array
    for (std::size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        b[i] = a[i];
    }

    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : b)
    {
        cout << i << " ";
    }
    cout << endl;
}
