/**
 * References:
 *
 *   [1] http://j.mp/cpp11ref
 */

#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{

    // C++03 and C++11.
    int a[] = { 1, 2, 3, 4, 5 };


    // C++03
    //vector<int> v;
    //for (int i = 1; i <= 5; ++i) v.push_back(i);

    // C++11
    //vector<int> v = { 1, 2, 3, 4, 5 };


    // C++03
    //map<int, string> labels;
    //labels.insert(make_pair(1, "Open"));
    //labels.insert(make_pair(2, "Close"));
    //labels.insert(make_pair(3, "Reboot"));

    // C++11
    map<int, string> labels {
        {1, "Open"},
        {2, "Close"},
        {3, "Reboot"}
    };

}
