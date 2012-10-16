#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

int main()
{
    //int maxlen;  // doesn't work
    string::size_type maxlen;  // works
    Student_info s;
    max(s.name.size(), maxlen);
}
