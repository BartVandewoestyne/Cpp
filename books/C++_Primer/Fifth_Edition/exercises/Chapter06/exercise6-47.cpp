// Compile with debug info:
//
//   g++ -std=c++11 exercise6-47.cpp
//
// Compile without debug info:
//
//   g++ -D NDEBUG -std=c++11 exercise6-47.cpp

#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int> vec, int i)
{ 

#ifndef NDEBUG
    cout << "vec.size() = " << vec.size() << endl;
#endif

    // Returning when i is larger or equal to the size of the vector.
     if ( i >= vec.size() ) { 
          return;
     }
  
     // Printing the ith element of the vector.
     cout << vec[i] << endl;

     // Calling the function with a larger i.
     printVector(vec, i+1);
}

int main()
{
    vector<int> v = {1, 2, 3};

    printVector(v, 0);
}
