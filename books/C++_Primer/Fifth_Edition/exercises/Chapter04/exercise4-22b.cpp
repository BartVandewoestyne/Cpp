#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int grade = 0;

    cin >> grade;

    string finalgrade;
    if (grade > 90)
    {
        finalgrade = "high pass";
    }
    else if (grade > 75)
    {
        finalgrade = "pass";
    }
    else if (grade >= 60)
    {
        finalgrade = "lowpass";
    }
    else
    {
        finalgrade = "fail";
    }

    cout << finalgrade << endl;
}
