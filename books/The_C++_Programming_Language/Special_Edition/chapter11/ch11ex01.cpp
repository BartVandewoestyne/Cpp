/**
 * (*2) In the following program, which conversions are used in each
 *      expression?  Modify the program so that it will run and print the
 *      values of each legal expression.
 *
 * TODO: check this exercise and finish it.
 */

struct X {
  int i;
  X(int);
  X operator+(int);
};

struct Y {
  int i;
  Y(X);
  Y operator+(X);
  operator int();
};

extern X operator*(X, Y);
extern int f(X);

X x = 1;
Y y = x;
int i = 2;

int main()
{
  i + 10;
  x + y + i;
  f(y);      // error: could not convert ‘y’ from ‘Y’ to ‘X’

  y + 10;    // error: ambiguous overload for ‘operator+’ in ‘y + 10’
             // note: candidates are:
             // note: operator+(int, int) <built-in>
             // note: Y Y::operator+(X)
  x*x + i;
  y + y;

  y + 10*y;  // error: ambiguous overload for ‘operator*’ in ‘10 * y’
             // note: candidates are:
             // note: operator*(int, int) <built-in>
             // note: X operator*(X, Y)
  f(7);
  106 + y;
}
