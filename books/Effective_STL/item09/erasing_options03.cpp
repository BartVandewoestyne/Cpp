// TODO: finish this.

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>

using std::ofstream;
using std::remove;
using std::vector;
using std::list;
using std::set;

// Returns whether x is "bad"
bool badValue(int x)
{
    if (x%2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    {
        ofstream logFile;

        vector<int> c;
        c.push_back(1);
        c.push_back(1963);
        c.push_back(2);

        for (vector<int>::iterator i = c.begin();
             i != c.end(); )
        {
            if (badValue(*i)) {
                logFile << "Erasing " << *i << '\n';
                i = c.erase(i);  // keep i valid by assigning erase's return value to it
            }
            else ++i;
        }

        for (vector<int>::iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {
        list<int> c;
        c.push_back(1);
        c.push_back(1963);
        c.push_back(2);

        // TODO: for list: both approaches should work

        for (list<int>::iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {   // Associative containers: approach 1.

        // c is now one of the standard associative containers.
        set<int> c;

        c.insert(1);
        c.insert(1963);
        c.insert(2);

        // temporary container to hold unremoved values.
        set<int> goodValues;

        // copy unremoved values from c to goodValues.
        remove_copy_if(c.begin(), c.end(),
                       inserter(goodValues,
                                goodValues.end()),
                       badValue);

        // swap the contents of c and goodValues.
        c.swap(goodValues);

        for (set<int>::iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {   // Associative containers.

        ofstream logFile;

        set<int> c;

        c.insert(1);
        c.insert(1963);
        c.insert(2);

        // loop conditions are the same as before
        for (set<int>::iterator i = c.begin();
             i != c.end();
             /* nothing */)
        {
            if (badValue(*i))
            {
                logFile << "Erasing " << *i << '\n';  // write log file
                c.erase(i++);                         // erase element
            }
            else
            {
                ++i;
            }
        }

        for (set<int>::iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}
