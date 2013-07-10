#include <iostream>

using std::cout;
using std::endl;

int main()
{
    bool someValue = true;

    someValue ? cout << "a1", cout << "a2" : cout << "b1", cout << "b2";

    cout << endl;

    (someValue ? cout << "a1", cout << "a2" : cout << "b1"), cout << "b2";

    cout << endl;
}
