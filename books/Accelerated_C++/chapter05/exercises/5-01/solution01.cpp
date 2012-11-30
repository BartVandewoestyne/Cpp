/**
 * Exercise 5-1 from 'Accelerated C++', solution 1.
 *
 * References:
 *
 *   [1] Koenig, Andrew and Barbara Moo. "Analysis of a Classroom Exercise,
 *       Part 5: Working with Strings," Journal of Object-Oriented Programming,
 *       13(11): March 2001.
 *   [2] http://adtmag.com/Articles/2001/04/01/Rethinking-How-to-Teach-CPart-6-Analyzing-Strings.aspx
 *   [3] http://adtmag.com/Articles/2001/05/01/Rethinking-How-to-Teach-CPart-7-Payback-time.aspx
 *   [4] http://adtmag.com/Articles/2001/06/01/Rethinking-How-to-Teach-C-Part-8-An-interesting-revision.aspx
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> Phrase; // Typo was fixed here!

struct Rotated_phrase {
    Phrase words;
    Phrase::size_type bound;
};


bool compare(const Rotated_phrase& x, const Rotated_phrase& y)
{
    return x.words < y.words;
}


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


vector<string> split(const string& s) // Typo was fixed here!
{
    vector<string> ret; // Typo was fixed here!
    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters
    // [original value of i, i)
    while (i != s.size()) {

        // ignore leading blanks
        // invariant: characters in range
        // [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;

        // invariant: none of the characters in range
        // [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            ++j;

        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and
            // taking j-i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}


int main()
{
    vector<Rotated_phrase> phrases; // Typo was fixed here!

    string::size_type max_size = 0;
    string line;
    while (getline(cin, line)) {
        Rotated_phrase phrase;
        phrase.words = split(line);
        if (phrase.words.size()) {
            max_size = max( max_size,
                            phrase_length(phrase.words.begin(),
                                          phrase.words.begin()
                                            + phrase.words.size() - 1) );

            // Generate every possible rotation of phrase.words,
            // and associate each rotation with a different integer,
            // starting from 1
            // Each time through this loop, we first rotate
            // phrase.words one position to the right, and
            // then push it and its corresponding integer
            // onto the back of  phrases.
            for (phrase.bound = 1;
                 phrase.bound <= phrase.words.size();
                 ++phrase.bound) {

                 // remove the last word from phrase.words
                 string last_word = phrase.words.back();    
                 phrase.words.pop_back();

                 // insert the word at the beginning of phrase.words
                 phrase.words.insert(phrase.words.begin(), last_word);
                 phrases.push_back(phrase);
            }
        }
    }

    // Step 2: sort
    sort(phrases.begin(), phrases.end(), compare);

    // Step 3: write
    for (vector<Rotated_phrase>::const_iterator i = phrases.begin(); // Typo was fixed here!
         i != phrases.end();
         ++i) {

        Phrase::const_iterator bound = i->words.begin() + i->bound;

        cout << string(max_size - phrase_length(bound, i->words.end()), ' ');

        write_phrase(cout, bound, i->words.end());
        cout << " ";
        write_phrase(cout,i->words.begin(), bound);
        cout << endl;
    }

}
