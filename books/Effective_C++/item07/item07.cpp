// TODO: finish this item!!!

#include <cstdlib>
#include <iostream>
#include <new>
using namespace std;

// function to call if operator new can't allocate enough memory
void noMoreMemory()
{
  cerr << "Unable to satisfy request for memory\n";
  abort();
}


int main()
{
  set_new_handler(noMoreMemory);
  int *pBigDataArray = new int[100000000];
}
