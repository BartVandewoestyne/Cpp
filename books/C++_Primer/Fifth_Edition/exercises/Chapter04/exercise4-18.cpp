#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v = {1, 2, 3, 4, -5, 6};

    auto pbeg = v.begin();
    // print elements up to the first negative value
    while (pbeg != v.end() && *pbeg >= 0)
    {
        // Using postfix is correct.
        //cout << *pbeg++ << endl;  // print the current value and advance pbeg

        // Using prefix, we would skip the first element and also print the
        // negative value.
        cout << *++pbeg << endl;
    }
}
