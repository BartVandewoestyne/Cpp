#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const std::size_t ARRAY_SIZE = 10;
    int a[ARRAY_SIZE];

    for (std::size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        a[i] = i;
    }

    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}
