/*
 * References:
 *
 *   [1] http://yapb-soc.blogspot.de/2012/09/range-based-for-loop-on-int-range.html
 */

#include <stdio.h>
#include <vector>
#include <algorithm>

// Create an inclusive range [b,e].
std::vector<int> enumerate( int b, int e ) {

    // but store it in the range [b,e).
    std::vector<int> v( e-b + 1 );
    std::iota( v.begin(), v.end(), b ); // C++11
    return v;

}

int main() {

    for( int x : enumerate(1,10) )
    {
        printf( "%d ", x );
    }
    puts("");

}
