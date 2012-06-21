/*
 * Find 5 different c++ constructs for which the meaning is undefined (§C.2).
 * -> A construct is deemed undefined by the standard if no reasonable behavior
 *    is required by an implementation.  Undefined behavior can lead, literally,
 *    to anything: a compile-time or run-time diagnostic, catastrophic failure,
 *    non-catastrophic glitches, or just what you intended.
 *
 * Find 5 different c++ constructs for which the meaning is
 * implementation-defined (§C.2).
 * -> Each implementation must provide a specific, well-defined behavior for a
 *    construct and that behavior must be documented.
 */

#include <iostream>

using namespace std;

int main()
{

/* Undefined stuff. */

// Example 1
const int size = 4*1024;
char page[size];
page[size+size] = 7;

// Example 2
int array[3] = {1, 2, 3};
int i = 2;
array[i++] = i;
for (int i=0; i<3; i++)
{
  cout << array[i] << endl;
}

// Example 3: access outside the bounds of an array.
int a[10];
int *p = &a[10]; // a[0]..a[9] OK, a+10 also, but not a[10].

// Example 4: use of a destroyed object.
int &r = *new int;
delete &r;
r = r + 1; // reference no longer valid.

// Example 5: order of evaluation of subexpression, See Stroustrup special
// edition page 122.


/* Implementation defined stuff. */

// Example 1: truncation if char has only 8 bits.
unsigned char c2 = 1256;
cout << "c2 = " << c2 << endl;

// Example 2: numeric_limits

// Example 3: the number of bits in a byte (CHAR_BIT).
cout << "CHAR_BIT = " << CHAR_BIT << endl;

// Example 4: the sign of the result of % on negative integers.
cout << "-1%2 = " << -1%2 << endl;

// Example 5: the size of all non-char data types (eg sizeof(int) is 1, 2, 4, 8
//            depending on your machine)
cout << "sizeof(int) = " << sizeof(int) << endl;

// Example 6: everything about bit-fields is implementation specific.

// Example 7: the effect of shift left/right on negative integers.
cout << "-1<<2 = " << (-1<<2) << endl;

}
