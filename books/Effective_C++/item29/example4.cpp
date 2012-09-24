String someFamousAuthor()           // randomly chooses and
{                                   // returns an author's name
 
  switch (rand() % 3) {             // rand() is in <stdlib.h>
                                    // (and <cstdlib>  see
                                    // Item 49)
  case 0:
    return "Margaret Mitchell";     // Wrote "Gone with the
                                    // Wind," a true classic
  case 1:
    return "Stephen King";          // His stories have kept
                                    // millions from sleeping
                                    // at night
  case 2:
    return "Scott Meyers";          // Ahem, one of these
  }                                 // things is not like the
                                    // others...
 
  return "";                        // we can't get here, but
                                    // all paths in a value-
                                    // returning function must
}                                   // return a value, sigh

int main()
{
  const char *pc = someFamousAuthor();
  cout << pc;   // uh oh...
}
