/**
 * Exercise 5-1.
 *   TODO: finish this!
 *
 * References:
 *   [1] http://adtmag.com/Articles/2001/05/01/Rethinking-How-to-Teach-CPart-7-Payback-time.aspx
 *   [2] http://adtmag.com/Articles/2001/06/01/Rethinking-How-to-Teach-C-Part-8-An-interesting-revision.aspx
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> ret;

    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {

        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            j++;

        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}

vector<vector<string> > generate_rotations(const vector<string>& v)
{
    vector<vector<string> > ret;

    vector<string>::size_type vec_size = v.size();
    vector<string>::size_type shift;

    for (shift = 0; shift < vec_size; ++shift)
    {
      vector<string> s;
      vector<string>::size_type k;
      for (k = 0; k < vec_size; ++k)
      {
        vector<string>::size_type idx;
        idx = (shift + k) % vec_size;
        s.push_back(v[idx]);
      }
      ret.push_back(s);
    }

    return ret;
}

vector<string>::size_type find_index(const string& s, vector<string>& v)
{
}

vector<vector<string> > unrotate(const vector<vector<string> >& rotations, const vector<string>& v)
{
    for (vector<vector<string> >::size_type i = 0; i < rotations.size(); ++i) {
      // Zoek index
    }
}


int main() {

    string s;

    // read and split each line of input
    while (getline(cin, s)) {

        cout << endl;

        vector<string> v = split(s);

        // Step 1: generate set of rotations.
        vector<vector<string> > rotations = generate_rotations(v);

        for (vector<vector<string> >::size_type i = 0; i < rotations.size(); ++i) {
          for (vector<string>::size_type j = 0; j < rotations[i].size(); ++j) {
            cout << rotations[i][j] << " ";
          }
          cout << endl;
        }
        cout << endl;

        // Step 2: sort the rotations.
        sort(rotations.begin(), rotations.end());

        for (vector<vector<string> >::size_type i = 0; i < rotations.size(); ++i) {
          for (vector<string>::size_type j = 0; j < rotations[i].size(); ++j) {
            cout << rotations[i][j] << " ";
          }
          cout << endl;
        }
        cout << endl;

        // Step 3: unrotate
        //   1. find the separator
        //   2. put the phrase back together
        //   3. write it properly formatted
        //vector<string> permuted_index = unrotate(rotations, v);

    }

    return 0;
}
