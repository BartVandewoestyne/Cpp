#include <string>
using namespace std;

// a) FIXED by changing int return type to string.
string f() {
    string s;
    // ...
    return s;
}

// b) FIXED by adding void return type.
void f2(int i) { /* ... */ }

// c) FIXED by reneming second argument v1 to v2.
int calc(int v1, int v2) { /* ... */ }

// d) FIXED by adding braces to create a block.
double square(double x) { return x*x; }
