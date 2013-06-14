#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    for (auto& e : v)
    {
        e = (e % 2 != 0) ? 2*e : e;
    }

    for (const auto& e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
