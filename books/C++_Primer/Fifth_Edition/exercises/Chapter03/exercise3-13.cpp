#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;


template<typename T>
void print(const vector<T>& v)
{
    for (const auto& element : v)
    {
        cout << element << " ";
    }
    cout << " (size: " << v.size() << ")" << endl;
}


int main()
{
    // 0 elements.
    vector<int> v1;
    print(v1);

    // 10 elements with value 0.
    vector<int> v2(10);
    print(v2);

    // 10 elements with value 42.
    vector<int> v3(10, 42);
    print(v3);

    // 1 element with value 10.
    vector<int> v4{10};
    print(v4);

    // 2 elements: value 10 and 42.
    vector<int> v5{10, 42};
    print(v5);

    // 10 empty strings.
    vector<string> v6{10};
    print(v6);

    // 10 elements with value "hi".
    vector<string> v7{10, "hi"};
    print(v7);
}
