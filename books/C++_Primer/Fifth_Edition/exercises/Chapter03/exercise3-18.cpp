#include <vector>

using std::vector;

int main()
{
    // The code below is not legal because we may use the subscript operator
    // to fetch only elements that actually exist.  Since there are no
    // elements in the empty vector ivec, the element ivec[0] does not exist.
    //vector<int> ivec;
    //ivec[0] = 42;

    // Solution: create a vector with at least 1 element.
    vector<int> ivec(1, 0);
    ivec[0] = 42;
}
