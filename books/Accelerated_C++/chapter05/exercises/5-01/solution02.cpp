/**
 * Exercise 5-1 in Accelerated C++: solution 2.
 *
 * References:
 *   [1] http://adtmag.com/Articles/2001/06/01/Rethinking-How-to-Teach-C-Part-8-An-interesting-revision.aspx
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> Phrase;

struct Rotation {
    vector<Phrase>::const_iterator phrase;
    Phrase::const_iterator rhs;
};


// split a string into individual words
vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters
    // [original value of i,i)
    while (i != s.size()) {
        // ignore leading blanks invariant:
        // characters in range
        // [original i, current i) are all spaces
        while (i != s.size()
                && isspace(s[i]))
                     ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range
        // [original j, current j) is a space
        while (j != s.size()
                && !isspace(s[j]))
                     ++j;

        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at
            // i and taking j - i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}


// write the words in the range [begin, end)
// with a space between adjacent words
 void write_phrase(ostream& out,
                   Phrase::const_iterator begin,
                   Phrase::const_iterator end)
{
    if (begin != end) {
        out << *begin;
        while (++begin != end)
            out << " " << *begin;
    }
}


// determine how much space
// the words in the range [begin, end)
// would consume if written by write_phrase
string::size_type phrase_length(Phrase::const_iterator begin,
                                Phrase::const_iterator end)
{
    string::size_type sum = 0;
    if (begin != end) {
        sum = begin->size();
        while (++begin != end)
            sum += begin->size() + 1;
    }
    return sum;
}


bool compare(const Rotation& x, const Rotation& y)
{
    // if x's right-hand side is less than y's, the result is true
    if (lexicographical_compare
              (x.rhs, x.phrase->end(),
               y.rhs, y.phrase->end()))
         return true;

    // if y's right-hand side is less than x's, the result is false
    if (lexicographical_compare
              (y.rhs, y.phrase->end(),
               x.rhs, x.phrase->end()))
         return false;

    // otherwise, we determine the result by comparing
    // the left-hand sides in reverse order
    return lexicographical_compare(
        reverse_iterator<Phrase::const_iterator>
             (x.rhs), x.phrase->rbegin(),
        reverse_iterator<Phrase::const_iterator>
             (y.rhs), y.phrase->rbegin());
}


int main()
{
    // one element for each line of input
    vector<Phrase> lines;
    // one element for each rotation
    vector<Rotation> rotations;
    // the current input line
    string line;
    // the length of the longest left-hand side
    string::size_type max_size = 0;
    
    while (getline(cin, line)) {
         Phrase phrase = split(line);
         Phrase::const_iterator begin = phrase.begin();
         Phrase::const_iterator end = phrase.end();
         if (begin != end)
              max_size = max(max_size,
                   phrase_length(begin, --end));
         lines.push_back(phrase);
    }

    // examine each line in the input
    for (vector<Phrase>::const_iterator
         p = lines.begin();
         p != lines.end(); ++p)
    {
        Rotation e;
        e.phrase = p;
        // generate a rotation for each word in the phrase
        for (e.rhs = p->begin();
             e.rhs != p->end(); ++e.rhs)
             rotations.push_back(e);
    }

    stable_sort(rotations.begin(), rotations.end(), compare);

    for (vector<Rotation>::const_iterator i = rotations.begin();
         i != rotations.end();
         ++i)
    {
        // p refers to the input line that corresponds to the
        // current line of output, which we must
        // write with a gap immediately before the
        // element denoted by rhs
        vector<Phrase>::const_iterator p = i->phrase;
        // write an appropriate amount of padding
        cout << string(max_size - phrase_length(p->begin(), i->rhs), ' ');

        // write the part before the gap
        write_phrase(cout, p->begin(), i->rhs);

        // write the gap and the rest of the line
        cout << "   ";
        write_phrase(cout, i->rhs, p->end());
        cout << endl;
    }
}
