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

int main()
{
    {
        vector<int> c;
        c.push_back(1);
        c.push_back(1963);
        c.push_back(2);

        // The erase-remove idiom is the best way to get rid of elements with a
        // specific value when c is a vector, string or deque.
        c.erase( remove(c.begin(), c.end(), 1963),
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

        // The remove member function is the best way to get rid of elements
        // with a specific value when c is a list.
        c.remove(1963);

        for (list<int>::iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {
        set<int> c;
        c.insert(1);
        c.insert(1963);
        c.insert(2);

        // The erase member function is the best way to get rid of elements
        // with a specific value when c is a standard associative container.
        c.erase(1963);

        for (set<int>::iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}
