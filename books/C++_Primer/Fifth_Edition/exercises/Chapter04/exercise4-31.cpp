/**
 * TODO: to me, it seems there's no difference if postfix operators are used???
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec = {1, 2, 3};

    vector<int>::size_type cnt = ivec.size();
    // assign values from size...1 to the elements in ivec
    for (vector<int>::size_type ix = 0;
         ix != ivec.size();
         ++ix, --cnt)
    {
        ivec[ix] = cnt;
    }

    for (const auto& e : ivec)
    {
        cout << e << " ";
    }
    cout << endl;
}
