// RUN: g++ -O -g -fsanitize=address example_HeapOutOfBounds.cc

int main(int argc, char **argv)
{
  int* array = new int[100];
  array[0] = 0;
  int res = array[argc + 100];  // BOOM
  delete [] array;

  // Note that if you comment out this line, then AddressSanitizer does not
  // detect the issue, because the compiler probably optimized the code away!
  // See also https://github.com/google/sanitizers/wiki/AddressSanitizer#faq:
  //   Q: Why didn't ASan report an obviously invalid memory access in my code?
  //   A1: If your errors is too obvious, compiler might have already optimized it out by the time Asan runs.
  return res;
}
