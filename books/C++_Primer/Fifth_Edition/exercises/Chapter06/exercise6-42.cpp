// NOTE: the assignment seems incorrect to me.  I assume it should be the
// *third* parameter that needs a default argument 's'???

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word,
                               const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string word("cake");
    string plural = make_plural(2, word); 
    cout << plural << endl;
}
