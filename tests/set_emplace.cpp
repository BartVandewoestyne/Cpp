/*
 * Reference:
 *
 *   [1] http://msdn.microsoft.com/en-us/library/dd998446.aspx
 */
#include <set>
#include <iostream>
#include <string>

int main( )
{
   using namespace std;
   set<string> s1;
   string str("a");

   s1.emplace(move(str));
   cout << "After the emplace insertion, s1 contains: "
      << *s1.begin() << endl;
}
