// Method 1: compile and link in one go:
//
//   clang++ -O1 -g -fsanitize=address -fno-omit-frame-pointer example_UseAfterFree.cc
//
// Method 2: compile and link in two separate steps:
//
//   clang++ -O1 -g -fsanitize=address -fno-omit-frame-pointer -c example_UseAfterFree.cc
//   clang++ -g -fsanitize=address example_UseAfterFree.o

int main(int argc, char **argv)
{
  int* array = new int[100];
  delete [] array;
  return array[argc];  // BOOM
}
