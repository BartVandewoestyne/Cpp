/**
 * Erase-Remove idiom.
 *
 * http://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
 */

#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin();
         it != vec.end();
	 ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v;
    for (unsigned int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    print(v);

    v.erase( std::remove( v.begin(), v.end(), 5), v.end() );
    print(v);
}
