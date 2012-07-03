/**
 * Reference:
 *
 *   http://www.cprogramming.com/c++11/c++11-lambda-closures.html
 */

#include <iostream>

using namespace std;

int main()
{
    auto func = [] () { cout << "Hello world"; };
    func(); // now call the function
}
