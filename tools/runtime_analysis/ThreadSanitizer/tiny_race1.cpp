// Reference:
//   https://clang.llvm.org/docs/ThreadSanitizer.html
//
// Compile with:
//   clang -fsanitize=thread -g -O1 tiny_race.cpp

// TODO: why doesn't this work?

#include <pthread.h>

int Global;

void *Thread1(void *x) {
  Global = 42;
  return x;
}

int main() {
  pthread_t t;
  pthread_create(&t, NULL, Thread1, NULL);
  Global = 43;
  pthread_join(t, NULL);
  return Global;
}
