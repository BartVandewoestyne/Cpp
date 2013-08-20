// * s is a reference to const because its value cannot change.
//
// * occurs is a reference because its value can change.
//
// * s is a reference to avoid copying long strings.
//   occurs is a reference because it is an extra output parameter.
//   c is not a reference because it is a built-in type
//
// * If s is a plain reference, nothing happens because the code does not change
//   the value of s.  But is is more dangerous and adding const protects us more
//   against erroneous modifications of s.
//   If occurs is a reference to const, then the code doesn't compile anymore because
//   we change the value of occurs inside the function.

#include <string>
using namespace std;

// returns the index of the first occurence of c in s.
// the reference parameter occurs counts how often c occurs.
string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
    auto ret = s.size();    // position of the first occurence, if any
    occurs = 0;             // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;   // remember the first occurrence of c
            ++occurs;     // increment the occurrence count
        }
    }
    return ret;            // count is returned implicitly in occurs
}
