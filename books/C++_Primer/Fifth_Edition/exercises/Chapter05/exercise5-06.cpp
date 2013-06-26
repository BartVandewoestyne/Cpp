/**
 * 100: A++
 * 80-89: C
 * 70-79: D
 * 60-69: E
 * < 60: F
 */
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade = 70;

    string lettergrade = (grade < 60 ? scores[0] : scores[(grade-50)/10]);

    std::cout << lettergrade << std::endl;
}
