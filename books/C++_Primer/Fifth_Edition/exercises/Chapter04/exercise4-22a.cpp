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

    string finalgrade = (grade > 90) ? "high pass"
                        : (grade > 75) ? "pass"
                          :  (grade >= 60) ? "lowpass"
                            : "fail" ;

    cout << finalgrade << endl;
}
