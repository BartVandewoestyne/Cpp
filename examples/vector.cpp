#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<double> myVector;

    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
 
    // disadvantage: we repeatedly call the size() member function!!!
    for (vector<double>::size_type i = 0; i < myVector.size(); i++)
    {
      cout << myVector[i] << endl;
    }

    for (vector<double>::iterator it = myVector.begin();
                                  it != myVector.end();
                                  ++it)
    {
        cout << *it << endl;
    }
 
    return 0;
}
