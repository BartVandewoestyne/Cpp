/**
 * References:
 *
 *   [1] http://j.mp/cpp11ref
 */

int main() {

    int i = 4;
    const int j = 6;
    const int& k = i;
    int a[5];
    int *p;

    // decltype is an operator for querying the type of an expression.
    // Similarly to the sizeof operator, the operand of decltype is unevaluated.
    decltype(i) var1;
    decltype(1) var2;
    decltype(2+3) var3;
    decltype(i=1) var4 = i; // There is no assignment i to 1
    // i == 4 as before
    decltype(j) var5 = 1;
    decltype(k) var6 = j;
    decltype(a) var7;
    decltype(a[3]) var8 = i;
    decltype(*p) var9 = i;

    return 0;
}
