/**
 * Reference:
 *
 *   [1] http://www.cprogramming.com/c++11/c++11-lambda-closures.html
 *   [2] http://www.fluentcpp.com/2017/01/23/stl-function-objects-stateless-is-stressless/
 */

#include <iostream>

using namespace std;

int main()
{
    auto func = [] () { cout << "Hello world"; };
    func(); // now call the function
}
