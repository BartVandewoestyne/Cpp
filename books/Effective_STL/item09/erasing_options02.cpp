#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>

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
        vector<int> c;
        c.push_back(1);
        c.push_back(1963);
        c.push_back(2);

        // This is the best way to get rid of objects where badValue returns
        // true when c is a vector, string, or deque.
        c.erase( remove_if(c.begin(), c.end(), badValue),
                 c.end() );

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

        // This is the best way to get rid of objects where badValue returns
        // true when c is a list.
        c.remove_if(badValue);

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

    {   // Associative containers: approach 2a: WRONG!

        set<int> c;

        c.insert(1);
        c.insert(1963);
        c.insert(2);

        // clear, straightforward, and BUGGY code to erase every element in c
        // where badValue returns true; don't do this!
        for (set<int>::iterator i = c.begin();
             i != c.end();
             ++i)
        {
            if (badValue(*i))
            {
                c.erase(i);
            }
        }

        for (set<int>::iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {   // Associative containers: approach 2b.

        set<int> c;

        c.insert(1);
        c.insert(1963);
        c.insert(2);

        // the 3rd pard of the for loop is empty; i is now incremented below
        for (set<int>::iterator i = c.begin();
             i != c.end();
             /* nothing */)
        {
            // for bad values, pass the current i to erase and increment i as a
            // side effect; for good values, just increment i
            if (badValue(*i))
            {
                c.erase(i++);
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
