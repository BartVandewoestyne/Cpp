#include <iostream>

int main()
{
    int k = 0;
    while (k != 10) {          // invariant: we have written k asterisks so far
        // Make sure we can use cout inside this while loop.
        using std::cout;
        cout << "*";
        ++k;
    }
    // Need std:: here, because we didn't use a 'using namespace std;' line.
    std::cout << std::endl;   // std:: is required here
    return 0;
}
