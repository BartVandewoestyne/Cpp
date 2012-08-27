/**
 * References:
 *
 *   [1] http://www.cpprocks.com/if-arr-not_eq-0-and-not-false-alternative-tokens-in-c/
 */
%:include <iostream>
 
using namespace std;
 
int main()
<%
        int arr<:2:> = <% 1, 1 %>;
 
        if (arr<:0:> not_eq 0 and not false)
                cout << "Hey, this works!" << endl;
        return 0;
%>
