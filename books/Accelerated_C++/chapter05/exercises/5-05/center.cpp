/**
 * TODO:
 *   - This assignment is somehow unclear to me.  Am I producing the requested
 *     output???
 *   - What are the properties of pictures for which such a function is useful?
 *   - How can you tell whether a given picture has those properties?
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string::size_type width(const vector<string>& picture)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != picture.size(); ++i)
        maxlen = max(maxlen, picture[i].size());
    return maxlen;
}

vector<string> center(const vector<string>& picture) {

    string::size_type maxlen = width(picture);

    vector<string> new_picture;
    for (vector<string>::const_iterator it = picture.begin();
         it != picture.end();
         ++it) {
        unsigned int left = (maxlen - it->size())/2;
        unsigned int right = maxlen - left;
        new_picture.push_back(string(left, ' ') + *it + string(right, ' '));
    }

    return new_picture;
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
    vector<string> picture;
    picture.push_back(string("Bart"));
    picture.push_back(string("Jan"));
    picture.push_back(string("Marijke"));

    vector<string> new_picture = center(picture);

    show(picture);
    std::cout << "**************" << std::endl;
    show(new_picture);
}
