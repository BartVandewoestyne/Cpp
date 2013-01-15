/**
 * References:
 *
 *   [1] http://j.mp/cpp11ref
 */

#include <iostream>
using namespace std;

template<class T>
void print_list(T value)
{
    cout << value << endl;
}

template<class First, class ...Rest>
void print_list(First first, Rest ...rest)
{
    cout << first << ",";  print_list(rest...);
}

int main()
{
    print_list(42, "hello", 2.3, 'a');
}
