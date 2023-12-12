// Compile and run with:
//
//   $ clang++ simple_race.cpp -fsanitize=thread -fPIE -pie -g
//   $ ./a.out
//
// References:
//   https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual#Usage

#include <pthread.h>
#include <stdio.h>

int Global;

void *Thread1(void *x) {
  Global++;
  return NULL;
}

void *Thread2(void *x) {
  Global--;
  return NULL;
}

int main() {
  pthread_t t[2];
  pthread_create(&t[0], NULL, Thread1, NULL);
  pthread_create(&t[1], NULL, Thread2, NULL);
  pthread_join(t[0], NULL);
  pthread_join(t[1], NULL);
}
