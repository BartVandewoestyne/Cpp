#include <iostream>
using namespace std;

int ask_number()
{
    int number;
    std::cout << "Please enter a number to computer factorial of: ";
    cin >> number;
    return number;
}

int fact(int val)
{
    int ret = 1;  // local variable to hold the result as we calculate it.
    while (val > 1)
        ret *= val--;  // assign ret*val to ret and decrement val
    return ret;        // return the result
}

int main()
{
  int j = ask_number();
  cout << j << "! is " << fact(j) << endl;
  return 0;
}
