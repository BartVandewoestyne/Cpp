void manip(int, int);
double dobj;

int main()
{
  // (a) Rank 3: char promotes to int
  manip('a', 'z');

  // (b) TODO: Rank 3 or 4?
  manip(55.4, dobj);
}
