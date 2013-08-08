#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
    int i1, i2;

    while (cin >> i1 >> i2) {

        try {

            if (i2 == 0) {
                throw runtime_error("Second integer must be non-zero!");
            }

        } catch (runtime_error err) {
            cout << "second integer is zero, please re-enter two integers."
                 << endl;
            continue;
        }

        cout << i1 / i2 << endl;
    }
}
