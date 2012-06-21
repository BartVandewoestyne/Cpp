/**
 * (*2) Write these functions: strlen(), which returns the length of a
 * C-style string; strcpy(), which copies a C-style string into another;
 * and strcmp(), which compares two C-style strings.  Consider what the
 * argument types and return types ought to be.  Then compare your functions
 * with the standard library versions as declared in <cstring> (<string.h>)
 * and as specified in §20.4.1.
 *
 * Note:
 *   * Below is my solution.  Improvements are possible...
 */

#include <iostream>

using namespace std;


int strlen(char *s)
{
  int i = 0;
  while ( s[i] != '\0' )
  {
    i++;
  }
  return i;
}


void strcpy(char *s1, char *s2)
{
  int i = 0;
  while (s1[i] != '\0')
  {
    s2[i] = s1[i];
    i++;
  }
  s2[i+1] = '\0';
}


bool strcmp(char *s1, char *s2)
{
  bool equal = true;
  int i = 0;
  while (s1[i] != '\0')
  {
    if (s1[i] != s2[i])
    {
      equal = false;
      break;
    }
    i++;
  }
  return equal;
}


int main()
{
  cout << "Testing strlen:" << endl;
  char *s1 = "Bart";
  cout << s1 << " has length " << strlen(s1) << endl;

  cout << "Testing strcpy:" << endl;
  char *s2 = "Jan";
  char *s3;
  s3 = (char *)malloc(strlen(s2)+1);
  strcpy(s2, s3);
  cout << "s2 = " << s2 << endl;
  cout << "s3 (the copy) = " << s3 << endl;

  cout << "Testing strcmp:" << endl;
  char *s4 = "Piet";
  char *s5 = "Jan";
  if (strcmp(s2, s4)) {
    cout << s2 << " is equal to " << s4 << endl;
  } else {
    cout << s2 << " is not equal to " << s4 << endl;
  }
  if (strcmp(s4, s5)) {
    cout << s4 << " is equal to " << s5 << endl;
  } else {
    cout << s4 << " is not equal to " << s5 << endl;
  }
  if (strcmp(s2, s5)) {
    cout << s2 << " is equal to " << s5 << endl;
  } else {
    cout << s2 << " is not equal to " << s5 << endl;
  }
}
