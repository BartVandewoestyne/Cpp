#include <algorithm>
#include <iostream>
#include <list>
using std::list;
using std::find;

void print(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin();
         it != l.end();
         ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    list<int> list1;
    list<int> list2;

    // list2 must contain a 10 somewhere beyond a 5.
    for (int i = 1; i <= 10; i++)
    {
        list1.push_back(i);
        list2.push_back(i);
    }

    print(list1);
    print(list2);

    // move all nodes in list2 from the first occurrence of 5 through the last
    // occurrence of 10 to the end of list1.  See Item 28 for info on the
    // "base()" call.
    list1.splice(
        list1.end(), list2,
        find(list2.begin(),  list2.end(),   5),
        find(list2.rbegin(), list2.rend(), 10).base()
    );

    print(list1);
    print(list2);
}
