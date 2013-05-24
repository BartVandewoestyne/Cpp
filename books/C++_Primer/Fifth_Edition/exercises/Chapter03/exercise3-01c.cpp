#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Enter two integers:" << endl;

    int i1 = 0, i2 = 0;
    cin >> i1 >> i2;

    int val = i1;
    while (val <= i2) {
        cout << val << endl;
        val++;
    }

    return 0;
}
