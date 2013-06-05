#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<class T>
void print_array(T a[])
{
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

string sa[10];  // default initialized to array of 10 empty strings
int ia[10];     // default initialized to array of 10 zero ints

int main() {

    string sa2[10];  // uninitialized (TODO: check?)
    int    ia2[10];  // uninitialized

    print_array(sa);
    print_array(sa2);
    print_array(ia);
    print_array(ia2);

}
