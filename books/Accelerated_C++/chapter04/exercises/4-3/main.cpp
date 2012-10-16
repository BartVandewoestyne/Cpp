/**
 * 4-3. What happens if we rewrite the previous program to allow values up to
 * but not including 1000 but neglect to change the arguments to setw? Rewrite
 * the program to be more robust in the face of changes that allow i to grow
 * without adjusting the setw arguments. 
 */

#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::setw;

int nb_digits(int n)
{
  int nb_digits = 0;
  while (n)
  {
    ++nb_digits;
    n /= 10;
  }
  return nb_digits;
}

int main()
{
   int mymax = 10000;

   int max_nb_digits = nb_digits(mymax);
   int max_nb_digits_for_square = nb_digits(mymax*mymax);

   for (int i = 1; i <= mymax; ++i)
   {
     cout << setw(max_nb_digits + 1) << i
          << setw(max_nb_digits_for_square + 1) << i*i << endl;
   }
}
