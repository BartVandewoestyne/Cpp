// Compile and run with:
//
// clang:
//   $ clang++ simple_race.cpp -fsanitize=thread -fPIE -pie -g
//   $ ./a.out
//
// gcc:
//   => currently gives linker error:
//        g++ simple_race.cpp -fsanitize=thread -g
//        /usr/bin/ld: cannot find libtsan_preinit.o: No such file or directory
//        collect2: error: ld returned 1 exit status
//   https://bugs.launchpad.net/ubuntu/+source/gcc-9/+bug/2029910
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
