#include <iostream>
#include <string>
#include <vector>

using namespace std;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> center(const vector<string>& v) {

    string::size_type maxlen = width(v);

    vector<string> ret;
    for (vector<string>::const_iterator it = v.begin();
         it != v.end();
         ++it) {
        unsigned int left = (maxlen - it->size())/2;
        unsigned int right = maxlen - left;
        ret.push_back(string(left, ' ') + *it + string(right, ' '));
    }

    return ret;
}

void show(const vector<string>& v) {
    for (vector<string>::const_iterator it = v.begin();
         it != v.end();
         ++it) {
      cout << *it << endl;
    }
}

int main()
{
    vector<string> v;
    v.push_back(string("Bart"));
    v.push_back(string("Jan"));
    v.push_back(string("Marijke"));

    show(v);
    vector<string> c = center(v);
    show(c);
}
