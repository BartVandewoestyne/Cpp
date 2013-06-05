#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    const int MAX_NB_INTEGERS = 6;

    vector<int> v;

    int number;
    for (int i = 0; i < MAX_NB_INTEGERS; ++i)
    {
        cin >> number;
        v.push_back(number);
    }

    for (auto it = v.cbegin(); it != v.cend(); it += 2)
    {
        std::cout << *it + *(it+1) << " ";
    }
    std::cout << endl;

    for (auto itForward = v.cbegin(), itBackward = v.cend();
              itForward != itBackward;
              ++itForward, --itBackward)
    {
        std::cout << *itForward + *itBackward << " ";
    }
    std::cout << endl;
}
