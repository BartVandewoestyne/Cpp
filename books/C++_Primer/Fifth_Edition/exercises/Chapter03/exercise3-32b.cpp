#include <cstddef>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    const int MAX_SIZE = 10;
    vector<int> a(MAX_SIZE);
    vector<int> b(MAX_SIZE);

    // initialize elements
    for (decltype(a.size()) i = 0; i < MAX_SIZE; ++i)
    {
        a[i] = i;
    }

    b = a;

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
