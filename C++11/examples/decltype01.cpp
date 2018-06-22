/**
 * References:
 *
 *   [mertz2017] Modern C++ Features - decltype and std::declval
 *               http://arne-mertz.de/2017/01/decltype-declval/
 *
 *   [gvas2013] What expressions yield a reference type when decltype is applied to them?
 *              https://stackoverflow.com/questions/17241614/what-expressions-yield-a-reference-type-when-decltype-is-applied-to-them
 *
 *   [becker2013] C++ auto and decltype Explained
 *                http://thbecker.net/articles/auto_and_decltype/section_01.html
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
