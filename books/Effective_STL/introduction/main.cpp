#include <iostream>
#include <vector>
using namespace std;

template<typename C>
bool lastGreaterThanFirst(const C& container)
{
    if (container.empty()) return false;

    typename C::const_iterator begin(container.begin());
    typename C::const_iterator end(container.end());

    return *--end > *begin;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    //v.push_back(0);

    if (lastGreaterThanFirst(v))
    {
        cout << "Last is greater than first." << endl;
    }
    else
    {
        cout << "Last is NOT greater than first." << endl;
    }
}
