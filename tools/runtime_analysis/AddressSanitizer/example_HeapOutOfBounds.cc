// RUN: g++ -O -g -fsanitize=address example_HeapOutOfBounds.cc

int main(int argc, char **argv) {
  int *array = new int[100];
  array[0] = 0;
  int res = array[argc + 100];  // BOOM
  delete [] array;
  return res;
}
