/*
 * This is a test to see how we can implement indexing vectors in C++.
 * See e.g. http://nl.mathworks.com/company/newsletters/articles/matrix-indexing-in-matlab.html
 */

#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& v)
{
    for (std::vector<int>::const_iterator it = v.begin();
         it != v.end();
         ++it)
    {
        std::cout << *it << std::endl;
    }	    
}

std::vector<int> get_subvector(const std::vector<int>& v, const std::vector<int>& idxs)
{
    std::vector<int> subvector; 
    for (std::vector<int>::const_iterator it = idxs.begin();
         it != idxs.end();
         ++it)
    {
	std::cout << "v[" << *it << "] = " << v[*it] << std::endl;
        subvector.push_back(v[*it]);
    }
    return subvector;
}

int main()
{
    std::vector<int> v;
    std::vector<int> idxs;
    std::vector<int> subvector;

    v.push_back(2);
    v.push_back(5);
    v.push_back(4);
    v.push_back(8);
    v.push_back(9);
    v.push_back(4);
    v.push_back(3);

    idxs.push_back(3);
    idxs.push_back(5);
    idxs.push_back(6);

    // Is there a more elegant way to do this?
    subvector = get_subvector(v, idxs);

    std::cout << "v:" << std::endl;
    print_vector(v);

    std::cout << "idxs:" << std::endl;
    print_vector(idxs);

    std::cout << "subvector:" << std::endl;
    print_vector(subvector);
}
