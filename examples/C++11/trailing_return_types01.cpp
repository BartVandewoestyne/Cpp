/**
 * Reference:
 *
 *   [1] https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/introduction_to_the_c_11_feature_trailing_return_types?lang=en
 *   [2] http://arne-mertz.de/2016/11/trailing-return-types-everywhere/
 */

#include <iostream>

using namespace std;
 

template<typename T1, typename T2>
auto sum(T1 & t1, T2 & t2) -> decltype(t1 + t2)
{
    return t1 + t2;
}

int main()
{
    auto i = 1;
    auto j = 1.3;
    auto k = sum(i,j);
    cout << k << endl;
}
