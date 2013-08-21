#include <initializer_list>
#include <iostream>
using namespace std;

int sum_it(initializer_list<int> il)
{
    int sum = 0;
    for (const auto& elem : il)
    {
        sum += elem;
    }
    return sum;
}

int main()
{
    std::cout << sum_it({1, 2, 3}) << std::endl;
}
