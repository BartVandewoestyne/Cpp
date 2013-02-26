#include <vector>
using std::vector;

int main()
{
    const int numValues = 5;

    int data[numValues];

    for (int i = 0; i < numValues; ++i)
    {
        data[i] = i;
    }

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    // Insert the ints in data into v at the front.
    v1.insert(v1.begin(), data, data+numValues);

    // Using iterative calls to insert in an explicit loop.
    vector<int>::iterator insertLoc(v2.begin());
    for (int i = 0; i < numValues; ++i)
    {
        insertLoc = v2.insert(insertLoc, data[i]);
        ++insertLoc;
    }

    // Replacing the loop with a call to copy.
    copy(data, data + numValues, inserter(v3, v3.begin()));
}
